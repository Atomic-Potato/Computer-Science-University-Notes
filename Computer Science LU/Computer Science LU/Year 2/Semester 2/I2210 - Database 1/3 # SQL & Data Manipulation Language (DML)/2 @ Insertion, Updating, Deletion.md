# Deletion
Conceptually, delete is done in two steps:
- Find the tuples you want to delete
- **_devour them_** using the keyword `delete`

*Example:*
```sql
select *
from account
where bname = "Perryridge"
```

**`NOTE:`** if you're using aggregate functions, make sure to store the returned value of the function in a variable, otherwise it will keep updating as we delete *(unless thats what you want of course)*

# Insertion
The `insertion` command comes generally in the form
$$\huge \color{pink} insert \space into \space table \space values \space (NewTuple)$$
- adding a **new tuple** to a relation/table
	```sql
	insert into account values (“Perryridge”, A-9732, 1200)
	```
- To **reorder attributes**, specify attribute names explicitly:
	```sql
	insert into account (bname , balance, accid)
	values (“Perryridge”, 1200, A-9732)
	```

(You can set the values to `null`)

# Updation ( jk: Updating )
The `updating` command comes generally in the form:
$$\huge \color{pink} update \space TABLE \space set \space Attribute = NewValue$$
*Example:*
```sql
--Increase all accounts with balance over $10,000 by 6%, all other accounts receive 5%.
update account
	set balance = balance * 1.06
	where balance > 10000
update account
	set balance = balance *1.05
	where balance <= 10000
```

**`NOTE:`** note how the order of the expressions matter, because if it was in reverse some accounts balance would go over 1000, and so they will increase again in the second expression.

# More on Views
(I STILL DONT GET THE DIFFERENCE FROM VARIABLES AAAAAAAAAH !) anyways

Best shown on an example:
```sql
--Create a view of all loan data in the loan relation, hiding the amount attribute
create view branch-loan as
	select bname , loan-number
	from loan

-- Add a new tuple to branch-loan
insert into branch-loan values(“Perryridge”, “L-307”)
```
