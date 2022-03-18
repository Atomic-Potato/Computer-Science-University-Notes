Linked lists are a collection of pairs (var-pointer) where each pair points to the next element in the list, last one points to null. This means the elements of the list wont be next to each other in the memory. (We use the word "Node" to refer to an element in the list).

# Declaration of a Node
```c
struct node{
	int data;
	struct node* nextNode;
}
```

# Representation in memory
![[Pasted image 20220114090413.png | 700]]