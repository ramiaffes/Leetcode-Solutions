# Write your MySQL query statement below
select x,y,z, (case 
when(x+y)<=z then "No"
when(x+z)<=y then "No"
when(z+y)<=x then "No"
else  "Yes"
end
)as triangle
from Triangle