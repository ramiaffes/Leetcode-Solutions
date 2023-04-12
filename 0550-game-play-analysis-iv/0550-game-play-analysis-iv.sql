# Write your MySQL query statement below
select (round(count(distinct(s1.player_id))/(select(count(distinct(player_id)))from
       Activity
),2))
as fraction
from Activity s1
join Activity s2 on(s1.player_id =s2.player_id)
where(DATEDIFF(s1.event_date,s2.event_date)=-1)and(s1.event_date in 
                                                 (select min(s10.event_date)
                                                 from activity s10
                                                 where(s10.player_id=s1.player_id)
                                                  group by s10.player_id))