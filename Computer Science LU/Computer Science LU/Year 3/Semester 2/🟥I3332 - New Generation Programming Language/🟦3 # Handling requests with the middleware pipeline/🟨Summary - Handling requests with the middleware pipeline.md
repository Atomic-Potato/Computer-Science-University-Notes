*Important bits are ==highlighted==*

--- 

- Middleware has a similar role to HTTP modules and handlers in ASP.NET but is more easily reasoned about.
- Middleware is composed in a pipeline, with the output of one middleware passing to the input of the next. 
- The middleware pipeline is two-way: requests pass through each middleware on the way in and responses pass back through in the reverse order on the way out.
- ==Middleware can short-circuit the pipeline by handling a request and returning a response, or it can pass the request on to the next middleware in the pipeline.==
- ==Middleware can modify a request by adding data to, or changing, the `HttpContext` object.==
- ==If an earlier middleware short-circuits the pipeline, not all middleware will execute for all requests.==
- ==If a request isn’t handled, the middleware pipeline will return a `404` status code.==
- The order in which middleware is added to IApplicationBuilder defines the order in which middleware will execute in the pipeline.
- ==The middleware pipeline can be re-executed, as long as a response’s headers haven’t been sent.==
- ==When added to a middleware pipeline, `StaticFileMiddleware` will serve any requested files found in the `wwwroot` folder of your application.==
- `DeveloperExceptionPageMiddleware` provides a lot of information about errors when developing an application but should never be used in production.
- `ExceptionHandlerMiddleware` lets you provide user-friendly custom error handling messages when an exception occurs in the pipeline.
- `StatusCodePagesMiddleware` lets you provide user-friendly custom error handling messages when the pipeline returns a raw error response status code.
- Microsoft provides some common middleware and there are many third-party options available on NuGet and GitHub.