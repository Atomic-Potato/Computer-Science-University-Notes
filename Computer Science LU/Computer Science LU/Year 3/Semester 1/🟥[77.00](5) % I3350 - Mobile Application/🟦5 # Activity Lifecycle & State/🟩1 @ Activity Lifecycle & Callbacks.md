_Next [[🟩2 @ Activity Instance State]]_

--- 

# Lifecycle

An activity lifecycle is the set of states an Activity can be in during its lifetime, from when it is created until it is destroyed. 

More formally, a  directed graph of all the states an Activity can be in, and the callbacks associated with transitioning from each state to the next one
![[Pasted image 20230110181052.png|500]]

## Activity states and app visibility
State changes are triggered by user action, configuration changes such as device rotation, or system action

- `Created` _(not visible yet)_
- `Started` _(visible)_
- `Resume` _(visible)_
- `Paused` _(partially invisible)_ partially obscured or out of focus, but not shut down
- `Stopped` _(hidden)_ no longer active, but still in the device’s active memory
- `Destroyed` _(gone from memory)_

---

# lifecycle Callbacks
## Callbacks and when they are called
>`onCreate(Bundle savedInstanceState)`:  Called when the Activity is first created and does all static setup: _create views, bind data to lists, etc._ Only called once during an activity's lifetime ^onCreate
>```java
>@Override
>public void onCreate(Bundle savedInstanceState) {
>	super.onCreate(savedInstanceState);
>	// The activity is being created.
>	}
>```
>>`onStart()`:when Activity (screen) is becoming visible. And can be called more than once during lifecycle. 
>> Followed by `onResume()` if the activity comes to the foreground, or `onStop()` if it becomes hidden ^onStart
>> ```java
>> @Override
>>protected void onStart() {
>>	super.onStart();
>>	// The activity is about to become visible.
>>}
>> ```
>
>>`onRestart()`: called if Activity was stopped, immediately before it is started again _(calls onStart())_ ^onRestart
>>```java
>>@Override
>>protected void onRestart() {
>>	super.onRestart();
>>	// The activity is between stopped and started.
>>}
>>```
>>>`onResume()`: start to interact with user. For example  Activity has moved to top of the Activity stack. It is also always followed by `onPause()` ^onResume
>>>```java
>>>@Override
>>>protected void onResume() {
>>>	super.onResume();
>>>	// The activity has become visible and it is now "resumed"
>>>}
>>>```
>>
>>>`onPause()`: about to resume PREVIOUS Activity. Typically used to commit unsaved changes to persistent data, stop animations and anything that consumes resources ^onPause
>>>
>>>```java
>>>@Override
>>>protected void onPause() {
>>>	super.onPause();
>>>	// Another activity is taking focus this activity is about to be "paused"
>>>}
>>>```
>
>>`onStop()`: no longer visible, but still exists and all state info preserved. Causes of on stop:
>>- New Activity is being started, an existing one is brought in front of this one, or this one is being destroyed. 
>>- Operations that were too heavy-weight for `onPause()` ^onStiop
>>```java
>>@Override
>>protected void onStop() {
>>	super.onStop();
>>	// The activity is no longer visible and it is now "stopped"
>>}
>>```

>`onDestroy()`: final call before Android system destroys the Activity ^onDestroy
>```java
>@Override
>	protected void onDestroy() {
>	super.onDestroy();
>	// The activity is about to be destroyed.
>}
>```

![[image_2023-01-10_183530273.png|700]]

---

_Next [[🟩2 @ Activity Instance State]]_
