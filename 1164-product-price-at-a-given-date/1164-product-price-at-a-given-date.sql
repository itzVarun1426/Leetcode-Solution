# Write your MySQL query statement below
SELECT 
    p1.product_id,
    COALESCE(p2.new_price,10) AS price
FROM (SELECT DISTINCT product_id FROM Products) p1
LEFT JOIN (
    SELECT p.product_id, p.new_price
    FROM Products p
    JOIN (
        SELECT product_id , MAX(change_date) AS latest_change
        FROM Products
        WHERE change_date <= '2019-08-16'
        GROUP BY product_id
    ) x
    ON p.product_id = x.product_id
    AND p.change_date = x.latest_change
) p2
ON p1.product_id = p2.product_id