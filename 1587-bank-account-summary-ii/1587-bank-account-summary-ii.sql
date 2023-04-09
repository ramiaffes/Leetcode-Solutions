# Write your MySQL query statement below
select name ,sum(amount)as balance from Users
left join Transactions on(Users.account=Transactions.account)
group by Users.account
having(sum(amount)>10000)