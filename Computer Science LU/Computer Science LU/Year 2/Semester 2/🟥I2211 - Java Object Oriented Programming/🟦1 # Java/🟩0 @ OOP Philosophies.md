**`IF YOU'RE JUST STARTING WITH JAVA, DONT START WITH THIS NOTE, JUST GO DIRECTLY TO THE NEXT ONE AND COME BACK LATER`**
# Relation of classes
There are 2 types of relations:
- `Composition relation` : 
	Same as a weak relationship in Databases. Consider an object A, containing an object of class B. If we loose the reference to object A and B is left with no other object referencing to it then its a composition relation
			
- `Aggregation relation` : Same as composition, but in the end  the object B stays and doesnt get deleted by the garbage collector, since theres some object that has a reference to it

This is particularly useful when we want to save memory if we have a  great amount of objects with the same contained data of variables

# Class completeness 
Completeness of a class, is trying to write all the methods that might be needed to manipulate data using this class, instead of having the user write these methods themselves.