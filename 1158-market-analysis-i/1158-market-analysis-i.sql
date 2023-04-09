# Write your MySQL query statement below
select user_id as buyer_id,join_date,count(
    case 
    when UNIX_TIMESTAMP(order_date)>=UNIX_TIMESTAMP("2019-01-01") then order_id
 end) as orders_in_2019
from Users
left join Orders on(user_id=buyer_id)
group by user_id

