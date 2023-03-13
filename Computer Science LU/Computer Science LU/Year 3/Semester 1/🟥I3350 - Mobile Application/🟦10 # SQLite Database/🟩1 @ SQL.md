The SQLite database is represented as an `SQLiteDatabase` object. And all interactions with database are through `SQLiteOpenHelper`
![[Pasted image 20230310093826.png|300]]

# Cursors
Cursor is a data type commonly used for results of queries. It is a pointer into a row of structured data _(think of it as an array of rows)_
`Cursor` class provides methods for moving the cursor _(so like pointing to a specific row)_ and getting data.
`SQLiteDatabase` always presents results as `Cursor`

## Subclasses
- `SQLiteCursor` exposes results from a query on a `SQLiteDatabase`
- `MatrixCursor` is a mutable cursor implementation backed by an array of Objects that automatically expands internal capacity as needed

## Common Operations
- `getCount():` number of rows in cursor
- `getColumnNames():`string array with column names
- `getPosition():` current position of cursor
- `getString(int column), getInt(int column), ...`
- `moveToFirst(), moveToNext(), ...`
- `close():` releases all resources and invalidates cursor

## Processing Cursors
```java
// Store results of query in a cursor
Cursor cursor = db.rawQuery(...);
try {
	while (cursor.moveToNext()) {
		// Do something with data
	}
} 
finally {
	cursor.close();
}
```

---

# Content Values
An instance of `ContentValues`:
- Represents one table row
- Stores data as key-value pairs
- Key is the name of the column
- Value is the value for the field

It is used to pass row data between methods.

```java
ContentValues values = new ContentValues();

// Inserts one row (Use a loop to insert multiple rows)
values.put(KEY_WORD, "Android");
values.put(KEY_DEFINITION, "Mobile operating system.");
db.insert(WORD_LIST_TABLE, null, values);
```

# Implementing SQLite
You always need to:
1. Create data model
2. Subclass `SQLiteOpenHelper`
	1. Create constants for tables
	2. In `onCreate()`, create `SQLiteDatabase` with tables
	3. Use `onUpgrade()` and optional methods
	4. Implement `query()`, `insert()`, `delete()`, `update()`, `count()`
3. In `MainActivity`, create instance of `SQLiteOpenHelper`
4. Call methods of `SQLiteOpenHelper` to work with database

# Subclass `SQLiteOpenHelper`
```java
public class WordListOpenHelper extends SQLiteOpenHelper {
	public WordListOpenHelper(Context context) {
		super(context, DATABASE_NAME, null, DATABASE_VERSION);
		Log.d(TAG, "Construct WordListOpenHelper");
	}
}
```

Declare constants for tables:
```java
private static final int DATABASE_VERSION = 1;
// Has to be 1 first time or app will crash.
private static final String DATABASE_NAME = "wordlist";
private static final String WORD_LIST_TABLE = "word_entries";

// Column names...
public static final String KEY_ID = "_id";
public static final String KEY_WORD = "word";

// ... and a string array of columns. (Optional)
private static final String[] COLUMNS = {KEY_ID, KEY_WORD};
```

You need a query to create the database. Customarily defined as a string constant.
SQLite supports the following data types: `NULL`, `TEXT`, `INTEGER`, `REAL` and `BLOB`
```java
private static final String WORD_LIST_TABLE_CREATE =
	"CREATE TABLE " + WORD_LIST_TABLE + 
	" (" + KEY_ID + " INTEGER PRIMARY KEY, " +
	// will auto-increment if no value passed
	KEY_WORD + " TEXT );";
```

In `onCreate()`:
```java
@Override
public void onCreate(SQLiteDatabase db) { // Creates new database
	// Create the tables
	db.execSQL(WORD_LIST_TABLE_CREATE);
	// Add initial data
	// ...
}
```

In `onUpgrade()`:
```java
@Override
public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
	// SAVE USER DATA FIRST!!!
	Log.w(WordListOpenHelper.class.getName(),
		"Upgrading database from version " + oldVersion + " to "
		+ newVersion + ", which will destroy all old data");
	
	db.execSQL("DROP TABLE IF EXISTS " + WORD_LIST_TABLE);
	onCreate(db);
}
```

## Optional Methods
- `onDowngrade():` default rejects downgrade
- `onConfigure():` called before `onCreate()`. Only call methods that configure the parameters of the database connection
- `onOpen()`

# Data base operations
- [[#Query|query()]]
- [[#Insert|insert()]]
- [[#Update|update()]]
- [[#Delete|delete()]]

## Query
- implement `query()` method in open helper class
- `query()` can take and return any data type that UI needs
- Only support queries that your app needs
- Use database convenience methods for insert, delete, and update

Database methods for executing queries:
- `SQLiteDatabase.rawQuery():` Use when data is under your control and supplied only by your app
	```java
	rawQuery(String sql, String[] selectionArgs)
	// First parameter is SQLite query string
	// Second parameter contains the arguments
	// Only use if your data is supplied by app and under your full control
	```
	_For example:_
	```java
	String query = "SELECT * FROM " + WORD_LIST_TABLE +
		" ORDER BY " + KEY_WORD + " ASC " +
		"LIMIT " + position + ",1";
	cursor = mReadableDB.rawQuery(queryString, null);
	```
- `SQLiteDatabase.query():` Use for all other queries
	```java
	Cursor query (boolean distinct, String table,
		String[] columns, String selection,
		String[] selectionArgs, String groupBy,
		String having, String orderBy,String limit);
	```
	_For example:_
	```java
	String[] columns = new String[]{KEY_WORD};
	String where = KEY_WORD + " LIKE ?";
	searchString = "%" + searchString + "%";
	String[] whereArgs = new String[]{searchString};
	cursor = mReadableDB.query(WORD_LIST_TABLE, columns, where, whereArgs, null, null, null);
	```

## Insert
```java
long insert(String table, String nullColumnHack, ContentValues values)
```
- First argument is the table name.
- Second argument is a `String nullColumnHack`:
	- Workaround that allows you to insert empty rows
	- Use null
- Third argument must be a `ContentValues` with values for the row
- Returns the id of the newly inserted item. If it was 0 or less then it wasnt inserted successfully

_For example:_
```java
newId = mWritableDB.insert( WORD_LIST_TABLE, null, values);
```

## Delete
```java
int delete (String table, String whereClause, String[] whereArgs)
```
- First argument is table name
- Second argument is WHERE clause, now its a little confusing but in this clause every variable should be a placeholder `?`, and this placeholder is then specified in in the third argument string array, for example:
	```java
	String selection = "title = ? AND author = ?";
	String[] selectionArgs = {"The Catcher in the Rye", "J.D. Salinger"};
	// Which means i want to delete the entries
	// WHERE title = "The Catcher in the Rye"
	//       AND authoer = "J.D. Salinger"
	```
	For more info about this refer to the following images:
	[[Pasted image 20230311125531.png]]
	[[Pasted image 20230311125551.png]]
	[[Pasted image 20230311125615.png]]
	[[Pasted image 20230311125633.png]]

This function returns the number of rows deleted.

_For example:_
```java
deleted = mWritableDB.delete(WORD_LIST_TABLE, KEY_ID + " =? ", new String[]{String.valueOf(id)});
```

## Update
```java
int update(String table, ContentValues values, String whereClause, String[] whereArgs)
```
- First argument is table name
- Second argument must be `ContentValues` with new values for the row
- Third argument is WHERE clause
- Fourth argument are the arguments to the WHERE clause

_For example:_
```java
ContentValues values = new ContentValues();
values.put(KEY_WORD, word);

mNumberOfRowsUpdated = mWritableDB.update( WORD_LIST_TABLE, values, KEY_ID + " = ?", 
											  new String[]{String.valueOf(id)});
```


## ==Note==
- Always put database operations in try-catch blocks
- Always validate user input and SQL queries

# Instantiating `OpenHelper`
In `MainActivity` `onCreate()`:
```java
mDB = new WordListOpenHelper(this);
```

# Transactions
_([[🟩1 @ Transactions|Database Transactions]])_

- Use transactions when performing multiple operations that all need to complete to keep database consistent
- Use to batch multiple independent operations to improve performance
- Can be nested

```java
db.beginTransaction();
try {
	// ...
	db.setTransactionSuccessful();
} 
finally {
	db.endTransaction();
}
```