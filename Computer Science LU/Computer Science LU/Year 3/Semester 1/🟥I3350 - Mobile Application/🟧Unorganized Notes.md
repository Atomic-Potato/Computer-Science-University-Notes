

---
# Layouts
![[Pasted image 20230104114407.png | 200]]
You can make different layouts for different devices or languages or for whatever reason

# `values` Folder
![[Pasted image 20230104114525.png|200]]
In these files you can define global variables to be used in the `activity_main.xml` elements.
For example, lets make a `strings.xml` variable. The `name` is the variable name.
![[Pasted image 20230104114725.png|600]]
This can now be referenced in any element by typing: `"@string/variable_name"`, take for example a _text_ element:
![[Pasted image 20230104114919.png|600]]
![[Pasted image 20230104114951.png|200]]

## strings.xml
You can declare a string or an array for strings like so
```xml
<string name="name">value</string>

<string-array name="arrayname">
	<item>value</item>
	<item>value</item> <!-- must escape ' as \' in values -->
</string-array>
```

You can refer to strings and arrays in the java code like so:
- as a resource: `R.string.name`, `R.array.name`
- as a string or array: `getResources().getString(R.string.name)`, `getResources().getStringArray(R.array.name)`

You can refer to strings and arrays in the xml code like so:
- strings: `"@string/string_name"`
- arrays: `"@array/array_name"`