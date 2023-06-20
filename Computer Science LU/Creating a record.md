1. Create the table class
   ![[Pasted image 20230616180653.png]]
2. Make a new class that contains the same fields with data annotations and an extra function. This class will be bound to the user input, and the function will be used to convert that input into a new record *(lets call it command to keep track)*
   ![[Pasted image 20230616180414.png]]
   ![[Pasted image 20230616181115.png]]
   *The reason here that there is another class that inherits from the one above, is because we use the above one for other specific classes such as editing and deleting*
3. Bind this class in the razor page controller
   ![[Pasted image 20230616181259.png]]
4. Make a service class for adding a new record to the database *(will be used later on for other related services)* and add the following function.
   ![[Pasted image 20230616181504.png]]
   The context is the app database context that is injected in the controller
   ![[Pasted image 20230616181554.png]]
5. Back in the razor page controller, in the `OnGet()`, create a new instance of the command class
   ![[Pasted image 20230616181815.png]]
6. Now in one the `OnPost` handlers, call the function made in the service class which adds our input as a new record into the database
   ![[Pasted image 20230616182012.png]]

> **==BIG PHAT NOTE==** note that we are using `async Task` functions and `await` so we can safely add new data to the database without any other task/thread modifying our data. 
