# Iterating down a list
- (1) copy head pointer into local variable `currentNode;`
- (2) test for end of the list with `currentNode != NULL;`
- (3) advance pointer with `currentNode = currentNode->nextNode;`
```c
int ListLength(struct node *head)
{
	int count = 0;
	//1
	struct node *currentNode = head;
	//2
	while(currentNode != NULL)
	{
		//3
		currentNode = currentNode->nextNode;
		count++;
	}
	return count;
}
```

# Changing a Pointer with a reference Pointer
if functions need to change caller's head pointer -> pass *pointer to head pointer* :`reference pointer`
- to change a `node*`, pass a `node**`
- use `&` in call
- use `*` in calling function to access and change value
```c
void ChangeToNull(node** headRef)
{
	*headRef = NULL;
}

void ChangeTest()
{
	node *head1;
	node *head2;
	ChangeToNull(&head1);
	ChangeToNull(&head2);
}
```
![[Pasted image 20220114091356.png | 700]]

# `Push:` add a node to the head of the list
- (1) Allocate the new node in the heap and set its `.data` to whatever needs to be stored.
- (2) set the `.nextNode` pointer of the new node to point to the current first node of the list.
- (3) change the head pointer to point to the new node, so it is now the first node in the list.
```c
void Push(node **headRef, int newData)
{
	//1
	node *newNode = (node*)malloc(sizeof(node));
	newNode->data = newData;
	//2
	newNode->nextNode = *headRef;
	//3
	*headRef = newNode;
}
```

# Build - At head with `Push()`
The disadvantage of the following function is it will add each element to the start of the list making it all in reverse order.
```c
struct node *AddAtHead()
{
	struct node *head = NULL;
	for(int i=0; i<6; i++)
		Push(&head, i);
	// {5, 4, 3, 2, 1}
	return head;
}
```

# Build - With Tail Pointer
Locate the final node and change its node pointer to the new node.
One exception with this not is if the node is the first in list, in this case the head pointer itself must be changed.
```c
for(currentNode = head; currentNode && currentNode->nextNode; currentNode = currentNode->nextNode)
	//...
```

# Build - Special Case + Tail Pointer
**1st Method**
- (1) build up list {1, 2, 3, 4, 5} by appending nodes to tail end
- (2) every first node must be added at head pointer
- (3) all other nodes inserted after last node using tail pointer
```c
struct node* BuildWithSpecialCase()
{
	struct node* head = NULL;
	struct node* tail; //1

	tail = head; //1
	Push(&head, 1);//2

	for(int i=2; i<6; i++)
	{
		Push(&(tail->nextNode), i);
		tail = tail->nextNode;
	}

	//{1, 2, 3, 4, 5}
	return head;
}
```

# Build - Local References
- (1) use a local reference pointer  which always points to the last pointer in the list instead of to the last node
reference pointer starts off pointing to head pointer
- (2) additions to list are made by following reference pointer
- later, it points to `.next` field inside the last node in the list
```c
struct node* BuildWithLocalReference()
{
	srtuct node* head = NULL;
	struct node** lastPointerReference = &head;

	for(int i=1; i<6; i++)
	{
		Push(lastPointerReference, i);
		lastPtrReference = &((*lastPointerReference)->next);
	}
	
	//{1, 2, 3, 4, 5}
	return head;
}
```

**`NOTE`**
![[Pasted image 20220114113847.png | 700]]
