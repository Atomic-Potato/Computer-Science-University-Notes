```c
void ContinueHandler(int sigNum){
}

void main(){
	signal(SIGCONT, ContinueHandler);
	int nextPID;
	
	for(int i=0; i<10; i++){
		if(!(nextPID = fork()){
			pause();
		}
	}
	
	
}
```