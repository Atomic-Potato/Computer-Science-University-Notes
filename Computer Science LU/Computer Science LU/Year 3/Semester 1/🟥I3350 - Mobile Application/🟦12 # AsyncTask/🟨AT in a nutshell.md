```java
private class MyAsyncTask extends AsyncTask<ParamsType, ProgressType, ResultType>{
	@Override
	protected void onPreExecute(){
		// Runs on the main thread
		// Sets up the task
	}
	
	@Override
	protected ResultType doInBackground(ParamsType... Parameters){
		// Once the task is fnished
		// it should return a result of ResultType
		// that will be passed to onPostExecute
		// as a parameter
	}
	
	@Override
	protected void onProgressUpdate(ProgressType result){
		// Runs on the main thread
		// receives calls from publishProgress() 
		// from background thread
	}
	
	@Override 
	protected void onPostExecute(ResultType result){} 
}
```
![[Pasted image 20230322212744.png]]
![[Pasted image 20230322212714.png]]

```java
// In the main class that runs on the main thread
MyAsyncTask as = new MyAsyncTask();
as.execute("parameter 1", "parameter 2", ...);
// i have the parameteres strings here
// but ig you insert them same type youve put in the declaration
as.cancel();
```

