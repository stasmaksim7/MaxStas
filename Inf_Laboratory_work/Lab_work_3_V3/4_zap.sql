SELECT dishes.name AS блюдо, SUM(orders.quantity) AS всего_порций
FROM orders 
JOIN dishes ON orders.dish_id = dishes.id
GROUP BY dishes.id, dishes.name -- объединяем строки у которых однотипные значения
ORDER BY всего_порций DESC; -- DESC это типо по убыванию