# What is Indexing
Indexing mechanisms used to speed up access to desired data.

An  index file consists of records _(called index entries)_ of the following form:
![[Pasted image 20230201213746.png|300]]

_For example:_
![[Pasted image 20230201213806.png|200]]

# Types of Indices 
There are 2 types of indices:
- `Primary index`: Its the index that specifies the sequential order of the file.
 _(Also called  clustering index)_  usually but not necessarily its the **primary key** of a table.
- `Secondary index:`  specifies an order different from the sequential order of the file. 
 _(Also called non-clustering index)_ usually but not necessarily its the **foreign key** of a table.

## Multilevel Index
If primary index  does not fit in memory , access becomes expensive.

So to reduce number of  disk accesses to index records, treat primary index kept on disk as a sequential file and construct a sparse index on it:
- `outer index` : a sparse index of primary index
- `inner index` : the primary index file
![[Pasted image 20230201220102.png|700]]

If even  outer index is too large to fit in main memory , yet another level of index can be created, and so on.

**_Note:_**  Indices at all levels must be updated on insertion or deletion from the file.


# Indexing Files Types
- `Dense index` : Index record appears for every search-key value in the file.
	![[Pasted image 20230201214542.png|600]]
- `Sparse Index` : contains index records for only some search-key values. 
	![[Pasted image 20230201214709.png|600]]

# Blocks overflow
Say we have 2 sequential blocks, **Block-1** for names that start with A and **Block-2** with names that start with B.
The A block is full and we need to a new entry, and we cant add it to the B block, this means we have an overflow. 
And so what we do is we make multiple **Block-1** that are chained together:
![[Pasted image 20230201220549.png|500]]

# Index in SQL
Creating an index:
```sql
CREATE INDEX index_name
-- OR
CREATE NONCLUSTERED INDEX index_name
ON table_name (column1, column2, ...);
```

Delete an index:
```sql
DROP INDEX index_name;
```