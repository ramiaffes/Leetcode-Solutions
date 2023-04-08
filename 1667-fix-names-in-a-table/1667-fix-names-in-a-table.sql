# Write your MySQL query statement below
select user_id,concat(upper(SUBSTRING(name,1,1)),lower(SUBSTRING(name,2,LENGTH(name)-1))) as name
from  Users 
order by user_id;