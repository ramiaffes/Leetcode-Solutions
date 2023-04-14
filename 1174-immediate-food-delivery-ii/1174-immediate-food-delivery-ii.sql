# Write your MySQL query statement below
select round(sum(case when (t.order_date=t.customer_pref_delivery_date) then 1
          else 0
          end) /sum(1)*100,2) as immediate_percentage from Delivery t
join (select customer_id,min(order_date) as order_date from 
Delivery
group by customer_id)t1
on (t1.customer_id=t.customer_id)and(t.order_date=t1.order_date)