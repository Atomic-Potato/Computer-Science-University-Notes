==I couldnt bother finish these notes because i was basically copying and pasting all of the slides, so i included the slides in the same folder: [[Fragments.pdf]]==

---

Your app can use different layout in different situations:
- different device type _(tablet vs phone vs watch)_
- different screen size
- different orientation _(portrait vs. landscape)_
- different country or locale _(language, etc.)_

Your app will look for resource folder names with suffixes:
- screen density _(e.g. drawable-hdpi)_ 
	- xhdpi: 2.0 _(twice as many pixels/dots per inch)_
	- hdpi: 1.5
	- mdpi: 1.0 _(baseline)_
	- ldpi: 0.75
- screen size _(e.g. layout-large)_
	- small, normal, large, xlarge
- orientation _(e.g. layout-land)_
	- portrait, landscape

![[Pasted image 20230310114204.png|300]]

# Portrait vs Landscape Layout
To create a different layout in landscape mode:
1. create a folder in your project called res/layout-land
2. place another copy of your activity's layout XML file there
3. modify it as needed to represent the differences
![[Pasted image 20230310114501.png]]

# Redundant Layouts
With situational layout you begin to encounter redundancy.
- The layout in one case (e.g. portrait or medium) is very similar to the layout in another case (e.g. landscape or large).
- You don't want to represent the same XML or Java code multiple times in multiple places.

You sometimes want your code to behave situationally.
- In portrait mode, clicking a button should launch a new activity.
- In landscape mode, clicking a button should launch a new view.

![[Pasted image 20230310114638.png|600]]

# Fragments
A fragment is a reusable segment of Android UI that can appear in an activity, and can:
- can help handle different devices and screen sizes
- can reuse a common fragment across multiple activities

![[Pasted image 20230310114806.png|600]]

## Creating a fragment
In Android Studio, right-click app, click:
>New → Fragment → Fragment (blank)

- un-check boxes about _"Include __ methods"_
- now create layout XML and Java event code as in an Activity

![[Pasted image 20230310114905.png|600]]

## Using fragments in activity XML
Activity layout XML can include fragments.
```xml
<!-- activity_name.xml -->
<LinearLayout ...>
	<fragment ...
		android:id="@+id/id1"
		android:name="ClassName1"
		tools:layout="@layout/name1" />
	<fragment ...
		android:id="@+id/id2"
		android:name="ClassName2"
		tools:layout="@layout/name2" />
</LinearLayout>
```

## Fragment life cycle
Fragments have a similar life cycle and events as activities. 

Important methods:
- `onAttach` to glue fragment to its surrounding activity
- `onCreate` when fragment is loading
- `onCreateView` method that must return fragment's root UI view
- `onActivityCreated` method that indicates the enclosing activity is ready
- `onPause` when fragment is being left/exited
- `onDetach` just as fragment is being deleted

![[Pasted image 20230310115057.png|]]

## Fragment template
```java
public class Name extends Fragment {
	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup vg, Bundle bundle) {
		// load the GUI layout from the XML
		return inflater.inflate(R.layout.id, vg, false);
	}
	
	public void onActivityCreated(Bundle savedState) {
		super.onActivityCreated(savedState);
		// ... any other GUI initialization needed
	}
	// any other code (e.g. event-handling)
}
```