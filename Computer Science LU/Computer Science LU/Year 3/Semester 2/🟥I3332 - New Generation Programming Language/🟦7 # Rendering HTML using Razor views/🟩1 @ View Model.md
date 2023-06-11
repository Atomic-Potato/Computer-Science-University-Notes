The view model is a custom class that contains all the data required to render a view. *(defined as properties in PageModel)*

![[Pasted image 20230611180744.png]]

![[Pasted image 20230611180751.png]]
![[Pasted image 20230611180756.png]]

# Passing Data to Views
In ASP.NET Core, you have several ways of passing data from a page handler in a Razor Page to its view :
- `PageModel properties`—You should generally expose any data that needs to be displayed as properties on your `PageModel`. Any data which is specific to the associated Razor view should be exposed this way.
- `ViewData`—This is a dictionary of objects with string keys that can be used to pass arbitrary data from the page handler to the view.
  In addition, it allows you to pass data to `_layout` files, This is the main reason for using `ViewData` instead of setting properties on the `PageModel`.
- `ViewBag` :  ViewBag.TotalStudents = 3; @ViewBag.TotalStudents
- `HttpContext`—Technically the `HttpContext` object is available in both the page handler and Razor view, so you could use it to transfer data between them


**Next `@model` directive at the top of your Razor view describes which Type of `PageModel` is associated with a given Razor Page.
You can access the `PageModel` instance itself from the Razor view using the `Model` property.**

## ViewData using attributes 
![[Pasted image 20230611181806.png]]

# Using C# in Razor Templates
![[Pasted image 20230611181833.png]]
![[Pasted image 20230611181950.png]]

# Conditionals & Loops
![[Pasted image 20230611182038.png]]

# Rendering HTML With Raw()
What if the task variable contains HTML you want to display?
It contains `"<strong>Check oil</strong>"`?  then you might hope to get this:
```html
<li><strong>Check oil</strong></li>
```
But that’s not the case. The HTML generated comes out like this:
```html
<li>&lt;strong&gt;Check oil&lt;/strong&gt;</li>
```

If you really need to write the variable out to the HTML stream, then you can do so using the Html property on the view page and calling the Raw method:
```cshtml
<li>@Html.Raw(task)</li>
```

>==**WARNING:**== Doing this should be avoided since its a security risk.

