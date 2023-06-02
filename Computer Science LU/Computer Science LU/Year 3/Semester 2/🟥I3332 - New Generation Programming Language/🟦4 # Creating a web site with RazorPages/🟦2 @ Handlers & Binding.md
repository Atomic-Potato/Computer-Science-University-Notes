# Directing to Razor Pages & The Binding Model
A **binding model** is one or more objects that act as a *“container”* for the data provided in a request that’s required by a page handler.
![[Pasted image 20230602175715.png]]

## Handlers
The role of the page handler as the controller in the MVC pattern is to coordinate the generation of a response to the request it’s handling.

It should perform only a limited number of actions :
- `Validate` that the data contained in the binding model provided is valid for the request.
- `Invoke` the appropriate actions on the application model using services.
- `Select` an appropriate response to generate based on the response from the application model.

![[Pasted image 20230602180008.png]]

By default, the path of a Razor Page on disk controls the URL path that the Razor Page responds to.
For example, a request to the URL */products/list* corresponds to the Razor Page at the path *Pages/Products/List.cshtml*.

> Razor Pages can contain any number of page handlers, but only one runs in response to a given request.

### Returning Responses
Handlers also can return `IActionResult`, which has many types. But here are the main ones:
- A `PageResult` object. This causes the associated Razor view to generate an HTML response.
- `Nothing` *(the handler returns void or Task*). This is the same as the previous case, causing the Razor view to generate an HTML response.
- A `RedirectToPageResult`. This indicates the user should be redirected to a different page in your application.

Other `IActionResult`s:
- `ViewResult`—Generates an HTML view for a given Razor view when using MVC controllers.
- `RedirectResult`—Sends a 302 HTTP redirect response to automatically send a user to a specified URL (doesn’t have to be a Razor Page).
- `FileResult`—Returns a file as the response.
- `ContentResult`—Returns a provided string as the response.
- `StatusCodeResult`—Sends a raw HTTP status code as the response, optionally with associated response body content.
- `NotFoundResult`—Sends a raw 404 HTTP status code as the response.


### Accepting parameters to page handlers
The request may contain additional values from a variety of different sources:
- part of the URL,
- the query string,
- headers,
- or in the body of the request itself.

The middleware will extract values from each of these sources and convert them into .NET types ***(Binding)***

#### **Binding**
ASP.NET Core can bind two different targets in Razor Pages:
- **Method arguments**. If a page handler has method arguments, the values from the request are used to create the required parameters.
- **Properties marked with a `[BindProperty]` attribute**. Any properties marked with the attribute will be bound. *(By default, this attribute does nothing for GET requests.)*
  > ==Tip:== To bind properties for GET requests, use the `SupportsGet` property. For example: `[BindProperty(SupportsGet = true)]`

![[Pasted image 20230602184327.png]]
![[Pasted image 20230602184330.png]]

