# Write your MySQL query statement below
select Signups.user_id, round(ifnull(sum(case WHEN action='confirmed' THEN 1
                     else 0 end
                     )/ifnull(count(*),1),0),2)as confirmation_rate 
from Signups
left join Confirmations on Signups.user_id=Confirmations.user_id
group by Signups.user_id;