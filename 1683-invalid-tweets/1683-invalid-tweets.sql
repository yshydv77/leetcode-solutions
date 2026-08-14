# Write your MySQL query statement below
-- desc Tweets;
-- select tweet_id
-- from Tweets
-- where 

select tweet_id 
from Tweets
where Length(content) > 15;