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
Many factors contribute to time cost:
- disk accesses,
- CPU,
- or even network communication

**These costs depend on n the size of the buffer in main memory.**

# Selection Operation $\color{lime} \sigma$
We have 2 types of search for selection:
- `Linear:` Scan each file block and test all records to see whether they satisfy the selection condition.
- `Binary:` Applicable if selection is an equality comparison on the attribute on which file is ordered.

We also have a searching algorithm using indices but we wont go into details for this one.

# Join Operation $\color{lime}\Join$
There are several different algorithms to implement joins:
- Nested-loop join
- Block nested-loop join
- Indexed nested-loop join
- Merge-join
- Hash-join

In the worst case, if there is enough memory only to hold one block of each relation, the estimated cost is _(im not exactly sure what is the block, but i dont have time and exams are near and its not that important)_
$$\large \color{pink} n_{r} * b_{l} + b_{r}$$
where: 
- nr is the number of records of the right side of the relation
- bl is the number of blocks of the left side of the relation
- br is the number of blocks of the right side of the relation

If the smaller relation fits entirely in memory, use that as the inner relation.
Reduces costs to `br + bs` disk accesses.

# Heuristics _(Query Tree)_
Take the following query tree for example:
![[Pasted image 20230306165008.png|400]]

Pushing down the selection down the tree will reduce the calculation cost for the join operation:
![[Pasted image 20230306165106.png|400]]

**The main takeaway:** 
Pushing down selection and display operations down the query tree will reduce the calculation time.
Selection has higher priority going down the tree than the display operation.