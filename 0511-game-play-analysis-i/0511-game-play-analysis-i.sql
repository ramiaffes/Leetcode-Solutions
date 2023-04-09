# Write your MySQL query statement below
select player_id,DATE(FROM_UNIXTIME(min(UNIX_TIMESTAMP(event_date)))) as first_login from Activity 
group by player_id;

