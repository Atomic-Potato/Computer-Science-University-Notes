**_Note:_** Notice the difference between `$directory_string` which is what it says, and `$directory` being a data type specifically for directories.

---

To store a directory we use the function `opendir($directory_string)` which returns a `directory`.

To go through the directory we use the `readdir($directory)`. This function has an index at the first item in the directory, when its called it returns the file that is indexed and increments this index.
```php
while($file = readdir($dir)){
	// Just note that the current directory and parent directory are also read
	if($file == "." || $file == "..")
		continue;
}
```

To read all the files in the directory and place them inside an array we use `scandir($directory_string)`. We can also add the parameter `scandir($directory_string, 1)` to return the array in descending order.

And finally its always important to close your directory with `closedir($dir)`.