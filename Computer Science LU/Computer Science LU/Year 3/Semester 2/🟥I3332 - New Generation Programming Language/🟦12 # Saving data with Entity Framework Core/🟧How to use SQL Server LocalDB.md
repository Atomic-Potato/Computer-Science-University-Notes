# 1. Install the required packages
install all of the packages using NuGet in the following list
```
Microsoft.EntityFrameworkCore
Microsoft.EntityFrameworkCore.Tools
Microsoft.EntityFrameworkCore.SQLServer
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

# 2. Name your DB
Open the object explorer window under "View"
![[Pasted image 20230711223702.png]]

You should find one DB already present. You can rename the database to whatever you want. *(Keep this name for later as it will be used for connection)*
![[Pasted image 20230711223857.png]]

# 3. Connecting to the database
## 3.a Connection string
First thing you gotta do is make the connection string.
So go to `appsettings.json` and add the following code at the top
```json
{
  "ConnectionStrings": {
    "DefaultConnection": "Server=(localdb)\\mssqllocaldb;Database=DATABASE_NAME;Trusted_Connection=True;MultipleActiveResultSets=true"
  },
  // ...
}
```

> **==NOTE==** For `Database` use the name of the DB found in the *"SQL Server Object Explorer"* window

## 3.b Database Context
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

## 3.c Registering the database context
in `program.cs` add the following code before building the app:
```cs
builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseSqlServer(builder.Configuration.GetConnectionString("DefaultConnection")));
```

> **==NOTE==** make sure to register this service before building the app


# 4. Creating migrations
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

Finally you can find your tables in here
![[Pasted image 20230711224028.png]]