![[Pasted image 20220610145510.png]]

# Implementation
**`Type_Stack.h`**
```c
#define N 20
typedef int element; //can be anything other than int
typedef struct
{
	element data[N]; //stack content
	int top;
}stack;

```

**`Stack.h`**
```c
#include "Type_Stack.h"
extern stack CreateStack();
extern int Push(stack *p, element e);
extern int Pop(stack *p);
extern int Top(stack p, element *e);
extern int isEmptyStack(stack p);
extern int isFullStack(stack p);
```

**`Stack.c`**
```c
#include  "Stack.h"
stack CreateStack()
{
	stack p;
	p.top = -1;
	return p;
}

int Push(stack *p, element e)
{
	if(isFullStack(*p))
		return 0;
		
	p->top++;
	p->data[p->top] = e;
	return 1;
}

int Pop(stack *p)
{
	if(isEmptyStack(*p))
		return 0;

	p->top--;
	return 1;
}

int Top(stack p, element *e)
{
	if(isEmptyStack(p))
		return 0;

	*e = p.data[p.top];
	return 1;
}

int isEmptyStack(stack p)
{
	return p.top == -1;
}

int isFullStack(stack p)
{
	return p.top == N-1;
}
```