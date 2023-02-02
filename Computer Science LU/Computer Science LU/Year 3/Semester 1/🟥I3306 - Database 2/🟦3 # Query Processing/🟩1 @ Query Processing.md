Here we will learn the importance of writing efficient queries.
To help in query optimization we must first translate SQL to Relational algebra.

A relational algebra expression may have many equivalent expressions
_For example:_
![[Pasted image 20230201230413.png]]
First one reduces the amount of columns first and then we process.
Second one reduces the amount of rows and then we process.
Now you can see depending on which _(rows or columns)_ is bigger, we can reduce the search time by choosing the correct query.

# Query Cost
Cost is generally measured as total elapsed time for answering query
Many factors contribute to time cost
- disk accesses,
- CPU,
- or even network communication