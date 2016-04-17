# Write your MySQL query statement below
select Email from Person group by Email having COUNT(Id) >= 2;