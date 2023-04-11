# Write your MySQL query statement below
select s10.id,s10.visit_date,s10.people from
(select s1.id,s1.visit_date,s1.people
from  Stadium s1
join (select s3.id,s3.visit_date,s3.people
from  Stadium s3
join Stadium s4 on s3.id=s4.id+1
where s4.people>=100) s2 on s1.id=s2.id+1
where s2.people>=100 and s1.people>=100
union
select s1.id,s1.visit_date,s1.people
from  Stadium s1
join (select s3.id,s3.visit_date,s3.people
from  Stadium s3
join Stadium s4 on s3.id=s4.id-1
where s4.people>=100) s2 on s1.id=s2.id-1
where s2.people>=100 and s1.people>=100
union
select s1.id,s1.visit_date,s1.people
from  Stadium s1
join (select s3.id,s3.visit_date,s3.people
from  Stadium s3
join Stadium s4 on s3.id=s4.id-2
where s4.people>=100) s2 on s1.id=s2.id+1
where s2.people>=100 and s1.people>=100)s10
order by s10.id,s10.visit_date

