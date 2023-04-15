# Write your MySQL query statement below
select t2.day as day,t2.var as "Cancellation Rate"
from(select t.request_at as day,round(sum(case when(t.status<>'completed') and(t.client_id in (select users_id
                                                              from Users
                                                              where banned='No'))and(t.driver_id  in (select users_id
                                                              from Users
                                                              where banned='No')) then 1
            else 0 end )/sum(case when(t.client_id in (select users_id
                                                              from Users
                                                              where banned='No'))and(t.driver_id  in (select users_id
                                                              from Users
                                                              where banned='No')) then 1
                             else 0 end ),2) as var
from Trips t
where(t.request_at<="2013-10-03")and(t.request_at>="2013-10-01")
group by t.request_at)t2
where(t2.var is not null)
