# Write your MySQL query statement below
SELECT 
    visited_on,
    amount,
    ROUND(avg_amount,2) AS average_amount
FROM (
    SELECT 
        visited_on,
        SUM(amount) OVER(
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        AVG(amount) OVER(
            ORDER BY visited_on
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS avg_amount,
        ROW_NUMBER() OVER(
            ORDER BY visited_on
        ) AS rn
    FROM (
        SELECT 
            visited_on,
            SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) AS daily
) AS result
WHERE rn >= 7
GROUP BY visited_on



-- below is also the solution for this question with better approach 
# Write your MySQL query statement below
-- SELECT
--     visited_on,
--     (
--         SELECT SUM(amount)
--         FROM customer
--         WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
--     ) AS amount,
--     ROUND(
--         (
--             SELECT SUM(amount) / 7
--             FROM customer
--             WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
--         ),
--         2
--     ) AS average_amount
-- FROM customer c
-- WHERE visited_on >= (
--         SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
--         FROM customer
--     )
-- GROUP BY visited_on;