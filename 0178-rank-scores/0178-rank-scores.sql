# Write your MySQL query statement below
select s.score,s3.rank
from  Scores s
join(select score,RANK() OVER (ORDER BY score DESC) as 'rank'
from (select distinct(score) from Scores)s1)s3 on
s3.score=s.score
order by s.score desc;


