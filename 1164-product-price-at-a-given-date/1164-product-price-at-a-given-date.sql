# Write your MySQL query statement below
select distinct(product_id ),LAST_VALUE(new_price)
OVER (
 
partition by product_id
    ORDER BY change_date 
       RANGE BETWEEN UNBOUNDED PRECEDING AND UNBOUNDED FOLLOWING

  )as price from Products 
  where(change_date<='2019-08-16')
 union
 select distinct(product_id ),10
 from Products
 where(product_id not in( select product_id
                         from Products 
                         where(change_date<='2019-08-16')
                        ))
  