Tag Helpers are used to
- Automatically populate the values from the `PageModel` property.
- Choose the correct id and name, so that when the form is `POST`ed back to the Razor Page, the property will be model bound correctly.
- Choose the correct input type to display.
- Display any validation errors.
- generate HTML markup based on properties of your `PageModel`,
- creating the correct id and name attributes of the element
- setting the value of the element to the model property’s value

![[Pasted image 20230612200647.png]]

The `DataAnnotations` used in the binding model will dictate what the tag helpers will do.
![[Pasted image 20230612200808.png]]
![[Pasted image 20230612200811.png]]
![[Pasted image 20230612200910.png]]

this code will generate all of this HTML for us, thanks to the tag helpers
![[Pasted image 20230612200956.png]]


