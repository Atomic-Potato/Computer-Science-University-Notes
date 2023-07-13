# Data Annotations & Other Tags
Data Annotations
```cs
[Key]
[Required]
[Display(Name = "")]
[Compare("Varibale name to compare to", ErrorMessage = "The password and confirmation password do not match.")]

[StringLength(69)]
[Range(69, 420)]
[MinLength(69)]
[MaxLength(420)]

[EmailAddress]
[CreditCard]
[Phone]
[Url]
```

>**==NOTE==** You can add an error message to most of these by just adding `ErrorMessage=""` inside the parenthensis

Model Binding
```cs
[BindProperty]
[BindProperties]
```

Ignoring forgery token *(for postman)*
```cs
[IgnoreAntiforgeryToken]
```

---

# Dependency Injection
```cs
// Everytime a new instance is created
builder.services.AddTransient<ServiceClass>();

// Different instances for different scopes
builder.services.AddScoped<ServiceClass>();

// A single instance for the entire app
builder.services.AddSingleton<ServiceClass>();

```

>**==NOTES:==**
>- Register services before `build()`
>- **A service should only use dependencies with a lifetime longer than or equal to the lifetime of the service**

--- 

# Database

## Creating the database
To be safe do them in this order:

First finish your [[#Data Annotations]]

### Global Libraries
```cs
global using System.ComponentModel.DataAnnotations;
global using System.ComponentModel.DataAnnotations.Schema;
global using Microsoft.EntityFrameworkCore;
// before doing this one, create a folder to store your tables classes in
// and then write ProjectName.FolderName;
global using DatabaseTest.Data; 
```

### Connection String
```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Server=(localdb)\\mssqllocaldb;Database=DATABASE_NAME;Trusted_Connection=True;MultipleActiveResultSets=true"
  },
  // ...
}
```

### Database Context
```cs
namespace DatabaseTest.Data
{
    public class AppDbContext : DbContext{
        public AppDbContext(DbContextOptions<AppDbContext> options) : base (options){
        }
        public DbSet<Person> Persons { get; set; }
    }
}
```


### Registering the database context
in `program.cs` add the following code before building the app:
```cs
builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection")));
```

### Migrations
```
add-migration migrantion_name
update-database
```

### Scaffolding
1. Right click the pages folder
2. *Add -> New Scaffolded Item*
3. Pick `Razor Pages using Entity Framework (CRUD)` and add it *(Last one in the list)*

---

## Database Operations
Pretty much all of the ops have a sync version, im just gonna put the sync ones.
```cs
// Remember to make the function synchronous using:
async Task<return_type>
```

### Adding a Record
```cs
dbContext.Add(entity_object);
return await dbContext.SaveChangesAsync();
```

### Loading a List of Records
```cs
return await _context.Table_Name
	.Where(r => condition)
	.Select(r => new Entity_Class{
		pram1 = r.param1
	})
	.ToListAsync(); // beter one to use
	// OR
	.ToArrayAsync();

// Returns an IQueryable, set the return type of the function to ICollection
```

### Loading a Single Record
```cs
return await _context.Table_Name
	.Where(r => r.id == id)
	.Select(r => new Entity_Class{
		pram1 = r.param1
	})
	.ToSingleOrDefaultAsync();

// OR
return await _context.Table_Name.FindAsync(id);
```

### Updating a Record
1. Get the cv object using `FindAsync()`
2. Change the returned object values
3. save changes
```cs
Class object = await db.Table.FindAsync(id);
UpdateInfo();
await db.SaveChangesAsync();
```

### Deleting a Record
1. Get the cv object using `FindAsync()`
2. delete
3. save changes
```cs
Class object = await db.Table.FindAsync(id);
db.Remove(object);
await db.SaveChangesAsync();
```

---

# Tag Helpers
```cshtml 
<form asp-page="Page"></form>
<!--For pages with route parameter like @page "{id}"-->
<form asp-page="Page" asp-rout-*="x"></form>

<label asp-for="variable"></label>
<input asp-for="variable">
<select asp-for="list_variable" asp-items="list_values"></select>
<span asp-validation-for="variable"></span>

<div asp-validation-summary="All"></div>
<!-- 
	None
	ModelOnly - Displays errors that are not associated with a property
	All
-->
```

# Middleware
The only important one ngl is the developer exception page
```cs
app.UseDeveloperExceptionPage(); // Provides quick error feedback when building an application
app.UseExceptionHandler() // Provides a user-friendly generic error page in production
app.UseStatusCodePages(); // Converts raw error status codes into user-friendly error pages
```

# Routing
```cshtml
@page "{name}" // appends to url
@page "/{name}" // replaces url

@page "{name=default-value}" // optional with a default value
@page "{name?}" // optional with no default value

@page "{name:constraint:constraint}"

// catching all parameters
@page "{*name}"
@page "{**name}"
```
![[Pasted image 20230606121151.png]]

Invoking a specific page handler
![[Pasted image 20230606151344.png|400]]

> Examples:
> - `OnGet`—Invoked for GET requests that don’t specify a handler value.
> - `OnPostAsync`—Invoked for POST requests that don’t specify a handler value. Returns a Task so uses the `Async` suffix, which is ignored for routing purposes.  
> - `OnPostCustomSearch`—Invoked for POST requests that specify a handler value of "CustomSearch".

---

# Page Redirection
You can return one of these after on post
```cs
Page(); // current page, or void does the same
RedirectToPage("Page", new { route_var_name = value});
```
---

# Server Side Validation
In the OnPost function
```cs
/// <summary>
/// Checks if the form provided is valid
/// </summary>
/// <param name="input">The input binding model</param>
/// <returns>true if the form is valid, and false otherwise</returns>
bool ValidateForm(CVModel input) {
	if (!ModelState.IsValid)
		return false;

	if (!ValidateSum(cv)) {
		ModelState.AddModelError("cv.sum", "The sum of X & Y is incorrect!");
		return false;
	}

	return true;
}
```
---

# Windows
- `Package Manager Console`
  *Tools -> NuGet Package Manager -> Package Manager Console*
- `SQL Server Object Explorer`
  *View -> SQL Server Object Explorer*
- `Locals` *(The window that shows what variables contain when hitting a breakpoint)*
  Its always present in the bottom left corner of the screen when running the app
  ![[Pasted image 20230712205353.png]]