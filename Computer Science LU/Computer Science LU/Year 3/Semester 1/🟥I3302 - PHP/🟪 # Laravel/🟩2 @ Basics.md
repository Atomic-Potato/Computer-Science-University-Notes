# Project Directory
Now its not necessary to know what is every folder and file. The most important ones we want to know about is where we can do:
- HTML
- Models
- Controllers
- Routing
- File storing
- Config
- Databases

Which we will discuss later in the notes.
![[Pasted image 20230131191048.png]]

- `app:` contains the core of your application
- `bootsrap:` loads our application into the browser

tbh i cant bother 

# Editing the main page
If you go to `resources->views->welcome.blade.php` you will find the html that is displayed when you first open your project on the browser.
![[Pasted image 20230131214650.png]]
You can even delete the entire code in this page and write your own page.

# Creating pages / views
In the `resources->views` directory you can create a new page/view with the following name:
```
viewname.blade.php
```
we will discuss later in the notes what the blade means.

Now if you go to `routes->web.php`, you'll find
```php
Route::get('/', function(){
	return view('welcome');
})
```
This routes our upmost directory with the _welcome.blade.php_ to show up at the start of the page.
You can change "welcome" to the view name you just created and it will be the first thing when you open the app.

We will discuss routes later in the notes.