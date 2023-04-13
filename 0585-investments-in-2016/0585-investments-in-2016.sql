# Write your MySQL query statement below
select round(sum(i1.tiv_2016),2)as tiv_2016
from Insurance i1
where((select count(i2.tiv_2015) from
           Insurance i2
           where i2.tiv_2015=i1.tiv_2015)>=2)and(
           (select count(*)
           from Insurance i3 
        where(i3.lat=i1.lat)and(i3.lon=i1.lon)
        group by i3.lat,i3.lon)=1)
          ;