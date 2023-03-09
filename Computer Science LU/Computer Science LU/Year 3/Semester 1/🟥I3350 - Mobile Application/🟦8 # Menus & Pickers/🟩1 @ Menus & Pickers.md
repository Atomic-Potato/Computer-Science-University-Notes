There are several types of menus:
1. App bar with option menu _(We will only learn about dis one)_
2. Context menu
3. Contextual action bar
4. Popup menu
![[Pasted image 20230308115536.png|600]]

# Dialogs And Pickers
1. Alert dialog
2. Date picker
3. Timer picker
![[Pasted image 20230308115704.png|600]]

# App Bar
The app bar is the bar atop of each screen _(same for all devices usually)_.
It contains:
1. Nav icon to open navigation drawer
2. Title of the current **Activity**
3. Icons for options menu items
4. Action overflow button for the rest of the options menu

![[Pasted image 20230308115915.png|400]]

_You can have the action icons from the important options shown on the app bar_

# Implementing the options menu
1. Create the XML menu resource `menu_main.xml` that contains the layout and contents of the menu. This resource file defines the menu items, their icons, and other properties.
3. `onCreateOptionsMenu()` to [[#^inflate|inflate]] the menu.
	```java
	// Override this menthod in Activity
	@Override
	public boolean onCreateOptionsMenu(Menu menu){
		getMenuInflater().inflate(R.menu.menu_main, menu);
		return true;
	}
	```
1. `onClick` attribute or `onOptionsItemSelected()`
	```java
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
			case R.id.action_settings:
				showSettings();
				return true;
			case R.id.action_favorites:
				showFavorites();
				return true;
			default:
				return super.onOptionsItemSelected(item);
		}
	}
	```
2. A method to hand the item clicked
![[Pasted image 20230308120318.png|600]]

> **What is `inflate`?**
> When the app needs to display the menu, it needs to "inflate" the menu resource file, which means it needs to convert the XML file into a view hierarchy that can be displayed on the screen. ^inflate

## Creating an option
1. Create a menu resource directory **_(it is not present by default)_**
2. Create XML menu resource file `menu_main.xml`
3. Add entry for each menu item

_For example:_
```xml
<item android:id="@+id/option_settings"
	  android:title="Settings"/>
<item android:id="@+id/option_favorites"
	  android:title="Favorites"/>
```

The following attributes are possible for each item:
```xml
<item
	  ...
	  android:icon="@drawable/pic_name"
	  android:orderInCategory="30" (Im assuming the position in the list)
	  app:showAsAction="ifRoom" />
```
`showAsAction` can also have:
- `always`
- `collapseActionView`
- `withText`