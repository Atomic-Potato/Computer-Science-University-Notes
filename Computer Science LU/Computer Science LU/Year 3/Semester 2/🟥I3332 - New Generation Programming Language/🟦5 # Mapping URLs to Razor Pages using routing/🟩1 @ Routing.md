# What is Routing
You can use routing to control the URLs you expose in your application.

You can also use routing to enable powerful features like mapping multiple URLs to the same Razor Page, and automatically extracting data from a request’s URL.

Routing in ASP.NET Core is the process of mapping an incoming HTTP request to a specific handler.

![[Pasted image 20230602191329.png]]

# Endpoint Routing
Endpoint routing is implemented using two pieces of middleware :
- [[#EndpointMiddleware]] is to register the “endpoints” in routing of the system when you start your application. *(executes one of the endpoints at runtime.)*
- `EndpointRoutingMiddleware` This middleware chooses which of the endpoints registered by the `EndpointMiddleware` should execute for a given request at runtime.

## EndpointMiddleware 
This is where you register your Razor Pages and MVC controllers and other handlers
To register endpoints in your application, call `UseEndpoints` in the Configure method of [[🟩3 @ Startup Class|Startup.cs]].
![[Pasted image 20230602191646.png]]
![[Pasted image 20230602191650.png]]

![[Pasted image 20230602191755.png]]

> ==NOTE:== If you have a piece of middleware that needs to know which endpoint *(if any)* a given request will execute, then you need to make sure you place it after the `RoutingMiddleware` and before the `EndpointMiddleware`.
> ![[Pasted image 20230606114458.png]]

# Convention-based VS. Attribute Routing
- `Convention-based routing` is defined globally for your application.
  Map endpoints *(MVC controller actions)* in your application to URLs, but your MVC controllers must adhere strictly to the conventions you define.
  The downside to this approach is it makes customizing the URLs for a subset of controllers and actions more difficult.

- `Attribute-based routing` is to tie a given URL to a specific endpoint.
  For MVC controllers, this involves placing [Route] attributes on the action methods themselves, hence the term attribute-routing.
  And its more flexible
