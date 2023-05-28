==Note:== This summary is provided from the E-Book *"ASP.Net  Core in Action, Second Edition"*

- The `csproj` file contains details of how to build your project, including which NuGet packages it depends on. It’s used by Visual Studio and the .NET CLI to build your application.
- Restoring the NuGet packages for an ASP.NET Core application downloads all your project’s dependencies so it can be built and run.
- `Program.cs` defines the static void Main entry point for your application. This function is run when your app starts, the same as for console applications.
- `Program.cs` is where you build an `IHost` instance, using an `IHostBuilder`. The helper method, `Host.CreateDefaultBuilder()` creates an `IHostBuilder` that loads configuration settings and sets up logging. Calling Build() creates the `IHost` instance.
- The `ConfigureWebHostDefaults` extension method configures the generic host using a `WebHostBuilder`. It configures the Kestrel HTTP server, adds IIS integration if necessary, and specifies the application’s Startup class.
- You can start the web server and begin accepting HTTP requests by calling Run on the `IHost`.
- Startup is responsible for service configuration and defining the middleware pipeline.
- All services, both framework and custom application services, must be registered in the call to `ConfigureServices` in order to be accessed later in your application.
- Middleware is added to the application pipeline with `IApplicationBuilder`. Middleware defines how your application responds to requests.
- The order in which middleware is registered defines the final order of the middleware pipeline for the application. Typically, `EndpointMiddleware` is the last middleware in the pipeline. Earlier middleware, such as `StaticFileMiddleware`, will attempt to handle the request first. If the request is handled, `EndpointMiddleware` will never receive the request.
- Razor Pages are located in the Pages folder and are typically named according to the URL path they handle. For example, `Privacy.cshtml` handles the path `/Privacy`.
- Razor Pages must contain the `@page` directive as the first line of the file.
- Page models derive from the `PageModel` base class and contain page handlers. Page handlers are methods named using conventions that indicate the HTTP verb they handle. For example, `OnGet` handles the GET verb.
- Razor templates can contain standalone C#, standalone HTML, and dynamic HTML generated from C# values. By combining all three, you can build highly dynamic applications.