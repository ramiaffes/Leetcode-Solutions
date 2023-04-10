# Write your MySQL query statement below
select t1.name as name
from  Employee t1
inner join  Employee t2 on (t1.id=(t2.managerId))
group by t2.managerId
having(count(t1.id)>=5);
