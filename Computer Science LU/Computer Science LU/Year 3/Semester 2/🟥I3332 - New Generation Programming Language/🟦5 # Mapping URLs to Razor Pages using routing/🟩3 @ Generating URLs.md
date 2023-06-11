# Generating URLs from route parameters
![[Pasted image 20230606121559.png]]

# Generating URLs for a Razor Page
The following listing shows how you could generate a link to the *Pages/Currency/View.cshtml* Razor Page, using the `Url` helper from the `PageModel` base class.

![[Pasted image 20230606130008.png]]
![[Pasted image 20230606130018.png]]

The `Url` property is an instance of `IUrlHelper` that allows you to easily generate URLs for
your application by referencing other Razor Pages by their file path. It exposes a Page method
to which you pass the name of the Razor Page and any additional route data. The route data is
packaged as key-value pairs into a single C# anonymous object. If you need to pass more
than one route value, you can add additional properties to the anonymous object. The helper
will then generate a URL based on the referenced page’s route template.

# Generating URLs for an MVC controller
![[Pasted image 20230606131349.png]]
![[Pasted image 20230606131353.png]]

# Generating URLs with `ActionResults`
More commonly, you want to **automatically redirect a user to a URL**. For that situation you can use an `ActionResult` to handle the URL generation instead.

![[Pasted image 20230606131423.png]]
