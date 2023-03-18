_Previous_ [[🟩2 @ Cookies]]

---

# What Are Sessions
Support for PHP sessions is a way to preserve data between multiple accesses. This allows you to create custom applications, and increase the appeal of your site.

Each visitor accessing your web page is assigned a unique identifier, called "session identifier". It can be stored either in a cookie or propagated in the URL.

Session support allows you to store data between queries in the `$_SESSION` super-global array.

# Sessions vs. Cookies
`Sessions`
- Generally more secure
- Able to store more data
- Can be used without cookies

`Cookies`
- Easier to program
- Require less of the server
- Can be set to last longer

# Using Sessions
PHP supports two functions that enable you to retain data between forms:

## `session_start()`
either starts a new session or resumes one if a session exists. 
It runs at the beginning of the script _(before HTML display itself)_
By default creates a unique session ID stored as a cookie.

_Example:_
```php
<?php session_start(); ?>
<html>
...
</html>
```

## `session_register()`

registers one or more variables as session variables
```php
name = 'Matthew';
$preference = 'Soccer Equipment';
session_register('name', 'preference');
```

this function can be replaced by a direct access to the global associative
array `$_SESSION`

 _example:_
```php
$name = 'Matthew';
$preference = 'Soccer Equipment';
$_SESSION['name'] = $name;
$_SESSION['preference'] = $preference;
```
---

To destroy a session use `session_destroy()`
To name a sessions use `session_name()` before `session_start()` _(if you want to access the same session from another file, then just do the same thing)_

When a visitor visits your site, PHP will automatically check _(if `session.auto_start` is enabled)_ or on request _(explicitly with `session_start()` or implicitly with `session_register ()`)_ if there is a session with the same name. 
If this is the case, the previously saved environment will be recreated.

# Example
```php
<?php
	session_start() ;
	$sample=$_SESSION['sample_hidden'];
	$product=$_POST['product'];
	$quantity=$_POST['quantity'];
?>
<html><head><title> Order Product 2 </title> </head>
<body>
	<form action="sessions3order.php " method="post">
	<?php
		echo "<font color=blue size=4> Sample hidden=$sample</font>";
		echo "<br>You selected product=$product and quantity=$quantity";
		$_SESSION['product'] = $product;
		$_SESSION['quantity'] = $quantity;
		echo '<br>Please enter your name';
		echo '<input text type="text" name="name">';
		echo ' and Billing Code: (5 digits)';
		echo '<input text type="text" name="code">';
		echo '<br> <input type=submit value="Process Order">';
		echo '<input type=reset>';
		echo '</form></body></html>'; 
	?>
```

---
_Previous_ [[🟩2 @ Cookies]]
