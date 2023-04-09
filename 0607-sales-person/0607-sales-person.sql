# Write your MySQL query statement below
select name from SalesPerson
where (name not in (
select name from SalesPerson
inner join Orders
on (Orders.sales_id=SalesPerson.sales_id )
where(com_id in(select com_id 
               from Company
               where(name="RED")))))