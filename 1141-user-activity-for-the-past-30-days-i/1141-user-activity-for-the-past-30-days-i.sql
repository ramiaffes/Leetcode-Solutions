# Write your MySQL query statement below
select activity_date as day, count(distinct(user_id)) as active_users
from Activity
where((UNIX_TIMESTAMP(activity_date)<=UNIX_TIMESTAMP('2019-07-27'))and(UNIX_TIMESTAMP(activity_date)>=(UNIX_TIMESTAMP('2019-06-28'))))
group by activity_date;

