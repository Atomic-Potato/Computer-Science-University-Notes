# Uploading The File
To upload a file we use a simple form with a `multipart/form-data` encryption, it specifies how the data should be encoded.
Next we add a **hidden** input that specifies the max file size **in bytes**. _(this size can not override the maximum `upload_max_filesize` size in the field in your default php.ini file of 2MB)_
And finally we create an input of type `file` to upload the file
```html
<form action="upload.php" method="POST" enctype"multipart/form-data">
	<input type="hidden" name="MAX_FILE_SIZE" value="51200">
	File to Upload: <input type="file" name="fileupload"><br><br>
	<input type="submit" value="upload!">
</form>
```

# File Information
Information about the uploaded file becomes available to you in the super global associative array `$_FILES`
You can now access the associative array of the uploaded file information like so: `$_FILES['uploaded_file_name']`. 
With this you can access information about the file _(not the actual data)_ with the following keys:
![[Pasted image 20230124092407.png|700]]

**Notice how the file is stored in a temporary directory `$_FILES['fileupload']['tmp_name']`, which we will move later into a permanent directory**

## Error Handling 
In the file information we also have
```php
$_FILES['fileupload']['error']
```
to check for errors. `0` means there was no errors uploading the files, and we have 8 error types which can be checked like so:
```php
if ($_FILES['fileupload']['error'] > 0){
	echo 'Problem: ';
	switch ($_FILES['fileupload']['error']){
		case 1: echo 'File exceeded upload_max_filesize.'; break;
		case 2: echo 'File exceeded max_file_size.'; break;
		case 3: echo 'File only partially uploaded.'; break;
		case 4: echo 'No file uploaded.'; break;
		case 6: echo 'Cannot upload file: No temp directory specified.'; break;
		case 7: echo 'Upload failed: Cannot write to disk.'; break;
		case 8: echo 'A PHP extension blocked the file upload.'; break;
	}
	exit;
}
```

# Preparing The file
First we check if the file is uploaded using `is_uploaded_file()`
```php
if(is_uploaded_file($_FILES['filename']['tmp_name']))
```

And now we can move the file to a permanent directory using `move_uploaded_file()` _(usually we create a folder for uploads inside the project folder)_
```php
move_uploaded_file($uploaded_file_path, $destination_path);
```

# Type Checking
We simply do this comparison:
```php
if($_FILES['fileupload']['type'] === 'image/png')
```

# Displaying An Image
```php
echo '<img src="uploads/'.$_FILES['fileupload']['name'].'"/>';
```