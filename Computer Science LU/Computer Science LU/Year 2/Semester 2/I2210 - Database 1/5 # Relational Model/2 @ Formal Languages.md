# Query Languages
**Language in which user requests information from the database.**
And it has 2 categories:
- `procedural`
- `non-procedural`

## Procedural
It has 6 basic operators:
- `select`
- `project`
- `union`
- `set difference`
- `Cartesian product`
- `Rename`

#### Select
**It displays the records that satisfy a condition (`p`).**

**Notation:** $\color{pink} \large \sigma_p (r)$ where `r` is the **table name** that we want to preform the operation `p` on
`p` syntax: ***attribute1* `OPERATOR` *attribute2***
Where the operator can be any of these $\large \color{pink} =, \neq, >, \ge, <, \leq$

*Example:*
$\large \sigma_{branch=cse}(student)$ will display all the students in the student table where they have the branch equals the cse

### Project
**It displays the specific column of a table.** *(It does not display duplicate tuples)*

**Notation:** $\color{pink} \large \Pi_{a1, a2...}(r)$  where `r` is  **table name** that we want to display attributes columns from.

### Union
**Union operation combines values in table1 and table2 by removing duplicate ones.** _(mostly used with the `Project` operator)_

**Syntax:** $\large \color{pink} \Pi_a(T_1) \space \cup \space \Pi_a(T_2)$

### Set Difference
**Returns the entries in Table1 that dont exist in Table2**

**Syntax:** $\large \color{pink} Table_1 - Table_2$

### Cartesian Product
**it combines table1 and table 2 without any condition**

**Syntax:** $\large \color{pink} Table_1\space  X \space Table_2$ which is equal to $\large \color{pink} degree\_Table_1\space  + \space degree\_Table_2$ where degree is the total number of columns

*Example:*
![[Pasted image 20220715182945.png | 500]]

### Rename
**It allows us to rename tables or columns/attributes**

**Syntax:** $\large \color{pink} \rho_{newTable}(TableName)$ or for columns using the `project` operation $\large \color{pink} \rho_{newCol1, newCole2}(\Pi_{col1, col2}(TableName))$

**`NOTE: we can chain operations as we like just how we did above in the rename operation`** 