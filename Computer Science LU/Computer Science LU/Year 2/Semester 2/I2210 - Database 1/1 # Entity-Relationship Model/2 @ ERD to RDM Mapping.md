- `Rule 1:` Each entity becomes a table
- `Rule 2:` Find the **one-to-many** relationships and put an arrow from the table of the **one** to the **many** table, and put the **primary key** of the parent as a **foreign** *(use `#` before the key to mark it as foreign)* key for the child. If the relation has any attributes it goes to the child.
	- Note that if theres multiple relations, you add the same parent key again as foreign key but you name it something like the relation name
- `Rule 3:` For **many-to-many** relationships, take the relation (diamond) and make it as a table, keep its attributes, and it takes as **foreign keys** the primary keys of the tables it connects. **These to foreign keys form the primary key** (use `underline` to mark a primary key), and now put arrows from this table to the tables it connects.
- `Rule 4:` If an entity is inheriting from another entity, this entity takes all the attributes its inheriting and the old one gets deleted

Note: Changing the foreign keys names is fine as long as you can tell the parent 

*Example*
- ERD
 ![[Pasted image 20220712160909.png | 400]]
 - P.D. Model
 ![[Pasted image 20220712160935.png | 400]]
- Data schema
![[Pasted image 20220712160950.png|200]]


# Bijective case
![[Pasted image 20220713165233.png | 400]]

- `Solution 1:`
![[Pasted image 20220713165303.png]]
- `Solution 2:`
![[Pasted image 20220713165352.png]]
Sometimes if the woman if more dominant (hot) we put only an arrow from woman to man

if we have:
![[Pasted image 20220713165538.png | 400]]
we put an arrow from man to woman

