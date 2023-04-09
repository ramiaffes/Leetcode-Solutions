# Write your MySQL query statement below
(select employee_id from Employees
where(employee_id not in(
select Employees.employee_id from
    Employees 
    inner join Salaries 
    on  Employees.employee_id=Salaries.employee_id
))
union(
    select employee_id from Salaries
where(employee_id not in(
select Salaries.employee_id from
    Salaries
    inner join Employees
    on  Employees.employee_id=Salaries.employee_id
))
))order by employee_id;