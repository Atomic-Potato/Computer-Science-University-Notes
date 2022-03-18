![[Pasted image 20220315174953.png]]

# Form Element
The `<form></form>` element is used when we want to take input from user. We cannot nest form elements.

The form element can be configured with attributes that specify which server-side program or file will process the form, how the form information will be sent to the server, and the name of the form.
![[Pasted image 20220315171336.png | 800]]
![[Pasted image 20220315171535.png | 800]]
```html
<form name="order" method="post" id="order“ action="demo.php">
<!--. . . form controls go here . . . -->
</form>
```

Note that the query string (name/value pairs) is sent in the URL of a GET request:
![[Pasted image 20220315171853.png]]

The data sent to the server with POST is stored in the request body of the HTTP request:
![[Pasted image 20220315171923.png]]

# Input Element
The input element is a stand-alone, or void, tag that is used to configure several different types of form controls. The input element is not coded as a pair of opening and closing tags. Use the type attribute to specify the type of form control that the browser should display.

## Text box
```html
<input type="text" name="email" id="email" required="required“ size= =“30" >
```
<input type="text" name="email" id="email" required="required“ size= =“30" >

## Submit button
The submit button form control is used to submit the form. When clicked, it triggers the action method on the form element and causes the browser to send the form data to the web server. The web server will invoke the server-side processing program or script listed on the form’s action property.
```html
<input type="submit" value="Whats written in the button">
```
<input type="submit">

## Reset button
The reset button form control is used to reset the form fields to their initial - values. A reset button does not submit the form.
```html
<input type="reset">
```
<input type="reset">

## Check Box
The check box form control allows the user to select one or more of a group of predetermined items.
```html
<input type="checkbox">
```
![[Pasted image 20220315172754.png | 800]]

## Radio Button
The radio button form control allows the user to select `exactly one choice` from a group of predetermined items. `Each radio button in a group is given the same name attribute` and a unique value attribute. Because the name attribute is the same, the elements are identified as part of a group by the browsers and only one may be selected.
![[Pasted image 20220315173013.png | 800]]

## Password Box
The password box form control is similar to the text box, but it is used to accept information that must be hidden as it is entered, such as a password. The actual characters typed are sent to the server and the information is not really secret or hidden.
```html
<input type="password" name="pword" id="pword">
```
<input type="password" name="pword" id="pword">

# Scrolling Text Box
## Textarea Element
The scrolling text box form control accepts free-form comments, questions, or descriptions. The `<textarea></textarea>` element configures a scrolling text box. Text contained between the tags will display in the scrolling text box area.
![[Pasted image 20220315173622.png | 800]]
```html
<textarea name="comments" id="comments" cols="40" rows="2"> 
```
<textarea name="comments" id="comments" cols="40" rows="2"> Enter Comments</textarea>

# Select List
A select list is configured with one select element and multiple option elements. `<select></select>`
![[Pasted image 20220315174021.png | 800]]

## Option Element
The option element contains and configures an option item displayed in the select list form control. `<option></option>`
![[Pasted image 20220315174133.png | 800]]

# Image Button
When an image button is clicked or tapped, the form is submitted.
```html
<input type="image" src="login.gif" alt="Login Button">
```

# Label Element
The label element is a container tag that associates a text description with a form control. `<label></label>`
```html
<label for="email">E-mail: </label>
```
<label for="email">E-mail: </label>
<input type="text" id="email">
`Its important to set the 'for' equal to the id of the input for screen reader apps to relate the label to the input element`

# Fieldset and Legend Elements
Just makes things cool by making border go around text. `<fliedset></fieldset>`
The legend element provides a text description for the fieldset grouping. `<legend></legend>`
![[Pasted image 20220315174908.png]]

# E-mail Address Inpit
```html
<input type="email">
```
Its purpose is to accept information that must be in e-mail format, such as “Abed.safadi@ul.edu.lb”
Only browsers that support the HTML5 email attribute value will verify the format of the information.

# URL Input
```html
<input type="url">
```
It is intended to accept any valid type of URL or URI, such as “http://www.google.com”. Same as above in terms of support

# Telephone number Input
 Its purpose is to accept a telephone number.
 ```html
 <input type="tel">
 ```

# Datalist Form Control
The datalist form control offers a convenient way to offer choices yet provide for
flexibility on a form. The datalist is configured using three elements: an input
element, the datalist element, and one or more option elements. Only browsers that
support the HTML5 datalist element will display and process the datalist items.
![[Pasted image 20220315175505.png | 800]]

# Calendar
![[Pasted image 20220315175539.png | 800]]

# Color-well form control
![[Pasted image 20220315175618.png | 800]]
