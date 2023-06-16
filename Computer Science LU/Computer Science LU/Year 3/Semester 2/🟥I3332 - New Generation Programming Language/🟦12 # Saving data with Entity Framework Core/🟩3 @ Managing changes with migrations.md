EF Core provides its own version of schema management called migrations.
Migrations provide a way to manage changes to a database schema when your EF Core data model changes.

A migration is a C# code file in your application that defines how the data model changed—which columns were added, new entities, and so on.

Migrations provide a record over time of how your database schema evolved as part of your application, so the schema is always in sync with your app’s data model.

# Creating a migration
>1. Install "package manager console": Microsoft.EntityFrameworkCore.Tools
>2. Install .NET Core tools: dotnet tool install --global dotnet-ef **(This will install it globally on your machine)**

Make sure you have restored packages and check the folder you’re executing from.

run `dotnet ef` tools from the project folder in which you have registered your `AppDbContext`, not at the solution-folder level.

Now run the following command:
```
dotnet ef migrations add InitialSchema
```

This command creates three files in your solution:
- `Migration file`—A file with the `Timestamp_MigrationName.cs` format. This describes the actions to take on the database, such as Create table or Add column.
- `Migration designer.cs file`—This describes EF Core’s internal model of your data model at the point in time the migration was generated.
- `AppDbContextModelSnapshot.cs`—This describes EF Core’s current internal model. This will be updated when you add another migration, so it should always be the same as the current, latest migration.
![[Pasted image 20230616113921.png]]

## Applying the migration
You can apply migrations in one of three ways:
- Using the .NET CLI
- Using the Visual Studio PowerShell cmdlets
	```
	dotnet ef database update
	```
	1. Builds your application.
	2.  Loads the services configured in your app’s `Startup` class, including `AppDbContext`.
	3. Checks whether the database in the `AppDbContext` connection string exists. If not, it creates it.
	4. Updates the database by applying any unapplied migrations.
- In code, by obtaining an instance of your `AppDbContext` and calling `context.Database.Migratte()` 

> Refer to https://docs.microsoft.com/en-us/ef/core/managing-schemas/migrations/?tabs=dotnet-core-cli

Which is best for you is a matter of how you’ve designed your application, how you’ll update your production database, and your personal preference.


# Creating a second migration
EF Core migrations make this simple. Change your entities to your desired state, generate a migration, and apply it to the database
![[Pasted image 20230616134151.png]]
![[Pasted image 20230616134302.png]]

