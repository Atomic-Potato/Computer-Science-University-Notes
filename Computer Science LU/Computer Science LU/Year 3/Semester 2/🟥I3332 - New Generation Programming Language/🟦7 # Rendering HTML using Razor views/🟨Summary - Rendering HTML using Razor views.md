*important bits are ==highlighted==*

---

- In the MVC design pattern, views are responsible for generating the UI for your application.
- Razor is a templating language that allows you to generate dynamic HTML using a mixture of HTML and C#.
- HTML forms are the standard approach for sending data from the browser to the server. You can use Tag Helpers to easily generate these forms. 
- ==Razor Pages can pass strongly-typed data to a Razor view by setting public properties on the `PageModel`. To access the properties on the view model, the view should declare the model type using the `@model` directive.==
- ==Page handlers can pass key-value pairs to the view using the `ViewData` dictionary.==
- ==Razor expressions render C# values to the HTML output using `@` or `@()`. **You don’t need to include a semicolon after the statement when using Razor expressions.**==
- ==Razor code blocks, defined using `@{}`, execute C# without outputting HTML. **The C# in Razor code blocks must be complete statements, so it must include semicolons.**==
- Loops and conditionals can be used to easily generate dynamic HTML in templates, but it’s a good idea to limit the number of if statements in particular, to keep your views easy to read. 
- ==If you need to render a string as raw HTML you can use `Html.Raw`, but do so sparingly—rendering raw user input can create a security vulnerability in your application.==
- Tag Helpers allow you to bind your data model to HTML elements, making it easier to generate dynamic HTML while staying editor friendly.
- ==You can place HTML common to multiple views in a layout. The layout will render any content from the child view at the location `@RenderBody` is called.==
- ==Encapsulate commonly used snippets of Razor code in a partial view. A partial view can be rendered using the ``<partial />`` tag.==
- ==`_ViewImports.cshtml` can be used to include common directives, such as `@using` statements, in every view.==
- ==`_ViewStart.cshtml` is called before the execution of each Razor Page and can be used to execute code common to all Razor Pages, such as setting a default layout page. It doesn’t execute for layouts or partial views.==
- ==`_ViewImports.cshtml `and `_ViewStart.cshtml` are hierarchical—files in the root folder execute first, followed by files in controller-specific view folders.==
- Controllers can invoke a Razor view by returning a `ViewResult`. This may contain the name of the view to render and optionally a view model object to use when rendering the view. If the view name is not provided, a view is chosen using conventions.
- By convention, MVC Razor views are named the same as the action method that invokes them. They reside either in a folder with the same name as the action method’s controller or in the Shared folder.
