_Previous [[🟩3 @ Dalvik VM]]_

--- 

The Manifest is an XML file where you define each [[🟩1 @ Main Android App Components|component]]
The root element is manifest. 

_Example with some attributes:_
```xml
<manifest
xmlns:android="http://schemas.android.com/apk/res/android"
	package="com.example.myfirstapp"
	android:installLocation="auto"
	android:versionCode="1"
	android:versionName="1.0" >
</manifest>
```
- Package name (ID of your app)
- Version information (`versionCode` is the value that is read by Google Play Store whereas `versionName` is what is presented to the user)
- `installLocation` attribute to control where the application is installed (internal or external storage): `auto`, `internalOnly`, `preferExternal`

# Permissions
Declare in the manifest the permissions you use
```xml
<uses-permission android:name="string" android:maxSdkVersion="integer" />
```

- `android:name`: The name of the permission:
	-  _android.permission.CAMERA_
	- _android.permission.READ_CONTACTS_
	- _android.permission.WRITE_EXTERNAL_STORAGE_
- `android:maxSdkVersion`: The highest API level at which this permission should be granted to your app. _For example, beginning with Android 4.4 (API level 19), it's no longer
necessary for your app to request the WRITE_EXTERNAL_STORAGE permission._

# Used Features
Declare in the manifest the `uses-feature` element to define the used features of the OS by your app.

_Example:_
```xml
<uses-feature android:name="android.hardware.telephony"/>
<uses-feature android:name="android.hardware.camera, android.hardware.camera.flash"/>
```

# Supported screens
Declare in the manifest the `supports-screens` element to specify the screen sizes supported by your app

_The following is an example of what to use for a tablet-only application_
```xml
<supports-screens
	android:smallScreens="false"
	android:normalScreens="false"
	android:largeScreens="false"
	android:xlargeScreens="true” />

<!-- No reason for the following line, it just fixes syntax highlighting -->
<supports-screens android:smallScreens="false"/>
```

# Used SDKs
Declare in the manifest the `uses-sdk` element to define the API evels your application supports:
- `minSdkVersion` defines the lowest Android version you support
- `maxSdkVersion` defines the highest (to avoid!)
- `targetSdkVersion` tells a device which API level you’re targeting

_Example:_
```xml
<uses-sdk
	android:minSdkVersion="8"
	android:targetSdkVersion="21" />
```

# Application
The [[🟩1 @ Main Android App Components#Application Component|Application component]] is represented by the application element in the manifest file. 

_Example:_
```xml
<application
	android:icon="@drawable/ic_launcher"
	android:label="@string/app_name"
	android:description="@string/app_description"
	android:theme="@style/AppTheme"
	android:allowBackup="true"
	android:backupAgent=".MyBackupAgent">
<!-- Activities, Services, receivers and providers go here ... -->
</application>
```
You can provide your custom Application class using `android:name` attribute. If not, the system default will be used.

---

_Previous [[🟩3 @ Dalvik VM]]_
