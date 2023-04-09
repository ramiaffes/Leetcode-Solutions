# Write your MySQL query statement below
select id,"Leaf" as Type from Tree 
where(
id not in(
select T1.id
from Tree T1
inner join Tree T2
on(T2.p_id=T1.id))and(p_id is not null))
union
select id,"Root" as Type from Tree 
where(p_id is NUll)
union
select id,"Inner" as Type from Tree
where (p_id is not null)and(
id in(
select T1.id
from Tree T1
inner join Tree T2
on(T2.p_id=T1.id)))
