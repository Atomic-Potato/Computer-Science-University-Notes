*The database we will be working with in this note:*
![[Screenshot 2022-07-19 144731.png | 400]]

# Query Languages
**Language in which user requests information from the database.**
And it has 2 categories:
- `procedural` _(a.k.a. `Relational Algebra`)_
- `non-procedural`

## Procedural (a.k.a. Relational Algebra)
The basic operators: 

#### `Select`
**It displays the records that satisfy a condition (`p`).**

**Notation:** $\color{pink} \large \sigma_p (r)$ where `r` is the **table name** that we want to preform the operation `p` on
`p` syntax: ***attribute1* `OPERATOR` *attribute2***
Where the operator can be any of these $\large \color{pink} =, \neq, >, \ge, <, \leq$

*Example:*
$\large \sigma_{branch=cse}(student)$ will display all the students in the student table where they have the branch equals the cse

### `Project`
**It displays the specific column of a table.** *(It does not display duplicate tuples)*

**Notation:** $\color{pink} \large \Pi_{a1, a2...}(r)$  where `r` is  **table name** that we want to display attributes columns from.

### `Generalized Projection`
**Allows arithmetic functions to be used in the projection list.**

**Syntax:** $\color{pink} \large \Pi_{F1, F2...}(E)$ *where `E` and `Fx` can be an algebraic expression*

*Example:*
![[Pasted image 20220718193500.png | 400]]


### `Union`
**Union operation combines values in table1 and table2 by removing duplicate ones.** _(mostly used with the `Project` operator)_
(Both tables need to have the same number of attributes)
(The attribute domains must be compatible (e.g., 2nd column of r deals with the same type of values as does the 2nd column of s))

**Syntax:** $\large \color{pink} \Pi_a(T_1) \space \cup \space \Pi_a(T_2)$

_Example_
![[Pasted image 20220917160549.png | 300]]

### `Intersection`
**It displays the common values in table1 and table2.**
(Same rules as union)

**Syntax:** $\large \color{pink} \Pi_a(T_1) \space \cap \space \Pi_a(T_2)$

### `Set Difference`
**Returns the entries in Table1 that dont exist in Table2**

**Syntax:** $\large \color{pink} Table_1 - Table_2$

### `Cartesian Product`
**it combines table1 and table 2 without any condition** (Basically gives you every possible combo between the 2 tables)

**Syntax:** $\large \color{pink} Table_1\space  \times \space Table_2$ which is equal to $\large \color{pink} degree\_Table_1\space  + \space degree\_Table_2$ where degree is the total number of columns

*Example:*
![[Pasted image 20220918162948.png | 500]]

### `Rename`
**It allows us to rename tables or columns/attributes**

**Syntax:** $\large \color{pink} \rho_{newTable}(TableName)$ or for columns using the `project` operation $\large \color{pink} \rho_{newCol1, newCole2}(\Pi_{col1, col2}(TableName))$

**`NOTE: we can chain operations as we like just how we did above in the rename operation`** 

### `The dot operator`
You can access a column in a table without putting the table variable like so
$\large \color{pink} \Pi_{table.column}(....)$

### `Natural Join`
**Natural join can only be performed if there is a common attribute (column) between the relations. The name and type of the attribute must be same. Then it will return table merged with only a single instance of the same columns**

**Syntax:** $\large \color{pink} table_1 \Join table_2$

*Example:*
![[Pasted image 20220715211226.png | 300]]

**Alternative definition:**
![[Pasted image 20220719163210.png | 500]]

### `Outer Join`
An extension of the `join` operation that avoids loss of information.
Computes the join and then adds tuples form one relation that does not match tuples in the other relation to the result of the join.

In this operation we will use `null` values to signify that the value is unknown or does not exist.

- `Left Outer Join:`
In the left outer join, operation allows keeping all tuple in the left relation. However, if there is no matching tuple is found in right relation, then the attributes of right relation in the join result are filled with `null` values.
**Syntax:** ![[Pasted image 20220718195758.png | 50]]
- `Right Outer Join:`
In the right outer join, operation allows keeping all tuple in the **right** relation. However, if there is no matching tuple is found in the **left** relation, then the attributes of the left relation in the join result are filled with `null` values.
**Syntax:** ![[Pasted image 20220718195917.png | 50]]
- `Full Outer Join:`
In a full outer join, all tuples from both relations are included in the result, irrespective of the matching condition.
**Syntax:** ![[Pasted image 20220718200015.png | 50]]

### `Division`
Suited to queries that include the phrase “for all.”
**Table1 ÷ Table2 = tuples of Table1 associated with all tuples of Table2.**

**Syntax:** $\large \color{pink} table_1 \div table_2$

Extra:
Lets take the last example. It took the blue and the red because they have both **B1** and **A1**. and it did not take the green one because it has only **A1** and not **B1**

*Examples:*
![[Pasted image 20220715212819.png | 500]]
![[Pasted image 20220715213142.png | 450]]
![[Pasted image 20220725152022.png | 400]]

### `Assignment`
The assignment operation `(<-)` provides a convenient way to express complex queries by storing intermediate results into **temporary** variable.

*Example:*
![[Pasted image 20220715214213.png | 300]]

### `Aggregation Functions`
Aggregation function takes a collection of values and returns a single value as a result.
The functions that can be used are:
- avg
- min
- max
- sum
- count *(number of values)*

**Syntax:** $\large \color{pink} \small{G1, G2, G3} \huge g_{\large F1(A1), F2(A2), etc.}\large(E)$
Where:
- E is any relational-algebra expression
- G 1 , G 2 …, G n is a list of attributes on which to group (can be empty)
- Each F i is an aggregate function
- Each A i is an attribute name

*Example:*
![[Pasted image 20220918180330.png | 400]]

### Notes on `NULL` values
-  `Aggregate` functions simply **ignore** `null` values
-  For duplicate elimination and grouping, null is treated like any other value, and two nulls are assumed to be the same
-  **Comparisons** with null values return the special truth value `unknown`
	 Three-valued logic using the truth value `unknown`:
	 ![[Pasted image 20220718200347.png | 400]]
- Result of select `predicate` is treated as false if it evaluates to `unknown`

---
# Relational Model (Not required)
## Tuple Relational Calculus (TRC) / `non-procedural`
`TRC` is a **non-procedural** query language, where each query is of the form:
$$\huge \color{cyan} \{t | P(t)\}$$
 **It is the set of all `tuples t` such that `predicate P` is true for `t`.** 
 - `t[A]` denotes the value of tuple  `t` on attribute `A`.
 -  $\color{red} \large t \in r$  denotes that tuple `t` is in relation `r` / table `r`
 -  P is a formula similar to that of the [[🟩1 @ Predicate Logic |predicate calculus]] *(i think im linking to the right thing)* 

### Predicate Calculus Formula
A `predicate formula`  contains: 
- Set of **attributes** and **constants**
- Set of comparison operators *(i.e. $\large <, \le , =, \ne , >, \ge$)*
-  Set of connectives: ![[Pasted image 20220718212559.png | 100]]
-  Implication `=>`
- Set of quantifiers, `there exists` and `for all`

**`Note:`** its not favorable for `t` to have 2 variable types in `P(t)`, in other words, belong to 2 sets

### Safety of Expressions
To avoid writing tuples that can generate **infinite** relations *(e.g. $\large \{t \space | \space !t \in r\}$ )* , we restrict the set of allowable expressions to `safe expressions`.

An expression is **safe** if **every component of `t` appears in `one` of the relations, tuples, or constants that appear in `P`**

---

## Domain Relational Calculus (DRC) / `non-procedural`
 `DRC` is a nonprocedural query language equivalent in power to `TRC`,  with the form:
 $$\huge \color{cyan} \{<x_1,x_2,...,x_n> | \space P(x_1,x_2,...,x_n)\}$$
 $\color{red}\large x_1,x_2,...,x_n$  represent domain variables
`P` represents a formula similar to that of the [[🟩1 @ Predicate Logic |predicate calculus]]. 

*Example:*
![[Pasted image 20220719130517.png | 450]]

### Safety of Expressions
An expression is **safe** if:
- All values that appear in tuples of the expression are values from `dom(P)` *(that is, the values appear either in `P` or in a tuple of a relation mentioned in `P`).*
- For every **“there exists”** sub-formula of the form $\large \color{magenta} \exists x(P_1(x))$, the sub- formula is true if an only if $\large P_1(x)$ is true for all values `x` from $\large \color{red} dom(P_1)$.
- For every **“for all”** subformula of the form $\large \color{magenta} \forall x(P_1(x))$, the sub-formula is true if and only if $\large P_1(x)$ is true for all values `x` from $\large \color{red} dom(P_1)$. 

---

# Extra
## Formal modification of the database
### `Deletion`
The selected tuples are removed from the database. But it cannot delete values on only particular attributes

**Syntax:** $\large \color{pink} table \leftarrow table - E$ ,  where `E` is a relational algebra query.

*Example:*
![[Pasted image 20220719144014.png | 400]]

### `Insertion`
To insert data into a table, we either:
-  specify a tuple to be inserted
-  write a query whose result is a set of tuples to be inserted

**Syntax:** $\large \color{pink} table \leftarrow table \cup E$ ,  where `E` is a relational algebra query.

The insertion of a single tuple is expressed by letting `E` be a **constant relation containing one tuple**.
![[Pasted image 20220719150050.png | 450]]

### `Updating`
Change a value in a tuple without charging *all* values in the tuple

**Syntax:** $\large \color{pink} table \leftarrow  \Pi_{F1,F2,...}(table)$  Each `F`, is either the ith attribute of the table, if the ith attribute is not updated, or, if the attribute is to be updated.

`Fi` is an expression, involving only constants and the attributes of the table, which gives the new value for the attribute

*Example:*
![[Pasted image 20220719151339.png | 450]]

---

## Views
A database `view` is a subset of a database and is based on a **query** that runs on one or more database tables. Database views are saved in the database as named queries and can be used to save frequently used, complex queries.

`View` definition is not the same as creating a new `relation` by evaluating the query expression.
Rather, a view definition causes the saving of an expression to be substituted into **queries** using the view.

**Syntax:** $\large \color{pink} create \space view \space v  \space as \space <query \space expression>$
![[Pasted image 20220719153452.png | 450]]

Note that views can be created from other views, even if it was from itself  *(then it would be called a recursive view)*

- **`Updates` Through View:**
It's pretty much the same, we just use the view instead of the table
*Example:*
![[Pasted image 20220719153947.png | 450]]

---

**`Tip:`** Try writing the formula in a general way *(something like pseudo code but for predicate)* before writing it in one of the languages