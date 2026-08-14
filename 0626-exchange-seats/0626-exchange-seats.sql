# Write your MySQL query statement below
SELECT 
    id,
    CASE
        WHEN id = (SELECT MAX(id) FROM Seat) AND id % 2 = 1
        THEN student
        WHEN id % 2 = 1 
            THEN (
                SELECT student 
                FROM Seat 
                WHERE id = s.id+1
            )
        ELSE (
            SELECT student 
            FROM Seat 
            WHERE id = s.id-1
        )
    END AS student
FROM Seat s 
