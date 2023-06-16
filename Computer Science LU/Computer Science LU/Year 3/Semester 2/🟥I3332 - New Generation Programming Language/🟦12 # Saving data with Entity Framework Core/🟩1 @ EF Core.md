# What is EF Core

EF Core enables developers to define a domain model using plain .NET classes, referred to as `entity classes`, and map them to database tables. 
It abstracts the underlying database-specific operations and provides a high-level API for performing common database operations like querying, inserting, updating, and deleting data.

Key features of EF Core include:
1. **Code-First Approach:** With EF Core, you can define your entity classes first and then generate the database schema from those classes. It eliminates the need for manually creating database tables and writing SQL scripts.
2. **LINQ Support:** EF Core integrates with Language-Integrated Query (LINQ), which allows developers to write expressive and type-safe queries against the database using familiar C# or VB.NET syntax. LINQ queries are translated into database-specific queries by EF Core.
3. **Change Tracking:** EF Core keeps track of changes made to the entities and provides mechanisms to automatically persist those changes to the database when you save the changes. This simplifies the process of updating, inserting, and deleting records.
4. **Migrations:** EF Core includes a migration system that automates the process of applying database schema changes as your application evolves. It helps you keep the database schema in sync with your entity model.
5. **Database Providers:** EF Core supports multiple database providers, including SQL Server, MySQL, PostgreSQL, SQLite, and others. You can switch between different database providers without changing your application code.

When you interact with EF Core, you’ll be primarily using `POCO entities` and a `database context` that inherits from the `DbContext` EF Core class.

> **==DEFINITION:==** An entity is a .NET class that’s mapped by EF Core to the database.

# The start of EF Core
When your application first uses EF Core, **it creates an internal representation of the database**, based on the `DbSet<T> `properties on your application’s `DbContext` and the entity classes themselves.
![[Pasted image 20230615135957.png]]

# Adding EF Core
- Choose a database provider; for example, MySQL, Postgres, or MS SQL Server.
- Install the EF Core NuGet packages.
- Design your app’s DbContext and entities that make up your data model.
- Register your app’s DbContext with the ASP.NET Core DI container.
- Use EF Core to generate a migration describing your data model.
- Apply the migration to the database to update the database’s schema.

> I have used MySQL for EF Core, so checkout [[🟧How to use MySQL with EF Core]]


# Scaffolding
Scaffolding in ASP.NET Core is a technique used to generate code at design time to support a number of common application scenarios when working with Entity Framework Core.

> Complete Example :
> https://docs.microsoft.com/en-us/aspnet/core/data/ef-rp/intro?view=aspnetcore-5.0&tabs=visual-studio


