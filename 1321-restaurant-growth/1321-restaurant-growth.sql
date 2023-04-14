# Write your MySQL query statement below
select t.visited_on,t.amount,t.average_amount


from (
    select t1.visited_on,SUM(t1.amount) OVER (  ORDER BY t1.visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW )as amount  , round(avg(t1.amount) OVER ( ORDER BY t1.visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),2)as average_amount,row_number() OVER (ORDER BY t1.visited_on) AS rn
    from (
    select sum(t2.amount)as amount,t2.customer_id,t2.name,t2.visited_on
    from customer  t2 group by
     t2.visited_on )t1
)t WHERE rn > 6;
