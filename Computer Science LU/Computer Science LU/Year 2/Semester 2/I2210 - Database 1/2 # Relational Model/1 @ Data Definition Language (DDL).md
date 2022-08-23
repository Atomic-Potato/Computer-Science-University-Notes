# Domain Types in SQL
```sql
char(n) --Fixed length character string, with user-specified length n.

varchar(n) /*Variable length character string, with user-specified maximum length n.*/

int integer /*(a finite subset of the integers that is machine-dependent).*/

smallint /*Small integer (a machine-dependent subset of the integer domain type).*/

Numeric(p,d) /*Fixed point number, with user-specified precision of p digits, with d digits to the right of decimal point.*/

real, double precision /*Floating point and double-precision floating point numbers, with machine-dependent precision.*/

float(n) /*Floating point number, with user-specified precision of at least n digits.*/

date /*Dates, containing a (4 digits) year, month and date.*/
	--Example
	date ‘2001-7-27’

time /*Time of day, in hours, minutes and seconds.*/
	--Ex
	time ’09:00:30’
```

**`NULL` values:**  are allowed in all the domain types. Declaring an attribute to be `not null` prohibits null values for that attribute, but it can be null in the beginning.

```sql
create domain --creates user-defined domain types
--Example:
	create domain person-name char(20) not null
```
A `domain` is essentially **a data type with optional constraints** (restrictions on the allowed set of values). ^domain
# Table construct creation
```sql
create table table_name(A1 D1 ,
						A2 D2 ,
						-- …,
						An Dn ,
						<integrity-constraint1>,
						-- …,
						<integrity-constraintk>
						)
-- Where each A is an attribute name and D is the domain of the attribute
```

## Integrity Constraints
```sql
primary key(A1 ,/*...*/, An) --ensures uniqueness of key values by definition
							 --and automatically ensures not null in SQL-92
check(P) --ensures predicate P is always true
foreign key(key_name) references parent_table_name (parent_table_referenced_primary_key)
```

*Example: declare branch-name as primary key for branch and ensure that the values of assets are non-negative.*
```sql
create table branch
(
	branch-name char(15) not null,
	branch-citychar(30),
	assets integer,
	primary key (branch-name),
	check (assets >=0) 
)
```

## Drop and Alter Table Constructs
```sql
drop table table_name
	--deletes the schema and the tuples of a relation
alter table table_name add A D
	--Adds a new attribute and domain with value NULL
alter table table_name drop A
	--Deletes this attribute from the table
```

# Database creation
```sql
CREATE DATABASE database_name
	ON (NAME = \UnivRegDB_dat,
		FILENAME = 'H:\... \...data\UnivRegDB.mdf')
	LOG ON(NAME = '\UnivRegDB_log',
		   FILENAME = 'H:\... \...\data\\UnivRegDB.ldf')
	GO
```

# EXAMPLE of a DDL script
`NOTE THAT THE ORDER OF TABLE DECLARATIONS MATTER`
![[Pasted image 20220715132832.png]]
![[Pasted image 20220715132847.png]]
![[Pasted image 20220715132908.png]]
![[Pasted image 20220715133236.png]]
![[Pasted image 20220715133256.png]]
![[Pasted image 20220715132856.png]]
![[Pasted image 20220715133405.png]]