-- 1. Создание таблиц
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(10) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    subject_id INTEGER REFERENCES subjects(subject_id),
    grade INTEGER CHECK (grade BETWEEN 1 AND 5),
    CONSTRAINT unique_student_subject UNIQUE (student_id, subject_id)
);

CREATE TABLE attendance (
    attendance_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    date_attended DATE NOT NULL,
    status VARCHAR(20) CHECK (status IN ('present', 'absent', 'late')),
    CONSTRAINT unique_student_date UNIQUE (student_id, date_attended)
);

CREATE TABLE notes (
    note_id SERIAL PRIMARY KEY,
    student_id INTEGER REFERENCES students(student_id),
    note_text TEXT NOT NULL
);

-- 2. Наполнение данных
INSERT INTO students (full_name, group_number) VALUES
('Иванов Иван Иванович', 'ГР-01'),
('Петров Петр Петрович', 'ГР-01'),
('Сидоров Алексей Владимирович', 'ГР-01'),
('Кузнецова Мария Сергеевна', 'ГР-01'),
('Смирнов Дмитрий Алексеевич', 'ГР-01'),
('Васильева Анна Петровна', 'ГР-01');

INSERT INTO subjects (subject_name) VALUES
('Математический анализ'),
('Аналитическая геометрия'),
('Информатика');

INSERT INTO grades (student_id, subject_id, grade)
SELECT s.student_id, sub.subject_id, 
       CASE 
           WHEN s.student_id % 3 = 0 THEN 5
           WHEN s.student_id % 3 = 1 THEN 4
           ELSE 3
       END
FROM students s
CROSS JOIN subjects sub;

INSERT INTO attendance (student_id, date_attended, status)
SELECT s.student_id, '2024-01-15'::DATE,
       CASE 
           WHEN s.student_id % 4 = 0 THEN 'absent'
           WHEN s.student_id % 4 = 1 THEN 'present'
           ELSE 'late'
       END
FROM students s
UNION ALL
SELECT s.student_id, '2024-01-16'::DATE,
       CASE 
           WHEN s.student_id % 5 = 0 THEN 'absent'
           WHEN s.student_id % 5 = 1 THEN 'present'
           ELSE 'late'
       END
FROM students s;

INSERT INTO notes (student_id, note_text) VALUES
(1, 'Любит информатику, хорошо работает в команде'),
(2, 'Нужна помощь по информатике, редко посещает занятия'),
(3, 'Отличник по всем предметам, прогресс по информатике'),
(4, 'Хорошо работает в команде, любит математический анализ'),
(5, 'Редко посещает занятия по информатике, нужна помощь'),
(6, 'Прогресс по информатике, отличник по геометрии');

-- 3. Индексы
CREATE INDEX idx_students_group ON students(group_number);

CREATE INDEX idx_grades_student ON grades(student_id);

CREATE INDEX idx_notes_search ON notes USING gin(to_tsvector('russian', note_text));

-- 4. Представления
CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number;

-- 5. Транзакция - добавление нового студента вместе с его оценками
BEGIN;
    INSERT INTO students (full_name, group_number) 
    VALUES ('Новиков Сергей Викторович', 'ГР-01')
    RETURNING student_id;
    
    INSERT INTO grades (student_id, subject_id, grade)
    VALUES 
    (currval('students_student_id_seq'), 1, 4),
    (currval('students_student_id_seq'), 2, 5),
    (currval('students_student_id_seq'), 3, 4);
COMMIT;

-- 6. Запросы
WITH student_ordered AS (
    SELECT student_id, full_name,
           ROW_NUMBER() OVER (ORDER BY student_id) as row_num
    FROM students 
    WHERE group_number = 'ГР-01'
),
target_student AS (
    SELECT row_num FROM student_ordered WHERE student_id = 3
)
SELECT student_id, full_name
FROM student_ordered
WHERE row_num BETWEEN 
    (SELECT row_num FROM target_student) - 2 AND 
    (SELECT row_num FROM target_student) + 3
ORDER BY row_num
LIMIT 5;

SELECT * FROM student_avg_grades WHERE student_id = 1;

SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as avg_grade,
    COUNT(g.grade) as total_grades
FROM subjects s
JOIN grades g ON s.subject_id = g.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_name;

SELECT 
    n.note_id,
    s.full_name,
    n.note_text
FROM notes n
JOIN students s ON n.student_id = s.student_id
WHERE to_tsvector('russian', n.note_text) @@ to_tsquery('russian', 'Информатика');

BEGIN;
    SELECT * FROM attendance 
    WHERE student_id = 1 AND date_attended = '2024-01-15';
    

    UPDATE attendance 
    SET status = 'present'
    WHERE student_id = 1 AND date_attended = '2024-01-15';

    INSERT INTO attendance (student_id, date_attended, status)
    SELECT 1, '2024-01-15', 'present'
    WHERE NOT EXISTS (
        SELECT 1 FROM attendance 
        WHERE student_id = 1 AND date_attended = '2024-01-15'
    );
COMMIT;