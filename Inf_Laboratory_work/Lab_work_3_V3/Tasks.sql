CREATE TABLE categories (
    id SERIAL PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL
);

CREATE TABLE dishes (
    id SERIAL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    category_id INTEGER NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (category_id) REFERENCES categories(id)
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    dish_id INTEGER NOT NULL,
    order_date DATE NOT NULL,
    quantity INTEGER NOT NULL,
    total_price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (dish_id) REFERENCES dishes(id)
);

INSERT INTO categories (category_name) VALUES
('Супы'),
('Основные блюда'),
('Закуски'),
('Десерты');

INSERT INTO dishes (name, category_id, price) VALUES
('Борщ', 1, 350.00),      
('Стейк из лосося', 2, 850.50), 
('Цезарь с курицей', 3, 420.00), 
('Тирамису', 4, 300.00);    

INSERT INTO orders (dish_id, order_date, quantity, total_price) VALUES
(1, '2024-05-20', 2, 700.00),
(2, '2024-05-20', 1, 850.50),
(4, '2024-05-20', 3, 900.00),
(1, '2024-05-21', 1, 350.00),
(3, '2024-05-21', 2, 840.00);



