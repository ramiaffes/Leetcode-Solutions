# Write your MySQL query statement below
select distinct(t1.num) as ConsecutiveNums
from  Logs t1
inner join  Logs t2 on (t1.id=(t2.id+1))
where(t1.num=t2.num)and(
    t2.id in(select t3.id
    from  Logs t3
inner join  Logs t4 on (t3.id=(t4.id+1))
    where(t3.num=t4.num)
    )
)