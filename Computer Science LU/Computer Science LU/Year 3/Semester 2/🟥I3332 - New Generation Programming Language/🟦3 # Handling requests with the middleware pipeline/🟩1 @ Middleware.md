The middleware pipeline is one of the most important parts of configuration for defining how your application behaves and how it responds to requests.

In ASP.NET Core, middleware is C# classes that can handle an HTTP request or response.

Middleware can:
- Handle an incoming HTTP request by generating an HTTP response.
- Process an incoming HTTP request, modify it, and pass it on to another piece of middleware.
- Process an outgoing HTTP response, modify it, and pass it on to either another piece of middleware, or the ASP.NET Core web server.

# Pipeline
This arrangement, where a piece of middleware can call another piece of middleware, which in turn can call another, and so on, is referred to as a pipeline.
==Note:== The pipeline is bidirectional

![[what is a pipeline (67).png]]

# HttpContext object
The ASP.NET Core web server constructs an `HttpContext`, which the ASP.NET Core application uses as a sort of storage box for a single request. *(details of the original HTTP request and other configuration details)*

**All middleware has access to the `HttpContext` for a request.**

More info about this object:
![[HttpContext object (69).png]]

# Adding Middleware
Middleware is added in the [[🟩3 @ Startup Class|startup class]] inside the `Configure` method by adding it to an `IApplicationBuilder` object.
![[Pasted image 20230602165009.png]]

> ==Tip:== Use the extension methods to see all the middleware you have available. All middleware start with `Use` by convention.
> ![[extension methods (75).png]]

# Handling Static Files
Most web applications, including those with dynamic content, serve a number of pages using static files. *(Images, JavaScript, and CSS stylesheets are normally saved to disk during development and are served up when requested, normally as part of a full HTML page request.)*

In this example, an image called moon.jpg exists in the `wwwroot` folder. When you request the file using the */moon.jpg* path, it’s loaded and returned as the response to the request. .
![[Pasted image 20230602165419.png]]
Sending a request for a non existing file
![[Pasted image 20230602171806.png]]

## Adding The Middleware
![[Pasted image 20230602171903.png]]
![[Pasted image 20230602171918.png]]

If the file doesn’t exist, then the request effectively passes through the static file middleware unchanged.
ASP.NET Core effectively adds an automatic “dummy” piece of middleware to the end of the pipeline. *(This middleware always returns a 404 response if it’s called)*


# Error Handling

The main error handling middleware:
![[error handling middleware (66).png]]

Adding error handling middleware:
![[Pasted image 20230602172303.png]]

## Exception handling middleware propagation through pipeline
![[Exception handling middleware propagation through pipeline (93).png]]

## Error status code handling middleware propagation through pipeline

![[Error status code handling middleware propagation through pipeline  (98).png]]

### HTTP Response codes
![[http response codes (79).png]]