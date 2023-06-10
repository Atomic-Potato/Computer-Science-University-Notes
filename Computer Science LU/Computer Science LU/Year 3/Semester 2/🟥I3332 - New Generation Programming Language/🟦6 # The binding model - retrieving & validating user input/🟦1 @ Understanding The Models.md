The classic MVC design pattern has three independent components:
- `Controller`—Calls methods on the model and selects a view.
- `View`—Displays a representation of data that makes up the model.
- `Model`—The data to display and the methods for updating itself.

In this representation, there’s only one model, which represents all the business logic for the application as well as how to update and modify its internal state.

# Binding Model
Binding models in Razor Pages are typically defined by
- creating a public property on the page’s `PageModel` and decorating it with the `[BindProperty]` attribute.
- They can also be passed to a page handler as parameters.

# Application Model
This is typically a whole group of different services and classes *(anything needed to perform some sort of business action in your application.)*

It may include the `domain model` *(which represents the thing your app is trying to describe)* and `database models` *(which represent the data stored in a database)*, as well as any other additional services.

# Page Model
`PageModel` of a Razor Page
1. acts as the controller for the application by exposing page handler methods
2. acts as the view model for a Razor view.

All the data required for the view to generate a response is exposed on the PageModel.

# Example
- [[#Binding model]]—Would take the {query} route parameter from the URL and any values posted in the request body, and bind them to a C# class, which typically acts as a “throwaway” data transport class.
  This would be set as a property on the PageModel when the page handler is invoked.
- [[#Application Model]] : The services and classes that perform the logic.
- [[#Page model]]: The values provided by the application model would be set as properties on the Razor Page’s PageModel
  The Razor view would use this data to render the Razor view to HTML.