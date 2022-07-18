# Query Languages
**Language in which user requests information from the database.**
And it has 2 categories:
- `procedural`
- `non-procedural`

## Procedural
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

**Syntax:** $\large \color{pink} \Pi_a(T_1) \space \cup \space \Pi_a(T_2)$

### `Intersection`
**It displays the common values in table1 and table2.**

**Syntax:** $\large \color{pink} \Pi_a(T_1) \space \cap \space \Pi_a(T_2)$

### `Set Difference`
**Returns the entries in Table1 that dont exist in Table2**

**Syntax:** $\large \color{pink} Table_1 - Table_2$

### `Cartesian Product`
**it combines table1 and table 2 without any condition**

**Syntax:** $\large \color{pink} Table_1\space  X \space Table_2$ which is equal to $\large \color{pink} degree\_Table_1\space  + \space degree\_Table_2$ where degree is the total number of columns

*Example:*
![[Pasted image 20220715182945.png | 500]]

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

*Examples:*
![[Pasted image 20220715212819.png | 500]]
![[Pasted image 20220715213142.png | 300]]

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
![[Pasted image 20220718194644.png | 300]]

### Notes on `NULL` values
-  `Aggregate` functions simply **ignore** `null` values
-  For duplicate elimination and grouping, null is treated like any other value, and two nulls are assumed to be the same
-  **Comparisons** with null values return the special truth value `unknown`
	 Three-valued logic using the truth value `unknown`:
	 ![[Pasted image 20220718200347.png | 400]]
- Result of select `predicate` is treated as false if it evaluates to `unknown`

---
# Relational Model
## Tuple Relational Calculus (TRC) / `non-procedural`
`TRC` is a **non-procedural** query language, where each query is of the form:
$$\huge \color{cyan} \{t | P(t)\}$$
 **It is the set of all `tuples t` such that `predicate P` is true for `t`.** 
 - `t[A]` denotes the value of tuple  `t` on attribute `A`.
 -  $\color{red} \large t \in r$  denotes that tuple `t` is in relation `r` / table `r`
 -  P is a formula similar to that of the [[1 @ Predicate Logic |predicate calculus]] *(i think im linking to the right thing)* 

### Predicate Calculus Formula
A `predicate formula`  contains: 
- Set of **attributes** and **constants**
- Set of comparison operators *(i.e. $\large <, \le , =, \ne , >, \ge$)*
-  Set of connectives: ![[Pasted image 20220718212559.png | 100]]
-  Implication `=>`
- Set of quantifiers, `there exists` and `for all`

**`Note:`** its not favorable for `t` to have 2 variable types in `P(t)`, in other words, belong to 2 sets