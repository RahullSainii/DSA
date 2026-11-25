# Write your MySQL query statement below

SELECT
    visited_on,
    amount,
    ROUND(amount / 7, 2) AS average_amount
FROM (
    SELECT
        d.visited_on,
        (
            SELECT SUM(c.amount)
            FROM Customer c
            WHERE c.visited_on BETWEEN
                DATE_SUB(d.visited_on, INTERVAL 6 DAY)
                AND d.visited_on
        ) AS amount
    FROM (
        SELECT DISTINCT visited_on
        FROM Customer
    ) d
    WHERE d.visited_on >= (
        SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
        FROM Customer
    )
) AS daily_totals
ORDER BY visited_on;
