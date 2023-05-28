- You can write `required` keyword in `<input>` to you know.
	```html
	<input type="text" name="username" required>
	```
- Calling a php function within the html will cause the page to reload, so all data will be lost
	```php
	<input type="text" name="randnum" value=<?php echo GenerateRandomNumber();?>>
	```
	Its better to call this function outside the html tags
	```php
	<?php
		// check if $random has been initialized before
	    if(isset($_POST["submit"]) && isset($_POST["randnum"])){
	        $random = $_POST["randnum"];
	    } else {
	        $random = mt_rand(1, 100);
	    }
	?>
	<html>
		<input type="text" name="randnum" value=<?php echo $random;?>>
	</html>
	```
	You should also to be safe check if the variable has a value using `isset()` before calling the function so it wouldnt change the original value if you want that.
- You should include the `value=""` in the `<input>` even if theres no initial value, otherwise PHP wont take your value
- Use `urlencode()`  to econde a URL so it changes the unsupported characters in the string before going to that URL _(usually done when you add variables to the URL)_. On the receiving side use `urldecode()` to return the URL to its original state if you have variables set in the URL.
- To use functions from another PHP file, use `require("php_file_with_functions.php")` at the start of the PHP file you want to use the functions in.

# SQL
- Remember to use `GROUP BY` if you wanna group the results of a column
	```sql
	SELECT name, product, sum(money_spent)
	GROUP BY sum(money_spent)
	-- because if you dont, all of the rows will be summed
	```