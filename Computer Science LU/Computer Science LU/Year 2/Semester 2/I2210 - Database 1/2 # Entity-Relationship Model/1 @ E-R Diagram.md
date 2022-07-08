# What is ER Modeling
`Entity Relationship Modeling (ER Modeling)`  is a graphical approach to database design. It uses Entity/Relationship to represent real world objects.

`An Entity Relationship (ER) Diagram` is a type of flowchart that illustrates how “entities” such as people, objects or concepts relate to each other within a system.
___
# Entity & attribute
A real world can be modeled as a collection of entities and relationship between entities.

 - An **`entity`** is an object that exists and is distinguishable from other objects.
*Example: specific customer, account, company, etc.*

- Entities have **`attributes`**
*Example: customer id, customer name, and addresses*

- **`Identifier`** - Identifies an entity instance, the value of the identifier attribute is unique for each entity instance
*Example: customer id, account-number, etc.*

___
## Attributes
- **`Domain`** – the set of permitted values for each attribute

- **Attribute categories:**
	- `Simple`
	- `Composite attributes`:  An attribute that can be further divided into more attributes
	  ![[Pasted image 20220519114946.png | 300]]
	- `Multi-Value Attribute`: an attribute that allow multiple values
		*Example: skills, phone numbers, etc.*
	- `Derived attributes`: attributes that can be calculated (derived) from other attributes
		*Example: age, total, interest, due date, etc.*

---

# Relationship
 Relationship describes how entities are related by:
 - `Degree of relationship` - How many entities are involved in a relationship?
 -  `Cardinality` - Entity instance’s participation count

**A `relationship set` of degree 2**
![[Pasted image 20220519115312.png | 400]]
*An attribute can also be property of a relationship set.*

Relationship sets that involve `two entity sets` are `binary` (or degree two).

---

## Mapping Cardinalities
For a binary relationship set the mapping cardinality must be one of the following types:
- `One to one`
- `One to many`
- `Many to one`
- `Many to many`

---

# E-R Diagrams
- `Rectangles` represent **entity** sets.
- `Diamonds` represent **relationship** sets.
- `Lines` link **attributes** to entity sets and entity sets to relationship sets.
- `Ellipses` represent **attributes**
	- `Double ellipses` represent **multivalued attributes**.
	- `Dashed ellipses` denote **derived attributes**.
- `Underline` indicates **primary key** attributes
![[Pasted image 20220519120438.png | 400]]

A precise cardinality **limits** can be associated with relationship types
![[Pasted image 20220522203336.png | 500]]
Each entity $\color{cyan} e_1 \in E_1$ must participate in relationship `set R` at least $\color{cyan} min_1$ and at most $\color{cyan} max_1$ times
![[Pasted image 20220519121520.png | 300]]

---

## Multiple Relationships
Multiple relationships can exists between entities, as long as they are **independent** or **different**
![[Pasted image 20220522203836.png | 300]]


---

# Keys
Each **entity** needs a `key` to access its "account". This key is `one or more attributes`, so we select multiple attributes as a candidates.  Although several candidate keys may exist, one of the candidate
keys is selected to be the  `primary key`.

---
# Ternary Relationship
Multiple entities having the same relation in between eachother.
So for example if $E_3$ is (0,1), then its (0,1) to both $E_1$ and $E_2$  and every other entity connected to this relation R
![[Pasted image 20220522204040.png | 400]]

---
# Binary Relationship
When we have a `ternary relationship`, we can simplify it by **adding** an entity instead of the relation. (We name the new relations something related to the new Entity or a mix of the old entity and the new entity)
![[Pasted image 20220522204343.png | 500]]

---

# Weak Entity Sets
`Weak entities` are the ones that depend on `stronger entities` to exist.

**Strong** entities have a `one to many` relationship, and **weak** entities have `one to one` relationship connected to the strong entity, thus if you remove the strong entity all the weak entities collapse.

We represent weak entities and relations with a double boundary.
![[Pasted image 20220522204821.png | 200]]
