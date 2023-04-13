# Write your MySQL query statement below
(select name as results from Users
join MovieRating on Users.user_id=MovieRating.user_id
group by Users.user_id
order by(count(movie_id)) desc,name  limit 1)
union(
select title as results from Movies
 join MovieRating on Movies.movie_id=MovieRating.movie_id
    where(created_at>='2020-02-01')and(created_at<='2020-02-29')
group by MovieRating.movie_id
order by(avg(rating)) desc,title limit 1)