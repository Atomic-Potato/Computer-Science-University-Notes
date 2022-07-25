# Division
The alternative definition of division:
$$\large \color{pink} r \div s = \Pi_{R-S} - \Pi_{R-S}((\Pi_{R-S}(r)\times s) - \Pi_{R-S,S}(r))$$
Say that: R(A,B,C,D) and S(C,D). Then the division in SQL can be done as follows
**Steps:**
-  Find out all possible combinations of S(y) with R(x) by computing R(x) x(cross join) S(y), say r1
- Subtract actual R(x,y) from r1, say r2 
- x in r2 are those that are not associated with every value in S(y); therefore R(x)-r2(x) gives us x that are associated with all values in S
```sql
create view v as
	select A,B,S.C,S.D
	from R,S            -- Equivalent to RxS
	except              -- Equivalent to -
		select A,B,C,D from R

--Then we get the division
select A,B from R except select A,B from v
```

Doing the same thing with `not exists` instead of `except`
R(A,B)
S(B)
```sql
create view v as
	select A, S.B
	from R as R1, S
	where not exists(select A,B from R where A=R1.A and B=S.B)

select distinct A from R 
	where not exists(select * from v where R.A=v.A)
```
# Join Relations
- `Join conditio:`
	Defines which tuples in the two relations match, and what attributes are present in the result of the join.
	Join Conditions: 
	```sql
	natural
	on<predicate>
	using(A1,A2,...)
	```
- `Join type:`
	Defines how tuples in each relation that do not match any tuple in the other relation (based on the join condition) are treated.
	Join Types:
	```sql
	inner join
	left outer join
	right outer join
	full outer join
	```
	*Example:*
	![[Pasted image 20220725223644.png]]
	![[Pasted image 20220725223751.png]]
	In SQL: (same order)
	```sql
	SELECT *
	FROM loan l INNER JOIN borrower b
		ON l.loan-number = b.loan-number
		
	SELECT *
	FROM loan l LEFT JOIN borrower b
		ON l.loan-number = b.loan-number
	
	SELECT *
	FROM loan l RIGHT JOIN borrower b
		ON l.loan-number = b.loan-number
	
	SELECT *
	FROM loan l FULL JOIN borrower b
		ON l.loan-number = b.loan-number
	```

**`ON`** Operator: used to join columns that have different names.

# Transactions
A `transaction` is a sequence of **queries and update statements** executed as a single unit
Transactions are started implicitly and terminated by one of:
- `commit work`: makes all updates of the transaction permanent in the database
- `rollback work`: undoes all updates performed by the transaction

In most database systems, each SQL statement that executes successfully is automatically committed. Each transaction would then consist of only a single statement. 
Automatic commit can usually be turned off, allowing multi- statement transactions, but how to do so depends on the database system