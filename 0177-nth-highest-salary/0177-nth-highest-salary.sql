CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE offset INT DEFAULT N - 1;
  RETURN (
      # Write your MySQL query statement below.
      (select salary  as NthHighestSalary
from Employee
where(salary not in(
    select * from(
    select distinct(salary) from Employee
    order by salary desc  LIMIT offset)
    table1 
))
order by salary desc limit 1)
UNION
select Null  as NthHighestSalary
from Employee
where (select count(distinct salary) from Employee) < N
  );
END