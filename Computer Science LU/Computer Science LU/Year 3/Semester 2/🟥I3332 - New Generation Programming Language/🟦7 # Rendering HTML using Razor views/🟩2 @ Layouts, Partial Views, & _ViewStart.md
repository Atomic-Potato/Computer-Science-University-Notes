# Layouts
A layout in Razor is a template that includes common code.
It can’t be rendered directly, but it can be rendered in conjunction with normal Razor views.

Layout files are normal Razor templates that contain markup common to more than one page.

An ASP.NET Core app can have multiple layouts, and layouts can reference other layouts.
You’ll often use layouts across many different page handlers, so **they’re typically placed in the `Views/Shared` folder.**

You can name them anything you like, **but there’s a common convention to use `_Layout.cshtml` as the filename for the base layout in your application.**

A layout file looks similar to a normal Razor template, with one exception: every layout must call the `@RenderBody( )` function.
This tells the templating engine where to insert the content from the child views.
![[228 - Example layout and RenderBody.png]]

![[Pasted image 20230611185527.png]]

## Sections
![[229 - Sections.png]]

![[230 - Rendering a section.png]]
![[230 - Nesting layouts.png]]

# Partial Views

![[232 - partial views.png]]

> **Like [[#Layouts]], the convention for naming views starts with an underscores**

When you render a partial view without providing an absolute path or file extension the framework tries to locate the view by searching the Pages folder, starting from the Razor Page that invoked it.

# Running code on every view with `_ViewStart` and `_ViewImports`

![[234 - importing common directives with _ViewImports.png]]
You can easily run common code at the start of every view by adding a `_ViewStart` file to the Views folder in your application.
*This file can contain any Razor code, but it’s typically used to set the Layout for all the views in your application.*
Any code in the `_ViewStart.cshtml` file **runs before the view executes.**
`_ViewStart.cshtml` only runs for full views—**it doesn’t run for layouts or partials views.**



![[234 - running code for every view with _ViewStart.png]]

![[235 - naming these things is enforced.png]]

# AJAX
![[Pasted image 20230611190442.png]]

