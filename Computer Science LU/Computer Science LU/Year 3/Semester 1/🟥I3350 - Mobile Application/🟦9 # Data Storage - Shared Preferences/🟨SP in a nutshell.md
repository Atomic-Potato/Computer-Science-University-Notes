```java
Shared prefs = getSharedPreferences("name", MODE_PRIVATE);

prefs.getString("key", "default value");

SharedPreferences.Editor editor = prefs.edit();
editor.putString("key", "value");
```