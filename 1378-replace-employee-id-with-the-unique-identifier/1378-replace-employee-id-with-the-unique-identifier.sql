# Write your MySQL query statement below
-- joins lagane padenge
select eu.unique_id , es.name
from employees es left join employeeuni eu on es.id = eu.id;