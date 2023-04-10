# Write your MySQL query statement below
select(DATE_FORMAT(trans_date, '%Y-%m'))as month,country,count(trans_date)as trans_count,count(case 
    when state='approved' then trans_date
                                                                                        
 end)as approved_count,sum(amount)as trans_total_amount ,sum(
 case 
    when state='approved' then amount
     else 0
 end)as approved_total_amount 
 from
 Transactions
 group by DATE_FORMAT(trans_date, '%Y-%m'),country;