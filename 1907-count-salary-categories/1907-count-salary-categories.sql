# Write your MySQL query statement below
SELECT categories.category , COALESCE(counts.accounts_count , 0) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category 
    UNION ALL 
    SELECT 'Average Salary' 
    UNION ALL 
    SELECT 'High Salary'
) categories
LEFT JOIN (
    #below table is used to have the count of each categorical income so that it can be joint to the categoies table to get the categoies those having 0 count and doesnt exist in below table
    SELECT category , COUNT(income) AS accounts_count
    FROM (
        #to create a table with new column category and classifying each income into those categories but creating new table is done in select statement so group by cant be done in same query so ues it as subquery
        SELECT 
        *,
        CASE 
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income >= 20000 AND income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category
        FROM Accounts
    ) temp
    GROUP BY category
) counts
ON categories.category = counts.category;
