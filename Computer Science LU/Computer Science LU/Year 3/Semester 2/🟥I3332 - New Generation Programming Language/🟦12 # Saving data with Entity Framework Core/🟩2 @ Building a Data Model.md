# Conventions
- EF Core identifies this pattern of *TId* as indicating the primary key of the table.
- *RecipeId* property on the *Ingredient* class. EF Core interprets this to be a foreign key pointing to the *Recipe* class.
- When considered with *ICollection* on the Recipe class, this represents a many-to-one relationship.

You can also use [[DataAnnotations]] attributes to decorate your entity classes, controlling things like column naming or string length.

![[Pasted image 20230615150135.png]]
![[Pasted image 20230615150159.png]]

# Code-First approach
As well as the entities, you also define the `DbContext` for your application. This is the heart of
EF Core in your application, used for all your database calls. 

Create a custom `DbContext`, in this case called `AppDbContext`, and derive from the `DbContext` base class, as shown next. 
This exposes the `DbSet<Recipe>` so EF Core can discover and map the Recipe entity. You can expose multiple instances of `DbSet<>` in this way, for each of the *“top-level”* entities in your application.

![[Pasted image 20230615150321.png]]
> ==**NOTE:**== You didn’t list Ingredient on `AppDbContext`, but it will be modeled by EF Core as it’s exposed on the Recipe. You can still access the Ingredient objects in the database, but you have to go via the Recipe entity’s Ingredients property to do so


## Registering the data context
```cs
builder.Services.AddDbContext<AppDbContext>(
	options => options.UseSqlServer(
		builder.Configuration.GetConnectionString("Default")));
```

# Database-First approach
The code first approach is typical, but if you have an existing database, you can automatically generate the EF entities and `DbContext` instead.

https://www.entityframeworktutorial.net/efcore/create-model-for-existing-database-in-ef-core.aspx

