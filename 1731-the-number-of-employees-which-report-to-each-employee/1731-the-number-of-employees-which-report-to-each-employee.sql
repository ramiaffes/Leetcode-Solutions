# Write your MySQL query statement below
select s1.reports_to as employee_id,s2.name,count(*) as reports_count,round(avg(s1.age),0)as average_age
from employees s1
join employees s2 on(s2.employee_id=s1.reports_to)
group by s1.reports_to
order by s1.reports_to ;