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