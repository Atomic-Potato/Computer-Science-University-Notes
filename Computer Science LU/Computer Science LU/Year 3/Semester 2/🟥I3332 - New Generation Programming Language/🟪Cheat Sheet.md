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

## X Database Operations

---

# X Tag Helpers


# X Middleware


# X Routing


# Windows
- `Package Manager Console`
  *Tools -> NuGet Package Manager -> Package Manager Console*
- `SQL Server Object Explorer`
  *View -> SQL Server Object Explorer*
- `Locals` *(The window that shows what variables contain when hitting a breakpoint)*
  Its always present in the bottom left corner of the screen when running the app
  ![[Pasted image 20230712205353.png]]