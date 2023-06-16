# 1. Install the required packages
install all of the packages using NuGet in the following list
```
Microsoft.EntityFrameworkCore
Microsoft.EntityFrameworkCore.Tools
MySql.EntityFrameworkCore
```

Now to use these packages globally, create a new cs script and name it whatever u want. And fill it with the following:
```cs
global using System.ComponentModel.DataAnnotations;
global using System.ComponentModel.DataAnnotations.Schema;
global using Microsoft.EntityFrameworkCore;
// before doing this one, create a folder to store your tables classes in
// and then write ProjectName.FolderName;
global using DatabaseTest.Data; 
```

# 2. Connecting to the database
## 2.a Connection string
First thing you gotta do is make the connection string.
So go to `appsettings.json` and add the following code at the top
```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Server=localhost; Database=DatabaseTest; User=root; Password=;"
  },
  // ...
}
```

> **==NOTE==** For Database use the name of the project, and for user and password, use the ones you use in php my admin

## 2.b Database Context
Now its time to create a database context class. In the Data folder, create this class
```cs
namespace DatabaseTest.Data
{
    public class AppDbContext : DbContext{
        public AppDbContext(DbContextOptions<AppDbContext> options) : base (options){
            
        }
        
        // I havent gone over how to make table classes
        // but simply in the same folder make a class 
        // and fill it with its properies
        // and add it to the database like so
        public DbSet<Person> Persons { get; set; }
    }
}
```

## 2.c Registering the database context
in `program.cs` add the following code before building the app:
```cs
string connSrting = builder.Configuration.GetConnectionString("DefaultConnection");
builder.Services.AddDbContext<AppDbContext>(options => options.UseMySQL(connSrting));
```

# 3. Creating migrations
First open the package manager console
![[Pasted image 20230616161940.png]]

add your migration with this command
```
add-migration migrantion_name
```

and then apply the change to the database
```
update-database
```

> **==NOTE==** make sure you have wamp or xampp running before you update your database