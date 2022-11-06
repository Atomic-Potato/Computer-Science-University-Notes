![[Pasted image 20220610150710.png]]

# Implementation
**`Type_Stack.h`**
```c
typedef int element;
typedef struct cell
{
	element data;
	struct cell* next;
} *stack;
```

**`Stack.h`**
```c
#include "Type_Stack.h"
extern stack CreateStack();
extern int Push(stack *p, element e);
extern int Pop(stack *p);
extern int Top(stack p, element *e);
extern int isEmptyStack(stack p);
```

**`Stack.c`**
```c
#include  "Stack.h"
stack CreateStack()
{
	return NULL;
}

int Push(stack *p, element e)
{
	stack newEntry = (stack)malloc(sizeof(struct cell));
	if(newEntry == NULL)
		return 0;

	newEntry->data = e;
	newEntry->next = *p;
	*p = newEntry;

	return 1;
}

int Pop(stack *p)
{
	stack temp;

	if(isEmptyStack(*p))
		return 0;

	temp = *p;
	*p = (*p)->next;
	free(temp);
	return 1;
}

int Top(stack p, element *e)
{
	if(isEmptyStack(p))
		return 0;

	*e = p->data;
	return 1;
}

int isEmptyStack(stack p)
{
	return p == NULL;
}
```