Shared preferences allow us to read and write small amounts of primitive data as key/value pairs to a file on the device storage.

`SharedPreference` class provides APIs for reading, writing, and managing this data.

Usually data is saved `onPause()` and restored `onCreate()`

# Saved Instance State
Saved instances are small number of key/value pairs just like shared preferences but data is private to the application.

## Shared Preferences vs. Saved Instance State
`Shared Preferences:`
- Persist data across user sessions, even if app is killed and restarted, or device is rebooted
-  Data that should be remembered across sessions, such as a user's preferred settings
- Common use is to store user preferences

`Saved Instance State:`
- Preserves state data across activity instances in same user session
- Data that should not be remembered across sessions, such as the currently selected tab
- Common use is to recreate state after the device has been rotated

# Creating Shared Preferences
Only one Shared Preferences file is needed per app. _(It is usually named with the package name of the app)_

To get a link to the file we use `getSharedPreferences()`
```java
private String sharedPrefFile = "com.example.android.hellosharedprefs";
mPreferences = getSharedPreferences(sharedPrefFile, MODE_PRIVATE);
// MODE argument is for backwards compatibility
// use only MODE_PRIVATE to be secure
```

# Saving Data
The  `SharedPreferences.Editor` interface takes care of all file operations.
The `apply()` saves data to the file asynchronously and safely.

```java
@Override
protected void onPause() {
	super.onPause();
	SharedPreferences.Editor preferencesEditor = mPreferences.edit();
	preferencesEditor.putInt("count", mCount);
	preferencesEditor.putInt("color", mCurrentColor);
	preferencesEditor.apply();
}
```

# Restoring Data
Data should be restored in `onCreate()`.
We restore data using **get methods** _(such as getInt)_ which take 2 arguments, the key and the default value if the key cannot be found.

```java
if (savedInstanceState != null) {
	mCount = mPreferences.getInt("count", 1);
	mNewText = mPreferences.getString("text", "");
}
```

# Clearing
To clear all the values in the shared preferences file, call the `clear()` method on the shared preferences editor and `apply()` the changes.
```java
SharedPreferences.Editor preferencesEditor = mPreferences.edit();
preferencesEditor.clear();
preferencesEditor.apply();
```

# Listening to Changes
To listen to changes:
1. Implement interface `SharedPreference.OnSharedPreferenceChangeListener`
2. Register and unregister listener in `onResume()` and `onPause()` using, `registerOnSharedPreferenceChangeListener()`
3. Implement on `onSharedPreferenceChanged()` callback

```java
public class SettingsActivity extends AppCompatActivity implements OnSharedPreferenceChangeListener { 
	// ...
	public void onSharedPreferenceChanged(SharedPreferences sharedPreferences, String key){
		// do ur stuff
	}
}
```

Creating and registering listener:
```java
SharedPreferences.OnSharedPreferenceChangeListener listener = new SharedPreferences.OnSharedPreferenceChangeListener() {
	public void onSharedPreferenceChanged(SharedPreferences prefs, String key) {
		// Implement listener here
	}
};
prefs.registerOnSharedPreferenceChangeListener(listener);

// we kept a reference to the listen so we can unregister it later
```