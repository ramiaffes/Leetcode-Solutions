# Write your MySQL query statement below
(select employee_id,salary as bonus from Employees
where(employee_id%2=1)and(SUBSTRING(name,1,1)<>'M')
union
select employee_id,0 as bonus from Employees
where(employee_id%2=0)or(SUBSTRING(name,1,1)='M'))
order by employee_id ;