When a server script communicates with a client, it must first send headers containing information about the upcoming document. 
You can choose to send other header lines with the PHP function: `header("Location: URL")`

To call the header() function, ensure that no line has been sent to the browser

Any display in document, even a line break or outside space to your script tags, causes the headers to be sent to the client.

If you intend to use the `header()` function in a script ensure that nothing precedes the PHP code that contains the function call and check used libraries.

Usage example:
```php
<?php
	$num_to_guess = 42;
	$num_tries = (isset($_POST[num_tries])) ? $_POST[num_tries] + 1 : 0;
	$message = "";
	
	if (!isset($_POST[guess])) {
		$message = "Welcome to the guessing machine!";
	}
	else{
		if ($_POST[guess] > $num_to_guess) {
			$message = "$_POST[guess] is too big! Try a smaller number";
		} 
		elseif ($_POST[guess] < $num_to_guess) {
			$message = "$_POST[guess] is too small! Try a larger number";
		} 
		else{ // must be equivalent
			header("Location: congrats.html");
			exit;
		}
	$guess = $_POST[guess];
}
?>
```