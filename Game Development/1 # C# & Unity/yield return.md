`yield` keyword helps do custom stateful **iteration** over a collection

Say we have a list with the following values
```cs
List<int> MyList = new List(); // 1 2 3 4 5
```
And we display the values as follows: _(we shall call the `main()` function as the `caller`)_
```cs
static void Main(string[] args)
{
	foreach(int i in MyList)
		Console.WriteLine(i);
}
```
here is what actually happens
![[Pasted image 20220801153903.png]]

Say now we want to display the values that are greater than 3 by creating the function `Filter()`
```cs
static void Main(string[] args)
{
	foreach(int i in Filter())
		Console.WriteLine(i);
}

static IEnumerable<int> Filter()
{
	List<int> temp = new List<int>();
	foreach(int i in MyList)
		if(i > 3)
			temp.Add(i);
	return temp;
}
```
How it works
![[Pasted image 20220801154206.png]]

But what if we dont want to create auxiliary variables (now of course we can just do an if statement in the `Main()` but go with me for the sake of it)
Then here we can use `yield return` like so
```cs
static IEnumerable<int> Filter()
{
	foreach(int i in MyList)
		if(i > 3)
			yield return i;
}
```
What happened here
![[Pasted image 20220801154435.png | 450]]
- The `caller` goes through the list comparing `i`
- If it reaches a true value, then it returns this value to the `caller`
- the `caller` does what he wants with this value and **returns to the index where it left off** 
- repeat the process
---
Say we want to stack the values like so 
![[Pasted image 20220801154735.png | 300]]

Now we need an auxiliary variable to keep the count
```cs
static IEnumerable<int> Filter()
{
	int runningTotal = 0;
	foreach(int i in MyList)
	{
		runningTotal += i;
		yield return (runningTotal);
	}
}
```
Now the same process is done except, the `runningTotal` doesnt get reset each `yield return`  call (i.e. the function `Filter()` isnt "destroyed") it continues back from where it left off (i.e. `Filter()` continues the *foreach* loop)

---

# My conclusion
`yeild return` is just like `return` but doesnt actually exists the function, just pauses it until it gets called again.

**Note:** use `yeild break` to actually exit the function.