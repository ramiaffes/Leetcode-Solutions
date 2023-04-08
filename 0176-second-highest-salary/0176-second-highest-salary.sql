# Write your MySQL query statement below
(select salary  as SecondHighestSalary
from Employee
where(salary not in(
    select * from(
    select salary from Employee
    order by salary desc limit 1)
    table1 
))
order by salary desc limit 1)
UNION
select Null  as SecondHighestSalary
from Employee
where(1 in (select (count(distinct (salary)))
            from Employee
           ))