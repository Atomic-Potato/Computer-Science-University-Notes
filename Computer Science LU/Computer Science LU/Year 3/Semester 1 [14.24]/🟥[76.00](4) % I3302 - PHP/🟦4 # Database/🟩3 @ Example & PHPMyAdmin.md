_Previous [[🟩2 @ Using MySQLi]]_

---

# PHPMyAdmin
PHPMyAdmin is a software to manage databases.

# Example
```php
//variables
$searchtype=$_POST['searchtype'];
$searchterm=trim($_POST['searchterm']);
//connect to database
$db = new mysqli("localhost", "username", "password", "database");
if($db->connect_errno){
	echo "Error: Coudn't connect to database";
	exit;
}

//prepare & bind query
$query = "SELECT ISBN, Author, Title, Price FROM Books WHERE $searchtype = ?";
$stmt = $db->prepare($query);
$stmt->bind_param('s', $searchterm);
$stmt->execute();

//get result & bind result to variables
$stmt->store_result();
$stmt->bind_result($isbn, $author, $title, $price);
echo "<p>Number of books found: " . $stmt->num_rows() . "</p>";

//print result for each row
while($stmt->fetch()){
	echo "<p><strong>Title: " . $title . "</strong><br>Author: " . $author;
	echo "<br> ISBN: " . $isbn . "<br>Price: " . number_format($price, 2) . "</p>";
}

//free result from $stmt
$stmt->free_result();
```

---
_Previous [[🟩2 @ Using MySQLi]]_
