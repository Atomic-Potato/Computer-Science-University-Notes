> Session 7 May 10


---


# Symbology
Right click the desired layer -> `Symbology` -> go nutz

One you will use a lot is `Graduated Colors` _(Make sure as well to include values out of range by clicking on `More`)_
![[Pasted image 20230530194359.png]]

==Note:== By default when you drag in a new layer its symbol type is a `Single Symbol`, but if it has [[🟩3@ Data Integrity#Subtypes|subtypes]] then it will be of type `Unique Values`   

## Classes
If you pick `Unique Values` symbology then you can pick a unique symbol for each class

## Graduated Symbols
Resized the symbols based on a field value 

# Labeling
- To begin labeling just click on the desired layer and check `Label`
Then you can pick which class and field u want to use as labels
![[Pasted image 20230531113347.png]]
- You can also gain more control over the labels by right clicking the layer and going to `Label Properities`
- You can set a specific label for a specific field by selecting it in the attribute table and now modifying the label options will be only applied to this field

==Note:== Labels are on a project level, so sharing the map will share it without any of its labels or [[#Classes]]. To make geodatabase level labels we use [[#Annotations]]

## Classes
You can create label classes by click on `Class` and create a new class, this will kinda duplicate all the label data for the class, which means you will see duplicate labels on the map. To fix this issue just click on `SQL Query` so you can filter out the duplicate results as you wish.

## Annotations
Annotations are basically [[#Labeling|labels]] but that are on the geodatabase level

ig you can check if you have labels or annotations by checking if you can [[#Converting Labels to Annotations|convert labels to annotations]] or you can check if the `Label` mark is checked [[Pasted image 20230531113347.png]]

### Types of Annotations
![[Pasted image 20230531124656.png]]

### Converting Labels to Annotations
_(While the layer is selected)_
![[Pasted image 20230531125121.png]]
![[Pasted image 20230531125354.png]]
The thing to note here the most is the `Extent`, you can set the extent to the current zoom so that only the visible labels will be converted for example.

_(Check the `Create feature-linked annotation` to do what it does. Just bringing your attention to it)_