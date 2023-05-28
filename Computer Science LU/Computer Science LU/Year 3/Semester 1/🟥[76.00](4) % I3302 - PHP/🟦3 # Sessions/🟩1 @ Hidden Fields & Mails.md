_Next_ [[🟩2 @ Cookies]]

---

# Hidden Input
```php
<input type="hidden" name="ligma" value="Ay watch yo jet">
```
Used to transfer data from page to page
Not visible to the user, but part of the form
Will be received by the action script

i dont get the point, i think you just use IT to store data in the form. Like in the following example where we generate a random number and store it in the hidden input
![[Pasted image 20230317141437.png]]


# Mails
To send mail in PHP, use `mail()` which uses Simple Mail Transfer Protocol _(SMTP)_
```php
// mail(to_address, subject, message, extra_headers);

// Example:
$dest = "orders@hardwareville.com";
$subject = "New Hardware Order";
$message = "Enclosed is a new order for 12 hammers.\n Thanks.";
$extra = "From: harry@hardwareville.com";
mail($dest,$subject,$message,$extra);
```

---
_Next_ [[🟩2 @ Cookies]]
