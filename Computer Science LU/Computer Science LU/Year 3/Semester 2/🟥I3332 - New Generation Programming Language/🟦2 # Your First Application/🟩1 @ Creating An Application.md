# Steps
1. `Generate`—Create the base application from a template to get started.
2. `Restore`—Restore all the packages and dependencies to the local project folder using NuGet.
   Both Visual Studio and the .NET CLI automatically restore packages when they first create your project
3. `Build`—Compile the application and generate all the necessary assets.
   You can compile your application by choosing `Build > Build Solution` or running the `dotnet build` command
4. `Run`—Run the compiled application.

*(I'm gonna skip how to create an app in VS)*

You can use these commands to perform the earlier steps
```
dotnet restore
dotnet build
dotnet run
```



