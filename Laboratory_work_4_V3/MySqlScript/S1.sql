CREATE TABLE categories (
    id SERIAL PRIMARY KEY,
    category_name VARCHAR(255) NOT NULL
);

CREATE TABLE dishes (
    id SERIAL PRIMARY KEY,
    name VARCHAR(255) NOT NULL,
    category_id INTEGER REFERENCES categories(id),
    price DECIMAL(10, 2) NOT NULL
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    dish_id INTEGER REFERENCES dishes(id),
    order_date DATE NOT NULL,
    quantity INTEGER NOT NULL,
    total_price DECIMAL(10, 2) NOT NULL
);

CREATE INDEX idx_categories_name ON categories(category_name);
CREATE INDEX idx_orders_date ON orders(order_date);

-- Заполнение таблицы categories
INSERT INTO categories (category_name) VALUES 
('Salads'),
('Soups'),
('Main Courses'),
('Desserts'),
('Drinks'),
('Appetizers');

-- Заполнение таблицы dishes
INSERT INTO dishes (name, category_id, price) VALUES 
('Caesar Salad', 1, 350.00),
('Greek Salad', 1, 320.00),
('Borscht', 2, 280.00),
('Tom Yum Soup', 2, 420.00),
('Ribeye Steak', 3, 890.00),
('Grilled Salmon', 3, 750.00),
('Tiramisu', 4, 280.00),
('Cheesecake', 4, 320.00),
('Mojito', 5, 250.00),
('Cappuccino', 5, 180.00),
('Bruschetta', 6, 220.00),
('BBQ Wings', 6, 390.00);

-- Заполнение таблицы orders
INSERT INTO orders (dish_id, order_date, quantity, total_price) VALUES 
(1, '2024-01-15', 2, 700.00),
(5, '2024-01-15', 1, 890.00),
(7, '2024-01-16', 3, 840.00),
(2, '2024-01-17', 2, 640.00),
(6, '2024-01-18', 1, 750.00),
(9, '2024-01-18', 4, 1000.00),
(3, '2024-01-19', 2, 560.00),
(8, '2024-01-20', 1, 320.00),
(4, '2024-01-21', 1, 420.00),
(10, '2024-01-21', 2, 360.00),
(11, '2024-01-22', 3, 660.00),
(12, '2024-01-22', 2, 780.00);