# Write your MySQL query statement below
select q1.person_name from Queue q1
join(select q2.person_id,SUM(q2.weight) OVER (ORDER BY q2.turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW)as cumulsom
    from Queue q2)q3 on q3.person_id=q1.person_id
    where(cumulsom<=1000)
    order  by cumulsom desc limit 1
    



