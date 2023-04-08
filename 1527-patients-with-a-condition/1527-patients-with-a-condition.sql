# Write your MySQL query statement below
SELECT *
FROM Patients
WHERE conditions LIKE ('% DIAB1%')
union
SELECT *
FROM Patients
WHERE conditions LIKE('DIAB1%');
