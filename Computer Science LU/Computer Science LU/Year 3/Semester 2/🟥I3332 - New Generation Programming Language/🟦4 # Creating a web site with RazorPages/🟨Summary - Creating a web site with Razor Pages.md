important bits are ==highlighted==

---

- The MVC design pattern allows for a separation of concerns between the business logic of your application, the data that’s passed around, and the display of data in a response.
- Razor Pages are built on the ASP.NET Core MVC framework and use many of the same primitives. They use conventions and a different project layout to optimize for page-based scenarios. 
- MVC controllers contain multiple action methods, typically grouped around a high-level entity. Razor Pages groups all the page handlers for a single page in one place, grouping around a page/feature instead of an entity. 
- ==Each Razor Page is equivalent to a mini controller focused on a single page, and each Razor Page handler corresponds to a separate action method.==
- ==Razor Pages should inherit from the PageModel base class.==
- ==A single Razor Page handler is selected based on the incoming request’s URL, the HTTP verb, and the request’s query string, in a process called **routing**.==
- ==Page handlers should generally delegate to services to handle the business logic required by a request, instead of performing the changes themselves. This ensures a clean separation of concerns that aids testing and improves application structure.==
- ==Page handlers can have parameters whose values are taken from properties of the incoming request in a process called **model binding**. Properties decorated with `[BindProperty]` can also be bound to the request.==
- ==By default, properties decorated with `[BindProperty]` are not bound for `GET` requests. To enable binding, use `[BindProperty(SupportsGet = true)]`.==
- ==Page Handlers can return a `PageResult` or `void` to generate an HTML response.==
- ==You can send users to a new Razor Page using a `RedirectToPageResult`.==
- ==The `PageModel` base class exposes many helper methods for creating an `ActionResult`.==