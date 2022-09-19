# ArrayList
its a non primitive data type unlike the normal array, it stores only objects and no primitive type variables. And it includes many methods for array manipulation.

## Decleration
```java
ArrayList arr1 = new ArrayList(); //Can store any object of class Object and its subclasses
								  //i.e. it stores any kind of object since everything inherits from the Object class	
ArrayList<ClassName> arr2 = new ArrayList<ClassName>(); //Can store any object of class ClassName and its subclasses
```

## Methods
- **ArrayList()** Create an empty array
- **add(Object o)** returns void and appends the new object (object can be of any class, depending on the array type) to the end of the array
- **add(int index, Object o)** adds o at the index i, it doesnt overwrite however, it shifts all the elements to the right
- **clear()** empties the array
- **contains(Object  o)** returns true or false, checks whether the object is the array
- **get(int index)** returns the first occurrence of object at index 
- **indexOf(Object o)** returns the index of the object o
- **isEmpty()** returns true or false
- **lastIndexOf(Object o)** returns the last occurrence of object at index 
- **remove(Object o)** returns true or false Removes the first occurrence of the specified element from this list, if it is present.
- **remove (int index)**  returns true or false and removes the object at index if present
- **size()** Returns the number of elements in this list.
- **set(int index, Object o)** Replaces the element at the specified position in this list with the specified element.

## Wrapper
what if we want to add primitive types to the array? Theres the classes called wrapper classes for primitive types that put them in a class

These classes are (Basically starts with capital letter)
- byte -> Byte
- short -> Short
- int -> Integer
- long -> Long
- float -> Float
- double -> Double
- boolean -> Boolean
- char -> Character

```java
ArrayList<int> myNumbers = new ArrayList<int>(); // Invalid
ArrayList<Integer> myNumbers = new ArrayList<Integer>(); // Valid

myNumber.add(new Integer(69));
```

**`NOTES:`**
- The array adds a **reference** to the objects and doesnt actually contain the object
	And so **equals()** should be overridden in a class since the equals by the object class compares addresses, and in the array we a give a new object of a new address
# Gregorian Calendar
The Gregorian calendar inherits form the Calendar class
```java
public class GregorianCalendar extends Calendar
```
It makes working with dates much more easier

## Constructors
```java
GregorianCalendar();
//Constructs a default `GregorianCalendar` using the current time in the default time zone with the default format locale.
GregorianCalendar(int year, int month, int dayOfMonth);
GregorianCalendar(int year, int month, int dayOfMonth, int hourOfDay, int minute);
GregorianCalendar(int year, int month, int dayOfMonth, int hourOfDay, int minute, int second);
```

## Methods 
```java
add(int field, int amount);
//Adds the specified (signed) amount of time to the given calendar field, based on the calendar's rules.

//The field can be accessed like the following instead of having to remeber their numbers
calendarName.add(GregorianCalenar.YEAR, 69); //of course YEAR can be replaced by DAY or MINUTE and such 
```