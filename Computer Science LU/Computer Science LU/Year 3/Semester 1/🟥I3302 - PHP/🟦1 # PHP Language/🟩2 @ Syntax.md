_Previous:_ [[🟩1 @ What is PHP]]

---

When creating a `PHP` file, if its called `index.php` and open the project from Wamp, it will automatically open to this page. Second in priority comes `index.html`

# Tags
To start coding `PHP` in an `HTML` file _(or just a PHP file)_ your surround your code with `<?php` and `?>`
There are other tags to use PHP like: `<?...?>` or `<%...%>`

# Comments `//`, `/**/`, `#`
Do i even have to explain this?

# Displaying text with `echo`
```php
<?php
	echo "This text will be displayed on the browser";
?>
```
You can use the html tags in the text string to make things bold `<b></b>` for example
```php
<?php
	echo "I like'em <b>THICC</b>";
?>
```

---

# `$`Variables
Variables start with a `$` and the naming convention is no uppercases and using `_ (underscore)` for spaces.
You dont have to specify the variable type as well, _or even initialize them before use_.
To use a variable in a string you just write the name as it is **`including the dollar sign $`**
```php
<?php
	$i_like_tatos = 69;
	echo "That $i_like_taters is a funny numbah!";
	
	// You can also have an identifier as the value of a variable
	${$var} = 420;
	// For example
	$toto = "foobar";
	${$toto} = 2002;
	echo $foobar; // 2002
?>
```

The primitive variables types are:
- `integer`
- `double`
- `string`
- `array`
- `object`
- `boolean`

You can also `Typecast`  just as in C
```php
<?php
	? $str = "12";
	? $nbr = (int)$str; 
?>
```

## Arrays
```php
<?php
	$tab = array(2,54,2,87);
	$tab2 = [2, 54, 2, 87];
	echo "$tab[0]<br>";
	echo "$tab2[0]<br>";
?>
```

## Operators
All of these are the same as in C:
- Arithmetic operators
- Assignment operators  (like = or +=)
- Logical operators (&&, ||)
- Comparison operators
- Ternary operator

## Some useful functions for variables
- `empty($var)` : returns true if the variable is empty
- `isset($var)` : returns true if the variable exists
- `unset($var)` : destroys a variable
- `gettype($var)` : returns the type of the variable
- `settype($var, "type")` : converts the variable to type type (cast)
- `is_long(), is_double(), is_string(), is_array(), is_object(), is_bool(), is_float(), is_numeric(), is_integer(), is_int()`…


--- 

# Constants
Constants are defined as follows:
`define("var", value)`
They are case insensitive, so you can write them however you want when calling them.
```php
<?php
	define("a", "a string");
	echo a;
	define(A_var, 420);
	echo a_VaR;
?>
```

# Booleans
Its inconsistent as fuck
```php
<?php
	if(0)    // false
	if("")   // false
	if("0")  // false
	if("00") // TRUE , SEE WHAT I MEAN?!
	if('0')  // false
	if('00') // TRUE
	if(" ")  // TRUE
?>
```


# Strings
To concatenate strings you use the `.` dot operator. You can use it like this `.=` as well for assignment.

---

# Conditional Statements & Loops
Same as C
```php
<?php
	if("condition"){}
	else if("condiiton2"){}
	else{}
	
	for($i=0;$i<5;$i++){break;}
	while("condition"){break;}
	do{
	}while("condition");
?>
```

## Switch statements
Same as in C
```php
<?php
	switch($i){
		case "red":
			echo "The color is red";
	}
?>
```

---

# `Get` & `Post`
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

## `GET` VS `POST` (post wins)
- `GET`:
	- Cons: adds the name & values of the forum in the URL
	- Pros: I can send a variable to a page through the URL (like sending back data/errors to the page)
	![[Pasted image 20221212190250.png]]
- `POST`: no variables are added to the URL 
	![[Pasted image 20221212190307.png]]