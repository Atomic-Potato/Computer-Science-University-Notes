_Next [[🟩2 @ Android OS & App Architecture]]_

--- 
# App Components
Here we will discuss the essential building blocks of an Android app. Each component is an entry point through which the system or a user can enter your app. Some components depend on others.

The most frequently used components are:
- `Activity`
- `Service`
- `BroadcastReceiver`
- `ContentProvider`
- `Application`

These components come with a **base class that you extend** and a section in the application ,**manifest XML file**, that exposes them to the Android system _(in other words, the XML file is what the user sees)_.

# Activity Component
UIs for an Android app should extend the `Activity` class, or one of its subclasses: _FragmentActivity, ListActivity, ActionBarActivity, AppCompatActivity ..._

An app can have several `Activities` for different functions but **only one `Activity` can be displayed** at any given time.

Its also important to switch intensive operations to a `Service` and execute them on a sperate thread so the user can keep using the UI without having to wait for the operation to finish.

# Service Component
Anything that doesn’t involve user interface operations goes into a `Service`.

All components run on the same main thread. So make sure to execute any long-running Service in a new thread using `AsyncTask`. _It is recommended to create a Service for each task_

# BroadcastReceiver Component
`BroadcastReceiver` is useful for one thing only: **listening to system events**. 
Your application will be notified about the events after registering to the desired event and this event is **broadcasted** (which means any script registered to the even will receive it).

_Example of an event:_ Be notified when the battery goes below certain limit

# ContentProvider Component
Use a `ContentProvider` component to manage a shared set of app data that you can store in the file system, in a SQLite database, on the web, or on any other persistent storage location

In many cases, a simple key/value storage using `SharedPreferences` is sufficient

# Application Component
A top-level component that’s created before other components _(Activities, Services …)_
An Android app will always have an `Application` component (created by default for you)
You can use it to share variables and communicate across the other components within your app

---

_Next [[🟩2 @ Android OS & App Architecture]]_
