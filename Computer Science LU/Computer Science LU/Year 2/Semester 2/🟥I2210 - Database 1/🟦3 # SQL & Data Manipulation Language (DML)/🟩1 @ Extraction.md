*We shall use the following database in this note*
![[Pasted image 20220719192505.png | 750]]

# SQL Basic Structure
SQL is based on set and relational operations with certain modifications and enhancements.

A typical SQL query has the form:
$$  \huge \color{Red} select \space A_1,A_2,...,A_n$$
$$\huge \color{Green} \space from \space  r_1,r_2,...,r_n$$
$$\huge \color{blue} where \space P $$
where: 
- `A` is an attribute
- `r` is a relation/table 
- `P` is a predicate

This query is equivalent to $\large \color{pink} \Pi_{A,A,...,A}(\sigma_P(r_1 * r_2 * r_n))$
 The result of an SQL query is a relation. I.e., SQL statements can be nested.

## `select` Clause
It pretty much equivalent to the [[🟩2 @ Formal Languages#Project |projection]] operation.
*Example:*
![[Pasted image 20220719192808.png | 400]]


We can use the `asterik *` to denote **all attributes**.
To **eliminate duplications** us the keyword `distinct` *(This keyword is redundant if the attribute is the **table key**)*. The `all` is opposite of distinct.
*Example:*
```sql
select distinct bname from loan
```

The `select` clause allows arithmetic operations *($+ - \div \times$)* on constants or attributes of tuples.
```sql
select bname, loanid, amount*100 from loan
```

## `where` Clause
The `where` clause specifies conditions that tuples in the relations in the `from` clause **must satisfy.**
SQL allows logical connectives `and`, `or`, and `not`. Arithmetic expressions can be used in the comparison operators.
*the `between` operator is included for convenience*

**`Note:`** attributes used in a query (both `select` and `where` parts) must be defined in the relations in the from clause.

*Example:*
```sql
select loanid from loan where amount between 90000 and 100000
```

- Instead of putting too many `OR`s we can switch it with `in (x1, x2,...)`
![[Pasted image 20220919144044.png | 450]]

## `from` Clause
The `from` clause corresponds to the [[🟩2 @ Formal Languages#Cartesian Product |Cartesian product]]  operation of the relational algebra.
*Example:*
```sql
select * from borrower, loan
```

---
## Rename Operation
Renaming relations and attributes using the `as` clause:
**Syntax:**
```sql
old-name as new-name
```

## Tuple Variables / Alias
Tuple variables are defined in the `from` clause via the use of the `as` clause.
*Example: (its pretty much the same as rename)*
```sql
select distinct B1.bname
from branch as B1, branch as B2
where B1.assets > B2.assets and B2.city == "Brooklyn"
```

## String Operations
Character attributes can be compared to a pattern:
-  `%` matches any substring.
-  `_` matches any single character.

*Example:*
```sql
-- Find the name of all customers whose street includes the substring ‘Main’.
select name from customer where cstreet like "%Main%"
```

## Ordering the Display of Tuples
SQL must perform a sort to fulfill an `order by` request. *Since sorting a large number of tuples may be costly, it is desirable to sort only when necessary.*
`order by` **will list the result in alphabetical order**

*Example:*
```sql
select distinct cname
from borrower b, loan l
where  b.loanid = l.loanid and bname = “Perryridge”
order by cname
```

---

## Set Operations
We can use the `union` $\cup$, `intersect`$\cap$, and `except` $-$ operations in SQL. This operations **eliminate duplicates**, however we can add the keyword `all` after them to keep them included, however its different for each operations.
Suppose a tuple occurs m times in r and n times in s, then, it occurs:
- **m + n** times in r `union all` s
- **min(m,n)** times in r `intersect all` s
- **max(0,m-n)** times in r `except all` s

*Example:*
```sql
(select cname from depositor) union (select cname from borrower)
```

## Aggregate Functions - `Group by`
*(Same functions in [[🟩2 @ Formal Languages#Aggregation Functions|Formal Languages]])*

*Example:*
```sql
select a1,a2,…, an, agg-function(….)
from account
group by a1,a2,…, an
```
![[Pasted image 20220919150104.png | 300]]

Attributes in `select` clause outside of aggregate functions **must appear in `group by` list**

## Aggregate Functions - `Having`
the keyword `having` specifies a **predicate** on the aggregate function

We use it for example were we need first to get the aggregation result and compare it with something else.

*Example:*
```sql
-- Find the names of all branches where the average account balance is more than $1200
select bname, avg(balance)
from account
group by bname
having avg (balance) >1200
```
predicates in the `having` clause are **applied after** the formation of `groups`

## Aggregate Functions - `Group by` with `Join`
*(Same join operation in [[🟩2 @ Formal Languages#Natural Join|Formal Languages]])*
The important thing is that it must be applied **before** `Group by`
(Join can take tables)

--- 

## `null` Values
The result of any arithmetic expression involving null is null.

*Example:*
```sql
-- Find all loan numbers which appear in the loan relation with null values for amount
select loanid
from loan
where amount is null

-- Total loan amoutns
select sum(amount)
from loan
```

**All** aggregate operations *(except `count(*)`)* **ignore** tuples with `null` values on the aggregated attributes

## Nested Subqueries
Every SQL statement returns a relation/set in the result; So you can replace a value or set of values with a SQL statement (ie., a `subquery`)
Just note that the sub-query **returns the correct type in comparisons**.

*Example:*
```sql
select *
from loan
where amount > (select avg(amount) from loan)
```

## Set Membership
`F in r` equivalent to: there exists t belong to r such that t = F
`F` is typically an **attribute name (or a tuple of attributes)**  and the set of values is typically returned from a subquery
![[Pasted image 20220719221314.png | 150]]

*Example:*
```sql
--Find all customers who have both an account and a loan in the bank.
select distinct cname
from borrower
where cname in (select cname from depositor)
```

Same thing applies for **`not in`**

## `some` Clause
`F <comp> some r` *equivalent to:* there exists t such that t belong to r and F \<comparison\>  t 
where \<comparison\> can be: fuck you, you know them and im tired, they are the greater than and such. (Sorry lol)
![[Pasted image 20220719222821.png | 300]]

*Example:*
```sql
-- Find all branches that have greater assets than some branch located in Brooklyn.
select bname
from branch
where assets > some (select assets from branch where bcity = “Brooklyn”)
```

## `all` Clause
Same as the `some` clause but it the condition must be true for **all** the values in the relation
![[Pasted image 20220719223122.png | 125]]

---
## Test for Empty Relations
 `exists` returns the `true` if the argument subquery is **nonempty**. 
 `not exists` returns the `true` if the argument subquery is **empty**. 

## Test for Absence of Duplicate Tuples
 `unique` tests whether a subquery has any **duplicate tuples** in its result.

## Derived relations/tables
Best explained with an example
```sql
-- Find the average account balance of those branches where the average account balance is greater than $1200.
select bname , avg-balance
from (select bname , avg(balance) from account group by bname )
		as result(bname, avg-balance) -- <--- HERE
where avg-balance > 1200
```

## Views
 Provide a mechanism to hide certain data from the view of certain users. To create a view we use the command:
 $$\huge \color{pink} create \space  view \space v \space as \space <query \space expression>$$
Its just a variable, but everything applied in the other tables that are contained in the view are also applied to the view

*Example:*
```sql
-- A view consisting of branches and their customers
create view all-customer as
	(select bname , cname
	from depositor, account
	where depositor.accid = account.name-number)
	union (select bname , cname
		from borrower, loan
		where borrower.loanid = loan.loan-number)
```