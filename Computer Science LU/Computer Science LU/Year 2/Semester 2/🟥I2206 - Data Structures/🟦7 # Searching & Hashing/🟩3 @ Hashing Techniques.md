# How Hashing Gets O(1) Complexity
By using the load factor we make sure that each block (for example, linked list in separate chaining approach) on the average stores the maximum number of elements less than the load factor.

If the average number of elements in a block is greater than the load factor, we rehash the elements with a bigger hash table size.

The access time of the table depends on the load factor which in turn depends on the hash function. This is because hash function distributes the elements to the hash table.
For this reason, we say hash table gives O(1) complexity on average. 
Also, **we generally use hash tables in cases where searches are more than insertion and deletion operations.**

# Hashing Techniques
- `Static Hashing:`
If the data is fixed then static hashing is useful. In static hashing, the set of keys is kept fixed and given in advance.
- `Dynamic Hashing:`
If the data is not fixed, static hashing can give bad performance, in which case dynamic hashing is the alternative, in which case the set of keys can change dynamically.

# Problems for which Hash Tables are not suitable
- Problems for which data ordering is required
- Problems having multidimensional data
- Prefix searching, especially if the keys are long and of variable-lengths
- Problems that have dynamic data
- Problems in which the data does not have unique keys.