# Write your MySQL query statement below
(select t1.id,t2.student
from  Seat t1
inner join  Seat t2 on (t1.id=(t2.id+1))
where(t1.id%2=0)
union
select t1.id,t2.student
from  Seat t1
inner join  Seat t2 on (t1.id=(t2.id-1))
where(t1.id%2=1)
union
select id,student
from Seat
where (
id not in(
select t1.id
from  Seat t1
inner join  Seat t2 on (t1.id=(t2.id-1))
where(t1.id%2=1)))and(id%2=1))
order by id;