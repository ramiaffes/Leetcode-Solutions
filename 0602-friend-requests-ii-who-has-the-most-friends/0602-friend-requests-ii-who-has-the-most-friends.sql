# Write your MySQL query statement below
select  m2.requester_id as id, (COUNT(*) + 
(SELECT COUNT(m1.accepter_id) FROM RequestAccepted m1 WHERE m2.requester_id=m1.accepter_id))as num
from RequestAccepted m2
group by  requester_id
order by (COUNT(*) + 
(SELECT COUNT(m1.accepter_id) FROM RequestAccepted m1 WHERE m2.requester_id=m1.accepter_id)) desc limit 1;