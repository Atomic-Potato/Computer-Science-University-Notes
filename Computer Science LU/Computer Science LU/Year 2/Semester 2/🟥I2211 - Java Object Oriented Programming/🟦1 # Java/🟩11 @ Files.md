# General
```java
File file = new File("filepath/file.txt"); // finds the file in this path
File folder = new File("folderPath"); // puts a folder in the variable instead of the file
```

Some useful functions in the file class:
- **exists()** _check if the file exists_
- **canRead() / canWrite** _checks for these abilities_
- **createNewFile()** _creates a file with this name if it doesnt exist_
- **delete()** _deletes file_
- **list()** _lists the files in this directory_
- **isFile()**

## Reading from a file
```java
Scanner input = new Scanner(FileVar);

while(input.hasNextLine())
{
	input.nextLine(); // Reads the entire current line
	input.next(); // reads the current word on the line
}
```

Its important to check for the existence of your files with the `FileNotFoundException`
```java
try{
	Scanner input = new Scanner(FileVar);
}catch(FileNotFoundException ex){
	PrintWriter pw = new PrintWriter(FileVar); // creates this file in the given file directory
}
```
## Writing to a file
- `PrintWriter` allows us to use the `System.out` functions for writing to a file (or the output stream of our choosing). If the file doesn't exists, it will be created. **If it already exists, it will be overwritten** and all its contents will be lost.
	```java
	PrintWriter pw = new PrintWriter(FileVar);
	pw.println("Potaton");
	pw.print("Tomato");
	pw.close(); // its important to close your files once youre done with editing
	```
- `FileWriter` is just like _PrintWriter_ but it appends to the file instead of overwriting it
	```java
	FileWriter fw = new FileWriter(FileVar);
	fw.write("This is a line\n");
	fw.write("Add this word");
	fw.close();
	```
- `BufferedWriter`: Since we have to get the hard drive to write into a file, which takes a lot of time, we can send the text added to a buffer. And once the buffer is full, we send out the data (Or when force it with `flush()` or the file is closed)
	```java
	BufferedWriter bw = new BufferedWriter(FileVar);
	bw.write("This is a line\n");
	bw.write("Add this word");
	bw.flush();
	bw.close();
	```
