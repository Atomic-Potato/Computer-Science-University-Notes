# Document Type Definition (DTD)
The first thing in an `HTML` file is declaring which version of `HTML` the webpage is gonna use. The DTD for HTML5 is:
```html
<!DOCTYPE html>
```
No need to close it 

# HTML element
The html element is used to indicate that the document is HTML formatted, its placed right below the DTD .
The language attribute specifies the spoken language of the document
```html
<!DOCTYPE html>
<html lang = "en">
</html>
```

# Head, title, meta and body elements
The `<head>` contains information that describes the webpage  document.
```html
<!DOCTYPE html>
<html lang = "en">
	<head>
		<tile>Page Title</title>
		<meta charset = "utf-8">
	</head>
</html>
```
The `<meta>` is the character encoding type and other stuff

The body section contains the actual tag, text, images... that are displayed in the page
```html
<body>
do your thing here
</body>
```

The heading `<h1> </h1>`... you know how it works, used in the `<body>`

# The `<p>`, `<br>`, `<blockquote>` elements
All of the following is contained in the `<body>`
- The paragraph `<p></p>` will create a paragraph with a space above it and below it
- The break line `<br>` will go down a line anywhere in the text in any element
- The `<blockquote></blockquote>` will create a paragraph with all of its lines has 1 tab space to the right

# Phrase elements
![[phrase elements.jpg | 600]]
Note these are not standalone elements.
The `sub` i think makes something to the base of like log_10.
The `sup` makes it to the power of
The `var` makes everything looks like a nice equation

# Lists
**Ordered List**
Displays the list with the defined attribute (numbers by default)
```html
<ol type = "1">
	<li></li>
</ol>
```
Attributes list
![[ordered list attributes.jpg]]

**Unordered List**
Displays the list with dots by default
```html
<ul>
	<li></li>
</ul>
```
same attribute assignment as above but google up what are they.

**Description List**
It means what it says
```html
<dl>
	<dt>Title of the description<\dt>
		<dd> The description<\dd>
	<\dt>
<\dl>
```
Example:
![[Example of description list.jpg]]

# Special characters
How to implement special chars in a paragraph 
![[special chars.jpg]]

# Structural Elements
### Div Element
The `<div><\div>` creates a new block with spaces above and below it that can be stylized with `<style>` that would be put in the div attributes `<div class="A Style">`
Example
![[example of div.jpg|300]]

### HTML5 structural elements
![[html 5 structural elements.jpg]]
![[visualized html5 elements.jpg]]

# Anchor element
The anchor element `<a href = ""><\a>` is used to specify a hyperlink / link to another web page or a file you want to display.
If you want to link another web page you have to include the whole url in `href`
```html
<a href = "http://www.google.com"> What appears to the user<\a>
```
For a local file in your page just include the file name
```html
<a href = "myFile.html"> My file <\a>
```
Email hyperlinks:
![[email hyperlinks.jpg]]

# HTML Validation
You can validate your code on:
http://validator.w3.org