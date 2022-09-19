A binary tree has 0,1 or 2 children

- `Depth:` of a node = length of the path from the **root** to the node 
- `Height:` of a node = length of the path from the node to the deepest node
- `Height of the tree` is the max height among all the nodes in the tree and depth of the tree is the max depth among all the nodes in the tree 
# Types of binary trees
- `Strict Binary Tree:` Each node has 2 children or none at all
- `Full Binary Tree:` Each node has 2 children and all leaf nodes are on the same level
- `Complete Bianry Tree:` All leaf nodes are at height `h` or `h-1` from the the root and also without any missing number in the sequence.
	*Example:*
	![[Pasted image 20220627173020.png | 250]]

# Properties of binary trees
![[Pasted image 20220627173149.png]]

# Binary Tree (Btree) ADT
![[Pasted image 20220627173356.png]]
![[Pasted image 20220627173419.png]]

# Dynamic Based Implementation
**`Type_Btree.h`**
```c
typedef int element;
typedef struct node
{
	element data;
	struct node* left;
	struct node* right;
}*Btree;
```

**`Btree.h`**
```c
#include "Type_Btree.h"

extern Btree Create_Btree();
extern int isEmpty_Btree(Btree B);
extern Btree Construct(element e, Btree L, Btree R);
extern int Root(Btree B, element *e);
extern int Right(Btree B, Btree* R);
extern int Left(Btree B, Btree* L);
```

**`Btree.c`**
```c
#include "Btree.h"

Btree Create_Btree()
{
	return NULL;
}

int isEmpty_Btree(Btree B)
{
	return B == NULL;
}

Btree Construct(element e, Btree L, Btree R)
{
	Btree temp = (Btree)malloc(sizeof(struct node));
	
	if(!temp)
		return 0;

	temp->data = e;
	temp->left = L;
	temp->right = R;

	return temp;
}

int Root(Btree B, element *e)
{
	if(isEmpty_Btree(B))
		return 0
	
	*e = B->data;
	return 1;
}

int Right(Btree B, Btree* R)
{
	if(isEmpty_Btree(B))
		return 0
	
	*R = B->right;
	return 1;
}

int Left(Btree B, Btree* L)
{
	if(isEmpty_Btree(B))
		return 0
	
	*L = B->left;
	return 1;
}
```

# Static Based Implementation
Elements are stored into an array of nodes
![[Pasted image 20220627181621.png]]
To delete a node we go through its children and its children children... and we put `-1` on the left (or right) in each node to state that the node doesnt belong to the tree.

**`Type Btree.h`**
```c
typedef int element;

typedef struct
{
	element root;
	int left_subtree; //represents indices
	int right_subtree;
}node;

typedef struct
{
	node data[N];
	int root_index;
} Btree;
```

**`Btree.h`**
```c
#include "Type_Btree.h"

extern void Create_Btree(Btree* B);
extern int add_left_child(Btree* B, element parent, element left_child);
```

```c
#include "Btree.h"

int Create_Btree(Btree* B)
{
	B->root_index = 0;
	for(int i=1; i < N; i++)
		B->data[i].left_subtree = -1;
}


int add_left_child(Btree* B, element parent, element left_child)
{
	int i;
	int j;
	//First we need to find if the parrent node exists
	//we stop if we find the parent
	for(i=1; i < N && (B->data[i].root != parent || B->data[i].left_subtree == -1); i++);
	
	//Stopping condition
	//B->data[i].root == parent && B->data[i].left_subtree == -1
	if(i == N) //parent doesnt exist
		return 0;
		
	if(B->data[i].left_subtree != 0) //parent already has a left subtree
		return 0;
	
	//otherwise i is the index of the parent node
	
	//Now we check if the child node already exists
	for(j=1; j<N && (B->data[j].root != left_child || B->data[j].left_subtree == -1));
	
	//Stopping condition:
	//B->data[j].root == left_child && B->data[j].left_subtree != -1
	if(j<N) //left child exists
		return 0;
	
	//Finding an empty node
	for(j=1; j<N && B->data[j].left_sutree == -1; j++);
	
	if(j == N) //no empty nodes left
		return 0;
	
	//Otherwise we found an empty node
	B->data[j].root = left_child;
	B->data[j].left_subtree = 0;
	B->data[j].right_subtree = 0;
	B->data[i].left_subtree  = j;
	
	return 1;
}
```