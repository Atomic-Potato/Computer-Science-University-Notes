# MVC 
Razor pages use the MVC model.  In general, three components make up the MVC design pattern:
- `Model`—The data that needs to be displayed, the global state of the application.
> 	The service that the controller uses
- `View`—The template that displays the data provided by the model.
	> The `cshtml` file
- `Controller`—Updates the model and selects the appropriate view.
> 	The page model class.
>	The controller calls methods from the model to retrieve or update data in the Model. And finally it decides what it wants to show in the View


## Order of Events
![[Pasted image 20230602175151.png]]

## Applying the MVC design pattern to Razor Pages
ASP.NET Core also includes a framework called ASP.NET Core MVC.

This framework very closely mirrors the MVC design pattern, using controllers and action methods in place of Razor Pages and page handlers.

Razor Pages builds directly on top of the underlying ASP.NET Core MVC framework, using the MVC framework “under the hood” for their behavior.

You can avoid Razor Pages entirely, and work with the MVC framework directly in ASP.NET Core.

![[Pasted image 20230602175431.png]]

### Adding Razor pages
> This must be done after creating an **empty** project

1. Add the necessary Razor Page services in your `Startup.cs` file’s `ConfigureServices` method
   ![[Pasted image 20230602182849.png]]
2. Replace the existing basic endpoint configured in the `EndpointMiddleware` at the end of your middleware pipeline with the `MapRazorPages( )` extension method.
   ![[Pasted image 20230602182916.png]]
3. Create a new `Pages` folder in your project
4. Create a razor page 
   ![[Pasted image 20230602183010.png]]



# The View Model
**A view model is all the data required by the view to render a UI.**
It’s typically some transformation of the data contained in the application model, plus extra information required to render the page, for example the page’s title.

![[Pasted image 20230602180129.png]]

# A complete request
![[Pasted image 20230602180226.png]]

# Razor Pages vs MVC in ASP.NET Core
If you’re creating a **Web API** for working with mobile or client-side apps then you will almost certainly be using the MVC framework directly

## MVC controllers in ASP.NET Core
Instead of a `PageModel` and page handler, MVC uses a concept of **controllers** and **action methods**.

An action *(or action method)* is a method that runs in response to a request. An MVC controller is a class that contains a number of logically grouped action methods.

MVC controllers use explicit view models to pass data to a Razor view, rather than exposing the data as properties on itself *(as Razor Pages do with Page Models)*.

![[Pasted image 20230602183324.png]]

![[Pasted image 20230602183403.png]]
![[Pasted image 20230602183407.png]]

