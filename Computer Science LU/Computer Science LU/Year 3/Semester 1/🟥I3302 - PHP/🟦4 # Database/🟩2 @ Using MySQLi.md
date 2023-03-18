_Next [[🟩3 @ Example & PHPMyAdmin]]_
_Previous [[🟩1 @ Database]]_

---

In any script used to access a database from the Web, you follow some basic steps:
1. Check and filter data coming from the user.
2. Set up a connection to the appropriate database.
3. Query the database.
4. Retrieve the results.
5. Present the results back to the user.

---

There are 3 ways to use MySQLi

# Procedural
By using  methods to **connect, fetch, execute** ...
```php
// connect to database
// This function returns a resource rather than an object
$db = mysqli_connect("localhost", "user", "password", "database");

// Checking for connection errors
// This function returns an error number on error, or zero on success
if(mysqli_connect_errno()){ 
	echo "<p>Error: Couldn't connect to the database</p>";
	exit;
}

// Getting the result of a query
$res = mysqli_query($db, "SELECT Age FROM DUAL");
// Fetching a result row as an associative array
$row = mysqli_fetch_assoc($res); 
echo $row['_msg'];
```

# Prepared Statement
When you plan to use any data input by a user, you need to filter it appropriately for any control characters. You need to validate data when submitting any user input to a database
Thats why we use a **prepared statement**.

Its also useful in:
- speeding up execution when you are performing large numbers of the same query with different data
- Helping to protect against SQL injection-style attacks

```php
// Notice how we here got an object of the database
$db = new mysqli("host", "username", "password", "database");

if($db->connect_errno){ // checking for connection errors
	echo "<p>Error: Couldn't connect to the database</p>";
	exit;
}

// Non-Prepared statements
$db->query("SELECT age FROM myTable");
// Prepared statements stage 1 (prepare)
// This function constructs a statement object or resource 
// that you will then use to do the actual processing.
$stmt = $db->prepare("SELECT username age FROM myTable WHERE username=? and age=?");

// Prepared statements stage 2 (binding): 

// This funciton  tell PHP which variables 
// should be substituted for the question marks

// First parameter should specify the types of the following parameters
// "si" means that the parameters are “string int” 
// (you can use each seperately)
// (s for name. i for age)

// After this parameter, you should list the same 
// number of variables as you have question marks in your statement. 
// They will be substituted in this order.

$stmt->bind_param("si", $_POST['name'], $_POST['age']);
// username is bound to be of type string with value = $_POST['name']
// age is bound to be of type int with value = $_POST['age']

// Retrieving the query results
$stmt->execute();
$stmt->close();
```

# Object Oriented
Same as prepared statements. _(shit idk, and i cant bother)_

---
_Next [[🟩3 @ Example & PHPMyAdmin]]_
_Previous [[🟩1 @ Database]]_
