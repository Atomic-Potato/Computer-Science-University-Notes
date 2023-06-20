_Next [[🟩2 @ Spinners]]_

---

Just to note, most of these widgets have these attributes:
- `onClick`
- `text`
- `textSize`

# Buttons
## Button
![[Pasted image 20230104130805.png|100]]

key attributes:
```java
android:clickable="bool"    //set to false to disable the button
android:id="@+id/theID"     //unique ID for use in Java code
android:onClick="function"  //function to call in activity when clicked
							//(must be public, void, and take a View arg)
android:text="text"         //text to put in the button
```

represented by `Button` class in Java code

## Image Button
A clickable widget with an image label.

The attributes are the same, you just need one more attribute for the **source** and **remove the text attribute**
```java
android:src="@drawable/img" // must correspond to an image in the resources folder
```

To set up an image resource:
- put image file in project folder `app/src/main/res/drawable`
- use _@drawable/foo_ to refer to _foo.png_

**Use simple file names with only lowercase letters and numbers**

---

# ImageView
Just an image. And it only needs a source attribute
```java
android:src="@drawable/img"
```

Represented by `ImageView` class in Java code.
To change the image use the function `setImageResource()` and pass it the new image `R.drawable.filename`

---

# EditText
An editable text input box
![[Pasted image 20230104132405.png|100]]

Key attributes:
```java
android:inputType="type" // what kind of input is being typed(number,phone,date,time, etc.)
android:lines="int"      // number of visible lines (rows) of input
android:maxLines="int"   // max lines to allow user to type in the box
android:textSize="size"  // size of font to use (e.g. "20dp")
```

Others:  capitalize, digits, fontFamily, letterSpacing, lineSpacingExtra, minLines, numeric, password, phoneNumber, singleLine, textAllCaps, textColor, typeface

---

# Selections

## CheckBox
![[Pasted image 20230104132926.png|100]]

Key Attributes
```java
android:checked="bool"   // set to true to make it initially checked
android:clickable="bool" // set to false to disable the checkbox
```

In Java code:
```java
CheckBox cb = (CheckBox) findViewById(R.id.theID);
cb.toggle();
cb.setChecked(true);
cb.performClick();
cb.isChecked();
```

## RadioButton
![[Pasted image 20230104133345.png|100]]

Same attributes as the checked box but without the `clickable`. It also needs to be nested inside a `RadioGroup` tag in XML so that only one can be selected at a time

_For example:_
```xml
<RadioGroup ...
	android:orientation="horizontal">
	<RadioButton ... android:id="@+id/lions"
		android:text="Lions"
		android:onClick="radioClick" />
	<RadioButton ... android:id="@+id/tigers"
		android:text="Tigers"
		android:checked="true"
		android:onClick="radioClick" />
	<RadioButton ... android:id="@+id/bears"
		android:text="Bears, oh my!"
		android:onClick="radioClick" />
</RadioGroup>
```

**Useful java functions:**
- `radioGroup.getCheckedRadioButtonId()`
---
# ScrollView
A container with scrollbars around another widget or container
![[Pasted image 20230104224254.png|300]]

```xml
<ScrollView
		android:layout_width="wrap_content"
		android:layout_height="wrap_content">
	<TextView ... android:id="@+id/turtle_info" />
</ScrollView>
```


---
_Next [[🟩2 @ Spinners]]_

