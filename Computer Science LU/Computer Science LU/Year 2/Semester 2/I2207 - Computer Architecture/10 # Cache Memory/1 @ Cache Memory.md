Exchanging data between the CPU and the RAM takes time and performance, so before the CPU accesses the RAM, it searches for the requested data in the **Cache memory** 

![[Pasted image 20220714161829.png]]

`RAM` and `Cache` are decomposed into cells of **one byte each.** Transformation between `RAM` and `Cache` **is done line by line**, where lines have equal length in both the ram and cache.

`Line lenght:` (usually 64 bytes) is the number of bytes brought from RAM to Cache in response to a **cache miss**.

There are three strategies for data transformation:
1. *Direct mapping*
2. *Fully associative*
3. *Set associative*