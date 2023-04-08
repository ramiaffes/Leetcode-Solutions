# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
DELETE FROM Person
WHERE id NOT IN (
  SELECT * FROM (
    SELECT MIN(p1.id)
    FROM Person p1
    GROUP BY p1.email
  ) AS subquery
);