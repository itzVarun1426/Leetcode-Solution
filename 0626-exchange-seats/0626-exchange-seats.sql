-- # Write your MySQL query statement below
-- SELECT 
--     id,
--     CASE
--         WHEN id = (SELECT MAX(id) FROM Seat) AND id % 2 = 1
--         THEN student
--         WHEN id % 2 = 1 
--             THEN (
--                 SELECT student 
--                 FROM Seat 
--                 WHERE id = s.id+1
--             )
--         ELSE (
--             SELECT student 
--             FROM Seat 
--             WHERE id = s.id-1
--         )
--     END AS student
-- FROM Seat s 

-- above solution works its time heavy so below solution which is better in this way

SELECT
    id,
    CASE
        WHEN id % 2 = 1 AND id != MAX(id) OVER ()
            THEN LEAD(student) OVER (ORDER BY id)
        WHEN id % 2 = 0
            THEN LAG(student) OVER (ORDER BY id)
        ELSE student
    END AS student
FROM Seat
ORDER BY id;