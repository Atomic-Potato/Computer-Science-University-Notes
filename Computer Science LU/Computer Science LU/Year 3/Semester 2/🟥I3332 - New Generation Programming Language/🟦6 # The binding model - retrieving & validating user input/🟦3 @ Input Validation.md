# Data Annotations
`DataAnnotations` provide `metadata` about your model by describing the sort of data the model should contain.

> ==**Definition:**== Metadata describes other data, specifying the rules and characteristics the data should adhere to.

Apply `DataAnnotations` attributes directly to your binding models properties to indicate the type of data that’s acceptable.

> *Example:*
> ![[Pasted image 20230610180846.png]]

Some `DataAnnotations` attributes:
- `[CreditCard]`—Validates that a property has a valid credit card format
- `[EmailAddress]`—Validates that a property has a valid email address format
- `[StringLength(max)]`—Validates that a string has at most the max amount of characters
- `[MinLength(min)]`—Validates that a collection has at least the min amount of items
- `[Phone]`—Validates that a property has a valid phone number format
- `[Range(min, max)]`—Validates that a property has a value between min and max
- `[RegularExpression(regex)]`—Validates that a property conforms to the regex regular expression pattern
- `[Url]`—Validates that a property has a valid URL format
- `[Required]`—Indicates the property that must be provided
- `[Compare]`—Allows you to confirm that two properties have the same value *(for example, Email and ConfirmEmail)*

**`DataAnnotations` are good for input validation of properties in isolation, but not so good for validating business rules.**

> you could use the popular FluentValidation library (https://github.com/JeremySkinner/FluentValidation) in place of the DataAnnotations attributes if you prefer.

# Validation on the Server Side
**Validation happens automatically but handling validation failures is the responsibility of the page handler method.**

The Razor Pages framework stores the output of the validation attempt in a property on the `PageModel` called `ModelState`.

This property is a `ModelStateDictionary` object, which contains a list of all the validation errors that occurred after model binding, as well as some utility properties for working with it.

![[Pasted image 20230610181422.png]]
![[Pasted image 20230610181426.png]]

## POST-REDIRECT-GET Pattern
![[199 - POST-REDIRECT-GET Pattern.png]]

# Validation on the Client Side
The alternative approach to validation is to perform client-side validation by running JavaScript. *(Default approach used in ASP.NET Core when you’re building a traditional web application.)*
![[Pasted image 20230610181812.png|600]]

With this approach, the user sees any errors with their form immediately, even before the request is sent to the server.
![[Pasted image 20230610181858.png]]