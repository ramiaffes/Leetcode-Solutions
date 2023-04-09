# Write your MySQL query statement below
select name,sum(
case
    when  Users.id not in(
    select user_id
    from Rides
    ) then 0
else distance 
end)as travelled_distance 
from
Users
left join Rides on(Users.id=user_id)
group by Users.id
order by travelled_distance desc,name asc;