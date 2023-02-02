# Routing
**Routing is basically mapping a laravel page with a specific URL.** So say we have a page called _"hello.blade.view"_ then we can route it to _"website\.com/welcome"_ 

Now to create routes to pages, we have to add them inside `routes->web.php`. And the syntax of a route is the following:
```php
Route::get("url", function(){ // this is an anonymous function
	return view("PageName");
});
```
The url name can be whatever we want, it doesnt have to match with the actual file name.

You can also make it shorter, but you wont be able to pass in variables through the url _(we will talk about this next)_:
```php
Route::get("url", "PageName");
```

**_Note:_** You can set the URL as `/` so it would be the route of the application, i.e. first page to open up.

## Parsing data 
We can parse data through the URL  like so:
```php
Route::get("URL{variable}", function($variable){
	// we can use this variable here as well, or in the page as show later
	echo $variable;
	return view("page");
});
```

To use this variable inside the page we have to parse it inside a dictionary array _(forgot what they are called)_:
```php
return view("page", ['key'=>$variable]); 
```
And we can access this dictionary in the page like so:
```php
<h1>Our variable value: {{$key}}</h1>
```
_We can do this thanks to `blade.php`_

## Redirecting
With the following function you can redirect a URL to a specific another URL 
```php
Route::get("RedirectedURL", function(){
	return redirect("NewURL");
});
```

---

# Controller
**The controller gets data from the database and sends it to the HTML part.**
Controllers are located inside: `app->Http->Controllers`.

To create a new controller, use the following command line:
```
php artisan make:controller ControllerName
```
_(You can create the file manually, but its kinda tedious)_

This is the default structure of a controller:
```php
<?php
namespace App\Http\Controllers;

use Illuminate\Http\Request;

class myController extends Controller{
	//
}
```
Here you can write functions as you like to handle variables with logic when passed between pages. And i think PHP is object oriented, so you can make your functions public / private.

## Calling Functions & Parsing Data
To call a function from the controller, first you write this at the top of `routes->web.php`
```php
use App\Http\Controllers\ControllerName; // Pay attention to the name
```

And then you use a route to call the function like so:
```php
Route::get('URL', [ControllerClassName::class, 'YourFunction']);
```

To parse data to that function, just add the variable to the URL:
```php
Route::get('URL{variable}', [ControllerClassName::class, 'YourFunction']);
```
and in the function parameter in the controller class:
```php
class ControllerClass extends Controller{
    public function echo($variable){
        echo "$variable";
    }
}
```

---

# Views
**Views are the part we want to show to the user. Basically the HTML in Laravel.**

Views are located inside `resources->views` and create a file with this format:
```php
ViewName.blade.php
```
_(we will discuss blades later in the notes)_
Parsing data to views was already scene in [[🟩3 @ Routes, Controllers & Views#Routing|Routing]]

## Calling views from controllers
You can simply just make a function that returns the view in the controller 
```php
class ControllerClass extends Controller{
    public function LoadView(){
        return view("ViewName");
    }
}
```
and route this function like in [[🟩3 @ Routes, Controllers & Views#Calling Functions & Parsing Data|Controllers]]

And to parse data to that view you just simply:
1. Parse it to the function in the route
2. Add it to a dictionary as second parameter to the view function _(as seen in [[🟩3 @ Routes, Controllers & Views#Parsing data|Routes]])_