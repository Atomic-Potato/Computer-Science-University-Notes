# Creating a record
The best way to do this is by doing the following steps
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

# Loading Records
now im not gonna repeat the entire foundation, so its better if you look at [[#Creating a record]] first.

Basically we just use LINQ commands to make queries
![[Pasted image 20230616182503.png]]

EF Core uses a fluent chain of LINQ commands to define the query to return on the database.
The `DbSet<Recipe>` property on `AppDataContext` is an `IQueryable`, so you can use all the
usual `Select()` and `Where()` clauses that you would with other `IQueryable` providers. EF Core
will convert these into a SQL statement to query the database with when you call an execute
function such as `ToListAsync()`, `ToArrayAsync()`, or `SingleAsync()`, or their non-async
brethren.

![[Pasted image 20230616182909.png]]

## List of available LINQ queries
![[Pasted image 20230616182542.png]]


# Loading a single record
We can simply use the `Where()` LINQ expression to restrict the query to a single record by searching for a specific id
```cs
.Where(r => r.id = id); // the id is taken as a parameter from somewhere
```

And then we use a `Select()` clause to map the record to an object. And finally the `SingleOrDefaultAsync()` clause will cause EF Core to generate the SQL query, execute it on
the database, and build the view model.

> **==NOTE==** `SingleOrDefaultAsync()` will throw an exception if the previous Where clause returns more than one record.

![[Pasted image 20230616183658.png]]
![[Pasted image 20230616183711.png]]


# Updating a model with changes
For web applications, when you update an entity, you’ll typically follow these steps:
1. Read the entity from the database
2. Modify the entity’s properties
3. Save the changes to the database

![[Pasted image 20230616185453.png]]

In this example, I read the Recipe entity using the `FindAsync(id)` method exposed by `DbSet`.
This is a simple helper method for loading an entity by its ID, in this case *RecipeId*. I could’ve
written a similar query using LINQ as
```cs
_context.Recipes.Where(r=>r.RecipeId == cmd.Id).FirstOrDefault();
```
Using `FindAsync()` or `Find()` is a little more declarative and concise.

# Deleting a record
1. EF Core can easily handle these true deletion scenarios for you with the `DbContext .Remove(entity)` command.
2. What you mean when you find a need to delete data is to archive it or hide it from the UI.
3. A common approach to handling this scenario is to include some sort of *“Is this entity deleted”* flag on your entity, such as the *IsDeleted* flag I included on the Recipe entity: `public bool IsDeleted {get;set;}`

![[Pasted image 20230616190217.png]]

