# Write your MySQL query statement below
select a.FirstName as FirstName, a.LastName as LastName, b.City as City, b.State as State
from Person a
left outer join Address b
on a.PersonId = b.PersonId
