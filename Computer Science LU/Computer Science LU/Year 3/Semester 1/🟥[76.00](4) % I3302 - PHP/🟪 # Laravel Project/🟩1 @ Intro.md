Laravel is a PHP framework. A framework is **a structure that you can build software on**. It serves as a foundation, so you're not starting entirely from scratch.

# MVC (Model-View-Controller)
MVC is a pattern in software design commonly used to implement user interfaces, data, and controlling logic.

- `Model`: Manages data and logic
- `View`: Handles layout and display _(usually html)_
- `Controller`: Routes commands to the model and view.

![[Pasted image 20230130233524.png]]

# Composer
Composer is a dependency manager for PHP. i.e. it can help us import external libraries and packages to out project with a simple command.
Composer can also be used with quite many frameworks.



# Creating a project
Change the CMD directory to the project directory and use this command
```cs
laravel new ProjectName
```

once laravel is installed for your project, you can run a local server using
```cs
php artisan serve
```
which will give you the address of the local host _(usually you can just write `localhost:8000` in the browser)_