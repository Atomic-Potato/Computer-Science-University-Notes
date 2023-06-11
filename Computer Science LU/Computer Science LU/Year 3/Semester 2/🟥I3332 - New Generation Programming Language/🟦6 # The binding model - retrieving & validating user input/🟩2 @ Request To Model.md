# Binding Properties

Model binding extracts values from a request and uses them to create .NET objects.

These objects are passed as method parameters to the page handler being executed or are set as properties of the `PageModel` that are marked with the `[BindProperty]` attribute.

![[Pasted image 20230610170656.png]]
> **==Note:==** PageModel properties are not model bound for `GET` requests, even if you add the `[BindProperty]` attribute.
> For security reasons, only requests using verbs like `POST` and `PUT` are bound.
> If you do want to bind `GET` requests, then you can set the `SupportsGet` property on the `[BindProperty]` attribute to opt-in to model binding.

## Binding Complex Types
It's recommended that you place all your bound properties inside an inner class and bind that class.
![[Pasted image 20230610170945.png]]

## Binding Collections & Dictionaries
To achieve this, you could create a page handler that accepts a `List<string>` type such as:
```cs
public void OnPost(List<string> currencies);
```

You could then POST data to this method by providing values in several different formats:
- currencies[index]—Where currencies is the name of the parameter to bind and index is the index of the item to bind, *for example,  `currencies[0]=GBR&currencies[1]=USD`.*
- `[index]`—If you’re only binding to a single list (as in this example), you can omit the name of the parameter, *for example, `[0]=GBR&[1]=USD`.*
- `currencies`—Alternatively, you can omit the index and send currencies as the key for every value, *for example, `currencies=GBR&currencies=USD`.*

The key values can come from route values and query values, but it’s far more common to `POST` them in a form.

Dictionaries can use similar binding, where the dictionary key replaces the index both when the parameter is named and when it’s omitted.

If this all seems a bit confusing, don’t feel too alarmed. If you’re building a traditional web application, and using Razor views to generate HTML, then it will take care of most of the naming for you.

## Binding File Uploads With `IFormFile`
```c# 
public void OnPost(IFormFile file);
public void OnPost(IEnumerable file);
```
![[Pasted image 20230610175948.png|400]]

When your method accepts an `IFormFile` instance, the whole content of the file is buffered in memory and on disk before you receive it.
You can then use the `OpenReadStream` method to read the data out.


## Properties Vs. Handler Parameters
![[Pasted image 20230610171239.png]]

## Default Values
If none of the binding sources contain the required value, then the method parameter receives a new instance of the type instead.

For value types, the value will be default (T).
- For an `int` parameter this would be `0`, and for a `bool` it would be `false`.
- For reference types, the type is created using the default constructor.
	- For custom types like `ProductModel`, that will create a new object.
	- For nullable types like `int?` or `bool?`, the value will be `null`.
- For string types, the value will be null.

# Binding Sources
By default, ASP.Net Core uses three different binding sources when creating binding models. It looks through each of these in order and will take the first value it finds (if any) that matches the name of the binding model:
- `Form values` —Sent in the body of an HTTP request when a form is sent to the server using a POST.
- `Route values` —Obtained from URL segments or through default values after matching a route.
- `Query string values` —Passed at the end of the URL, not used during routing.

Each of these binding sources store values as name-value pairs
![[Pasted image 20230610171120.png]]

## Duplicate data from multiple sources
By default, form values will take precedence over other binding sources, including route values!
![[Pasted image 20230610171656.png]]

> ==**Note:**== The default model binder isn’t case sensitive, so a binding value of QTY=50 will happily bind to the qty parameter.


## Choosing a Binding Source
Decorate your page handler method parameters *(or binding model class properties)* with attributes that say where to bind from.
![[Pasted image 20230610180116.png]]

There are several source binding attributes:
- `[FromHeader]`—Bind to a header value
- `[FromQuery]`—Bind to a query string value
- `[FromRoute]`—Bind to route parameters
- `[FromForm]`—Bind to form data posted in the body of the request
- `[FromBody]`—Bind to the request’s body content
- `[BindNever]`—The model binder will skip this parameter completely.
- `[BindRequired]`—If the parameter was not provided, or was empty, the binder will add a validation error.
- `[FromServices]`—Used to indicate the parameter should be provided using dependency injection.

You can apply each attribute to any number of method parameters. **BUT only one parameter may be decorated with the `[FromBody]` attribute.**
`[FromBody]` and `[FromForm]` attributes are effectively mutually exclusive.

