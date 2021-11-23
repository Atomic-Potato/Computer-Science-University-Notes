# What are "Stacks" ?
Imagine a stack of boxes, you can only add new boxes from the top, and only remove new boxes from the top, this is what stacks are but with any type of variable we want

### How to work with stacks
```c++
#include <stack>
using namespace std;

int main(){
	//Decleration
	stack<char> c;
	
	//c.empty() returns 1 or 0
	c.push('a'); // adds 'a' to the top of the stack
	c.pop(); // removes the top element of the stack
	//c.top(); returns the value in the top of the stack
	
	//if we printed the top of the stack and popped it one bye one we get
	// c b a
}
```

# What are "Queues" ?
They are the same as stacks, but imagine a queue in a supermarket, you add people from the start of the line who finished shopping and you remove people who payed in the front

### How to work with queues
```c++
#include <queue>
using namespace std;

int main(){
	//Decleration
	queue<char> c;
	
	//c.empty() returns 1 or 0
	c.push('a'); // adds 'a' to the start of the queue
	c.push('b');
	c.push('c');
	c.pop(); // removes the front element of the queue
	//c.front(); returns the value in the top of the queue
	
	//if we printed the front of the queue and popped it one bye one we get
	// a b c
}
```

# What are "Deques / Double Queues i think" ?
Deques are `stack` and `queue` both at the same time.

### How to work with deques
```c++
#include <queue> //Deques are contained in the <queue> library
using namespace std;

int main(){
	//Decleration
	deque<char> c;
	
	//c.empty() returns 1 or 0
	c.push_back('a'); // adds 'a' to the back of the queue
	c.push_front('b'); // adds 'b' to the front of the queue
	c.pop_back (); // removes the first element of the queue 
	c.pop_front(); // removes the front element of the queue
}
```

# What are "Priority Queues" ?
Its just a queue but when you push a new element to it, for example lets say its a queue of ints, it will see if this new int is greater than the ints in the queue above it and will put it on the top of the max one that its smaller than it if it makes sense

### How to work with priority queues
```c++
#include <queue>
using namespace std;

int main(){
	//Decleration
	priority_queue<pair<int, string>> pq; // NVM --> //can be also of a single type, pq works with pairs just like the sorting function
	
	pq.push(4, "a");
	pq.push(6, "b");
	pq.push(1, "c");
	
	//creating an empty pair
	pair<int> result;
	result = pq.top();
	pq.pop();
	printf(/*result*/); // prints 6, b
	printf(/*pq.top()*/) // prints 4, a
}