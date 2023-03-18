_Next_ [[🟩3 @ Sessions]]
_Previous_ [[🟩1 @ Hidden Fields & Mails]]

---

# What are cookies
Cookies are small files saved on the client's hard disk by a web application. This file saves some information _(like login information)_ for smoother / faster and easier navigation when the client visits the site again.

# Limits of Cookies
- Users can easily disable the cookies feature.
- People move around.
- Users may delete cookies.
- PHP sets limit on cookies

# Creating Cookies
To create a temporary cookie that will be deleted after the browser closes, we use the following function:
```php
setcookie($cookie_name, $cookie_value);
```

To create a more permanent cookie on the hard drive you need to use the time() function when want to set a cookie on a hard drive. 
```php
//$expire = time() + $seconds; // time() returns the current date
$expire = time() + (60 * 60 * 24 * 10);
setcookie('Preference', 'Likes Chocolate', $expire);
```

# Reading Cookies
Use the supper global variable `$_COOKIE`
```php
$cookie_value = $_COOKIE[$cookie_name];
```

To check if the cookie exists, use `isset()`
```php
isset($_COOKIE['le fish']);
```

---
_Next_ [[🟩3 @ Sessions]]
_Previous_ [[🟩1 @ Hidden Fields & Mails]]