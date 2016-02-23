# Write your MySQL query statement below

select b.Email
from (select a.Email, count(*) as cnt from Person a group by a.Email ) b
where cnt > 1;
