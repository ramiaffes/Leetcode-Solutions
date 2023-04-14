# Write your MySQL query statement below
select d1.name as Department  ,e1.name as Employee ,e1.salary as Salary
from Employee e1
join Department d1 on(e1.departmentId=d1.id)
where(e1.salary in (select(t.var) from (select distinct(e2.salary) as var
 from  Employee e2
 join Department d2 on(e2.departmentId=d2.id)
 where(d2.name=d1.name)
order by var desc
 limit 3)t));