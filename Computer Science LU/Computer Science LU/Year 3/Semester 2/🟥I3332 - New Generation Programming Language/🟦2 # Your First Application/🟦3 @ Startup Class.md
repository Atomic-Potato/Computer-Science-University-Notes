The Startup class is responsible for configuring two main aspects of your application:
- `Service registration`—Any classes that your application depends on for providing functionality—both those used by the framework and those specific to your application—must be registered so that they can be correctly instantiated at runtime.
- `Middleware and endpoints`—How your application handles and responds to requests.

![[Pasted image 20230602160836.png]]

1. The `IHostBuilder` created in Program calls `ConfigureServices` and then `Configure`
2. Each call configures a different part of your application, making it available for subsequent method calls.
3. Any services registered in the `ConfigureServices` method are available to the `Configure` method.
4. Once configuration is complete, an `IHost` is created by calling `Build()` on the `IHostBuilder`.
![[Pasted image 20230602160916.png]]

# Adding Configuration Services
Service refers to any class that provides functionality to an application. Service could be classes exposed by a library or code you’ve written for your application.

> **The single responsibility principle (SRP)** states that every class should be responsible for only a single piece of functionality—it should only need to change if that required functionality changes.

You must register each service with the *“container”* before it can be used in your application.
As well as registering framework-related services, this method is where you’d register any custom services you have in your application.
![[Pasted image 20230602162022.png]]
> The IServiceCollection is a list of every known service that your application will need to use.
By adding a new service to it, you ensure that whenever a class declares a dependency on your service, the IoC container (dependency Injection)  knows how to provide it.

# Middleware Pipeline
![[Pasted image 20230602162129.png]]

## Developer Exception Page
`DeveloperExceptionPageMiddleware` *(added by the `UseDeveloperExceptionPage()` call)* will be presented with as much information as possible in the browser

## Https and Static File Middleware
The next piece of middleware added to the pipeline is the `HttpsRedirectionMiddleware`, using the statement: `app.UseHttpsRedirection();`

This ensures your application only responds to secure *(HTTPS)* requests and is an industry best practice.

`Static file Middelware` is responsible for handling requests for static files such as CSS files, JavaScript files, and images.

![[Pasted image 20230602162403.png]]

## Routing & Endpoint Middleware
Normally, the final piece of middleware in a pipeline is the `endpoint middleware` which works with the `routing middleware` to match a request URL’s path to a configured route, which defines which Razor Page to invoke.

Once a Razor Page has been selected, the `routing middleware` stores a note of the selected Razor Page in the request’s `HttpContext` and continues executing the middleware pipeline.

Eventually the request will reach the `endpoint middleware`. The `endpoint middleware` executes the Razor Page to generate the HTML response, and sends it back to the browser.
