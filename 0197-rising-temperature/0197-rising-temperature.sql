# Write your MySQL query statement below
select W1.id from
Weather W1
inner join Weather W2 on(UNIX_TIMESTAMP(W1.recordDate) = (UNIX_TIMESTAMP(W2.recordDate)+86400))
where (W1.temperature>W2.temperature)