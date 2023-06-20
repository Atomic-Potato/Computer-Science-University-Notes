I removed the parts related to AsyncTaskLoader from the PDF since it wasnt required for exams in my year.

# Some Notes
- Even tho `onPreExecute()` is declared in the background thread class, it is actually ran in the UI thread
- The 3 dots after the type of the argument means we can send this functions as many parameters as we want. 
  _For example:_
	```java
	protected void onProgressUpdate(Integer... values){
		super.onProgressUpdate(values);
		// do ur thing
		print(values[0]);
	}
	```
