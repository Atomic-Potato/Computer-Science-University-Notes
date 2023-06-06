Route templates define the structure of known URLs in your application. They’re strings with placeholders for variables that can contain optional values.

For each route template, you can define:
- Specific, expected strings
- Variable segments of the URL
- Optional segments of a URL
- Default values when an optional segment isn’t provided
- Constraints on segments of a URL, for example, ensuring that it’s numeric

# Routing to Razor Pages
Razor Pages uses [[#Convention-based VS. Attribute Routing|attribute routing]] by creating route templates based on conventions.

For every Razor Page in your application, the framework uses the path of the Razor Page file relative to the Razor Pages root directory *(Pages/)*, excluding the file extension *(cshtml)*.

# Customizing Razor Page route templates
A segment is typically separated by the `/` character, but it can be any valid character.

Each segment is either:
- A literal value: must be matched exactly *(ignoring case)* by the request URL
- A route parameter: may vary, but will still be a match for the template.

![[Pasted image 20230606120048.png|400]]
When a route template defines a route parameter, and the route matches a URL, the value associated with the parameter is captured and stored in a dictionary of values associated with the request.
These route values typically drive other behavior in the Razor Page, such as model binding.

## Adding Segments
To add an additional segment to a Razor Page’s route template, add a space followed by the desired route template, after the `@page` statement.
```c
@page "{category}/{name}"

// This would give a final route template of Products/{category}/{name} which would match all of the following URLs:
// /products/bags/white-rucksack
// /products/shoes/black-size9
```

To specify a custom route for a Razor Page, prefix the route with `/` in the `@page` directive.
```c
@page "/{category}/{name}"
```

Similarly, you can create a *"static"* custom template for a page by starting the template with a `/` and using only literal segments. For example:
```c
@page "/checkout"
```

## Optional and default values
You can specify any number of route parameters in your templates, and these values will be available to you when it comes to model binding
![[Pasted image 20230606120959.png]]

> Examples:
> ![[Pasted image 20230606121017.png]]

## Constraints
You can apply a large number of route constraints to route templates to ensure that route values are convertible to appropriate types. *(complete list online at http://mng.bz/U11Q.)*
![[Pasted image 20230606121151.png]]

## Matching arbitrary URLs with the `catch-all` parameter
Catch-all parameters can be declared using either one or two asterisks inside the parameter definition, like `{\*others}` or `{\*\*others}` .

![[Pasted image 20230606121436.png|500]]

These will match the remaining unmatched portion of a URL, including any slashes or other characters that aren’t part of earlier parameters.
They can also match an empty string.
