`Get` and `Post` are used to send data to other pages (either though a form or a link).

Take this form for example:
```html
<form action = "ActionPage.php" method = "get/post"> // For the method only use either get or post
	Name: <input type ="text" name="username">       // This is just for example sake
	Email: <input type="text" name="email">
	<input type="submit" name="submit" value="send">
</form>
```
<form action = "ActionPage.php" method = "get/post">
	Name: <input type ="text" name="username">
	Email: <input type="text" name="email">
	<input type="submit" name="submit" value="send">
</form>

First thing, when the player (i mean user, too much game dev) presses the submit button. **He will be taken to the page specified in the `action` attribute.**

Now because we specified `get` or `post` in the `method` attribute. Each value for an `<input>` tag with a `name` attribute will be sent to the `action` page in the form of a _dictionary like in python_ **where the key is the `name` and the value is well... the value of the input.** 

To access the data in this dictionary we use the specified `method` as the dictionary name.
```php
<?php
	// if we used the get method
	$_GET["key_name"] // remember the key_name is the name of the <input> tag
	// if we used the post method
	$_POST["key_name"]
?>
```

It's also quite **IMPORTANT** to check if the values were sent by using the `isset()` function on submit button dictionary key (`"submit"` in this case) before trying to access them.
```php
<?php
	if(isset($_GET["submit"]))
?>
```

**_Note:_** to send data from the form to a php tag in the current html, we place this inside the `action`:
```php
<form action=<?php echo $_SERVER["PHP_SELF"]?>>
```
This variable is equivalent to the name of the current script and the action indicates that the script is reloading itself.

# `GET` VS `POST` (post wins)
- `GET`:
	- Cons: adds the name & values of the forum in the URL
	- Pros: I can send a variable to a page through the URL (like sending back data/errors to the page)
	![[Pasted image 20221212190250.png]]
- `POST`: no variables are added to the URL 
	![[Pasted image 20221212190307.png]]

# Multiple values
Some fields allow the entry of several values under the same name _(like checkboxes)_. The name of the input will be an array, and you can access these values as an array in the PHP
```php
<input type="checkbox" name="choice[]" value="blue">Blue<br>
<input type="checkbox" name="choice[]" value="white" > White<br>

<?php
	echo $_POST['choice'][0];
?>
```