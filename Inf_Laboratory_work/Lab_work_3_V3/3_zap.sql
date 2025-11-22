SELECT SUM(total_price) AS total_income -- Вот эта фигня AS по факту задает имя нашему ответу
FROM orders
WHERE order_date = '2024-05-20';