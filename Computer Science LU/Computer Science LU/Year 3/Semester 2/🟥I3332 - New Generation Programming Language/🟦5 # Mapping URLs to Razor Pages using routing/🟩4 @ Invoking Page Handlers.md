Razor Pages can contain any number of page handlers, but only one runs in response to a given request.
![[Pasted image 20230606131512.png]]
![[Pasted image 20230606131515.png]]

When the `EndpointMiddleware` executes a selected Razor Page, it selects a page handler to invoke based on two variables:
- The HTTP verb used in the request *(for example GET, POST, or DELETE)*
- The value of the handler route parameter

The handler route value typically comes from a query string value in the request URL, for example */Search?handler=CustomSearch.*
>If you don’t like the look of query strings, you can include the {handler} route parameter in your Razor Page’s route template.
>```c
>@page "{handler}"
>```

This would give a complete route template something like *"Search/{handler}"*, which would match URLs such as */Search/CustomSearch*.

The `EndpointMiddleware` uses the handler route value and the HTTP verb together with a standard naming convention to identify which page handler to execute.
![[Pasted image 20230606151344.png|400]]

> Examples:
> - `OnGet`—Invoked for GET requests that don’t specify a handler value.
> - `OnPostAsync`—Invoked for POST requests that don’t specify a handler value. Returns a Task so uses the `Async` suffix, which is ignored for routing purposes.  
> - `OnPostCustomSearch`—Invoked for POST requests that specify a handler value of "CustomSearch".

If you get no matching handlers then the `EndpointMiddleware` executes an implicit page handler instead. Implicit page handlers contain no logic, they just render the Razor view.
