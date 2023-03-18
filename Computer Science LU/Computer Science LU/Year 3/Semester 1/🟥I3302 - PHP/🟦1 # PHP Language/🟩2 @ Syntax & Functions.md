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

Alternatively you can use `print_r($result)` which prints variables in a more human-readable way _(don’t use it for global variables, it will loop infinitely)_

**_Note:_** We can echo html tags as you saw earlier 

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
	
	$tab[] = "Name" // pushes Name at the end of the array
?>
```

Some functions:
- `implode($str,$tab)` : returns a string containing all values in _\$tab_ separated with _\$str_
- `explode($delim,$str)` : returns an array of strings with separator _\$delim_
-  `shuffle($tab)` 

## Associative Arrays
Exactly like a dictionary in python
```php
<?php 
	$person = array("Name"=> "Jana" , "Family"=>"Al Sabeh");
	$person["Name"]; //returns Jana
	$person["Family"]; //returns Al Sabeh
	
	// This isnt my name btw, im just copying this girls notes heh, so credits to her
?>
```

You can loop through this array like so
```php
<?php
	foreach($person as $elem){/* $elem represents the value (not keys) */}
	foreach($person as $key =>$elem){/* Access both key and value */}
?>
```

Some functions:
`Array_count_values($tab)` : returns an associative array containing the values of _\$tab_ as keys and their frequencies as values _(useful to check redundancy)_

## Operators
All of these are the same as in C:
- Arithmetic operators
- Assignment operators  (like = or +=)
- Logical operators (&&, ||)
- Comparison operators
- Ternary operator
- `===` compares values & types


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
	// well it actually makes sense now that i look at it again
?>
```


# Strings
To concatenate strings you use the `.` dot operator. You can use it like this `.=` as well for assignment.

Some of the string functions:
- `strlen($str)`
- `strtolower($str)` 
- `strtoupper($str)` 
- `trim($str)` : removes extra spaces at the beginning & end of a string
- `substr($str,$i, $j) `
- `strcmp($str1,$str2)` 
	- 0 if $str1 == $str2
	- <0 if $str1 < $str2
	- \>0 if $str1 \> $str2
- `strpos($str, $val, [ $start]  )` : returns the first index of the _\$val_ (can be a string or a character) in _\$str_. _\$start_ is optional, it specifies where the index to begin the search. If it is negative, it searches from the end of the string
- `addslashes($str)` : _(used mainly in forms)_ this function returns a new string with added / before the special characters (like “ or ‘ or \\) so that they don’t cause any unintentional effect
- `ord($char)` : returns the ASCII value of the char

# Number Formatting
```php
<?php number_format ($nbr ,[$dec, $a, $b])) ?> 
// dec,$a, and $b are optional
// $dec: number of values after the decimal point
// $a: character to separate the integer part and decimal part (default is . )
// $b: character that separates the thousands in the integer part (default is , )
```

_Example:_
![[Pasted image 20230123090723.png|400]]
---

# Conditional Statements & Loops
Same as C
```php
<?php
	if("condition"){}
	else if("condiiton2"){}
	else{}
	
	for($i=0;$i<5;$i++){break;}
	foreach($array as $element){break;}
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

# Functions
```php
<?php
	function someFunction($parameter){
		echo "Some function with parameter: $parameter<br>";
		return 1;
	}
?>
```

Note that we dont need to specify the arguments type nor the return type. 
Also calling the function is case insensitive. So _someFunction()_ is the same as _Some Function()_ 

---

