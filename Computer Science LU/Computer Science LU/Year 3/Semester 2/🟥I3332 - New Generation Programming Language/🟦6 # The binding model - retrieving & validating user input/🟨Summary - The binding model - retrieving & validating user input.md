*important bits are ==highlighted==*

---

- Razor Pages uses three distinct “models”, each responsible for a different aspect of a request. The binding models encapsulates data sent as part of a request. The application model represents the state of the application. The `PageModel` is the backing class for the Razor Page, and exposes the data used by the Razor view to generate a response.
- Model binding extracts values from a request and uses them to create .NET objects the page handler can use when they execute.
- ==Any properties on the `PageModel` marked with the `[BindProperty]` attribute, and method parameters of the page handlers, will take part in model binding.==
- ==Properties decorated with `[BindProperty]` are not bound for `GET` requests. To bind `GET` requests, you must use `[BindProperty(SupportsGet = true)] `instead.==
- ==By default, there are three binding sources:==
	- POSTed form values, 
	- route values, 
	- and the query string. 
	  The binder will interrogate these in order when trying to bind your binding models.
- ==When binding values to models, the names of the parameters and properties aren’t case sensitive.==
- You can bind to simple types or to the properties of complex types.
- ==To bind complex types, they must have a default constructor and public, settable properties.==
- Simple types must be convertible to strings to be bound automatically, for example numbers, dates, and Boolean values.
- ==Collections and dictionaries can be bound using the `[index]=value` and `[key]=value` syntax, respectively.==
- ==You can customize the binding source for a binding model using `[From*]` attributes applied to the method, such as `[FromHeader]` and `[FromBody]`. ==These can be used to bind to nondefault binding sources, such as headers or JSON body content.
- In contrast to the previous version of ASP.NET, the `[FromBody]` attribute is required when binding JSON properties (previously it was not required).
- Validation is necessary to check for security threats. Check that data is formatted correctly, confirm that it conforms to expected values and that it meets your business rules.
- ==ASP.NET Core provides `DataAnnotations` attributes to allow you to declaratively define the expected values.==
- ==Validation occurs automatically after model binding, but you must manually check the result of the validation and act accordingly in your page handler by interrogating the `ModelState` property.==
- Client-side validation provides a better user experience than server-side validation alone, but you should always use server-side validation.
- Client-side validation uses JavaScript and attributes applied to your HTML elements to validate form values.