Well it can just be really all explained with some code example
```java
File f = new File("path");
if(! f.exists())
{
	System.out.println("File does not exist");
	System.exit(-1);
}

try{
	Scanner input = new Scanner(f); /* to read from a file, will try to open the file */
	
	while(input.hasNextLine())
		System.out.println(input.nextline()); //optional code for what to do
}
catch(FileNotFoundExceptionn ex)
{
	// when opening if file not found what to do
}
```