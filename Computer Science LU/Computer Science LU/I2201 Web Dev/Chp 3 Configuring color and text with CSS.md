# Configuring cascading style sheets
There are 3 ways to implement style with CSS:
![[cascading sheets.jpg | 500]]

# CSS selectors and declarations
Style sheets are composed of `style rules` and each rule has 2 parts:
- `Selector` that can be an HTML element, a class name, or and id name
- `Decleration` indicate the CSS property you are setting (like color) and the value you are assigning to the property

```html
selector{declerationProp : declerationValue}

// you can declare multiple ones at the same time with the ;
selector{prop1 : val1; prop2 : val2} 
```

# Some CSS properties
![[css props.jpg | 500]]
![[css props 2.jpg | 500]]

# Using color on web pages
There are multiple ways to input a color:
- `clor name`: p{color: red}
- `Hexadecimal color value`: p{color: #FF0000}
- `Decimal color value (RGB triplet)`: p{color: rgb(255, 0, 0)}

quick example:
```html
<h1 style="color: #cc0000"> <\h1>
```

# Embedded CSS with the style element
To apply styling to the whole web page we declare the `<style><\style>` section inside the `<head>` element and declare inside it all the styles want for each element like the `<body>` or `<p>` . Example:
```html
<head>
	<title>potato<\title>
	
	<style>
		body{prop1: val1; ...}
	<\style>
<\head>
```

# CSS class selector
We use the `class selector` when we need to apply CSS declaration to certain elements on a web page and not necessarily tie the style to a particular HTML element.
To create a class we put the element name in the `<style>` element and a dot `.` after it with a class name of our choice and afterwards `{}` containing our style choices.
The element name is not necessary you can just put a dot
```html
<style>
	p.className{prop1: val1; ...}
	or 
	.className{prop1: val1; ...}
<\style>

<body>
	<p class = "className"> <\p>
<\body>
```

# CSS Id selector
The `ID selector` is used to apply a CSS rule to `single` area in a web page. Its only applied once to a web page.
To declare it put a `#` in front of the id name (the name can contain numbers and underscores). Example:
```html
#feature {color: red}
```
to apply it you use it like an attribute 
```html
<div id="feature">
```

# Span element 
It is used to style individual words, example:
```html
<p>
	Some words in here <span class = "className"> Styled words <\span> rest of the paragraph
<\p>
```

# Using external style sheets
![[external style sheets.jpg | 500]]

**Link element**
the link element is used in the html file that we want to apply to, the css style sheet we created. We place it in the `<head>`
We have to attributes in the link element:
- `red` with a value `"stylesheet"`
- `href` with a value `"the name of the style sheet file"`

```html
<link rel="stylesheet" href="color.css">
```

# Center HTML elements with CSS
like doing so 
```html
#wrapper { 
width: 960px;
margin-left: auto;
margin-right: auto}
```
`auto` will take the size of the browser window and divide it by 2 or something

# The "Cascade"
![[cascade.jpg | 600]]

# Validation 
http://jigsaw.w3.org/cssvalidator