# Write your MySQL query statement below
select  D2.name as Department,Employee.name as Employee,Employee.salary as Salary
from Department D2
inner join Employee on Employee.departmentId=D2.id
where(salary in
     (select max(salary)
     from Department D1
inner join Employee on Employee.departmentId=D1.id 
     where(D2.id=D1.id)
     group by D1.id
    ))
