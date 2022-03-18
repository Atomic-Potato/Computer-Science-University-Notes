# Adding Javascript
You can use the script element
```html
<script>
<!-- JS here -->
</script>
```

# Events and Event Handlers
![[Pasted image 20220316143627.png ]]

# Variables
```js
var name = 69
```
Note: i think you can use variables in different script elements other than the original

# Functions
```js
function function_name()
{
	// js statements
}
```

# Form Handling 
Its better to do form validation in the client side because it will make less pressure on the server.

## `onsubmit` validation
the onsubmit returns a true or false value itself so we can create a validation function that returns true or false and then we return the returned value of that function to onsubmit
```html
<form method="post" action="URL" onsubmit="return ValidateForm();">
<!-- ... -->
</form>
```

## input box validation
we can access forms elements in the html file like an array or just access it by name instead
```js
document.forms[0].inputbox_name.value
```

# jQuery 
jQuery is an open source JS library used for many things, one of them is form validation.

## Adding jQuery to a page
- You can download the jQuery JavaScript library file and save it to your hard drive.
	-  http://jquery.com/download
	-  save the file with the name of jquery-3.2.1.min.js in your website folder.
	-  add the following script tag to the head section of your web page document `<script src="jquery-3.2.1.min.js"></script>`
- Or you can access a version of the jQuery JavaScript library file online through a Content Delivery Network (CDN)
	- add the following script tag in the head section of your web page document `<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>`

## Basics
**The ready Event:**
You need to inform the jQuery library when your web page’s Document Object Model (DOM) has been completely loaded by the browser. A jQuery statement referred to as the ready event is used for this purpose.

A jQuery statement consists of a jQuery alias, a selector, and a method.
```js
$(selector).method()
```
The selector indicates the DOM element(s) that jQuery <span style="color:blue;">will</span> work with.
The method is an action that jQuery can take.
`The ready() method indicates the code the browser should execute when the DOM is fully loaded.`

Example of the ready function
```js
$(document).ready(function()
{
	//js and other jQuery
})
```

## Selectors
A complete list of jQuery selectors is available at http://api.jquery.com/category/selectors.
![[Pasted image 20220316150133.png]]

## Methods
![[Pasted image 20220316150239.png]]

## Plugins
jQuery validation plugin (https://jqueryvalidation.org), which performs basic form validation.

A partial list of class names supported by the plugin for data validation is shown in the following table:
![[Pasted image 20220316152258.png | 600]]
these should be put in the `class="[insert]"` for it to validate the element

# Regular expressions (REGEX)
Syntax
```
/pattern/modifiers
```

## Functions
- The `search()` method uses an expression to search for a match, and returns the position of the match.
- The `test()` method searches a string for a pattern, and returns true or false, depending on the result.
- The` match()` method returns an array containing all of the matches, or null if no match is found.

## Modifiers
![[Pasted image 20220316152700.png | 700]]

## Patterns
![[Pasted image 20220316152755.png | 700]]

## Examples
<span style="color: green;">Email Addresses:</span> <span style="color: red;">/^\w+([.-]?\w+)*@\w+([.-]?\w+)*(\.\w{2,3})+$/</span>
```
1. The position anchors ^ and $ match the beginning and the ending of the input string, respectively.
2. \w+ matches 1 or more word characters (same as [a-zA-Z0-9_]+).
3. [.-]? matches an optional character . or -. Although dot (.) has special meaning in regex, in a
character class (square brackets) any characters except ^, -, ] or \ is a literal, and do not require
escape sequence.
4. ([.-]?\w+)* matches 0 or more occurrences of [.-]?\w+.
5. The sub-expression \w+([.-]?\w+)* is used to match the username in the email, before the @ sign.
It begins with at least one word character [a-zA-Z0-9_], followed by more word characters or . or -.
However, a . or - must follow by a word character [a-zA-Z0-9_].
6. The @ matches itself. In regex, all characters other than those having special meanings matches
itself, e.g., a matches a, b matches b, and etc.
7. Again, the sub-expression \w+([.-]?\w+)* is used to match the email domain name, with the same
pattern as the username described above
8. The sub-expression \.\w{2,3} matches a . followed by two or three word characters, e.g., ".com",
".edu", ".us", ".uk", ".co".
9. (\.\w{2,3})+ specifies that the above sub-expression could occur one or more times, e.g., ".com",
".co.uk", ".edu.sg" etc.
```
<span style="color: green;">Image Filenames:</span> <span style="color: red;"> /^\w+\.(gif|png|jpg|jpeg)$/i</span>
```
1. The position anchors ^ and $ match the beginning and the ending of the input string, respectively.
2. \w+ matches 1 or more word characters (same as [a-zA-Z0-9_]+).
3. \. matches the dot (.) character. We need to use \. to represent . as . has special meaning in regex.
The \ is known as the escape code, which restore the original literal meaning of the following
character. Similarly, *, +, ? (occurrence indicators), ^, $ (position anchors) have special meaning in
regex. You need to use an escape code to match with these characters.
4. (gif|png|jpg|jpeg) matches either "gif", "png", "jpg" or "jpeg". The | denotes "OR" operator. The
parentheses are used for grouping the selections.
5. The modifier i after the regex specifies case-insensitive matching. That is, it accepts "test.GIF" and
"TesT.Gif".
```