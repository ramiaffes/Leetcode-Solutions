# Write your MySQL query statement below
select sell_date,count( Distinct product) as num_sold,GROUP_CONCAT(Distinct product)as products
from (
    select * from Activities 
    order by product
)Activitiesordered
group by sell_date
order by sell_date;