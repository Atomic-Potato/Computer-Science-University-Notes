`Hashing` is a technique used for sorting and retrieving information as fast as possible.
It provides _insertion, deletion and searching_ operations if we need in **O(1)**. Worst case is **O(n)** but it gives **O(1) on the average**

**HashTable ADT**:
- `Create HashTable`: Creates a new hash table
-  `Search`: Searches the key in hash table
-  `lnsert`: Inserts a new key into hash table
-  `Delete`: Deletes a key from hash table
-  `Delete HashTable`: Deletes the hash table

**Components in Hashing:**
- Hash table
-  Hash functions
-  Collisions
-  Collision resolution techniques

# Hash table
In an array, we store the element whose `key is k` at a position `k` of the array.
Hash table or hash map is a data structure that stores the keys and their associated value `S`.
Hash table uses a hash function to map keys to their associated values.

# Hash Function
The hash function should map each possible key to a unique slot index, but it’s difficult to achieve in practice.
![[Pasted image 20220802144806.png | 350]]

Characteristics of a good Hash Function:
- Minimize `collisions`
- Be easy and quick to compute
- Distribute key values evenly in the hash table
- Use all the information provided in the key
- Have a high `load factor` for a given set of keys

## Load Factor
The `load factor` tells whether the hash function is distributing the keys uniformly or not.  
$$\large \color{orange} load \space factor = \frac{number \space of \space elements \space in \space the \space hash \space table}{size \space of \space the \space hash \space table}$$

More on load factors: (2 min video)
https://youtu.be/pMKUrv1NksA
## Collisions
Collision is when the `hash function` generates the **same position** for two **distinct keys**
