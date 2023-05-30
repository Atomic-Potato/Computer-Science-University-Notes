A geodatabase is a container for storing and managing spatial data in ArcGIS. It is a type of database that is optimized for managing geographic information, including features such as points, lines, and polygons, as well as non-spatial attributes.

![[Pasted image 20230503230521.png]]

# Life cycle of a geodatabase 
$$\Large Design \to Create \to Load \space Data \to Edit \space and \space Maintain$$


# Creating a Geodatabase
In the **Catalog Pane -> Project Tab** you can create a new geodatabase *(One is created by default)* 
![[Pasted image 20230503231230.png]]

Within this database we can create `Feature Classes`. Which are basically tables in the database but that are of a specific [[🟩1@ ArcGIS#Types of Data|data type]]
![[Pasted image 20230503231637.png]]
Additionally for any feature class, you can create as many attributes as needed for that class. ^d0b334

Once this feature class is created, it will add a new `Feature Layer` in the contents pane.

## Feature Dataset
A feature dataset is a container for related feature classes that share the same coordinate system, resolution, and extent.

Feature datasets can be used to group related feature classes, which helps to organize spatial data and makes it easier to work with. 
*For example, you might create a feature dataset to store all of the feature classes related to a particular project, such as roads, buildings, and land parcels.*

A feature dataset can also define a common coordinate system and spatial reference for all of the feature classes it contains. This ensures that the spatial data in the feature classes are properly aligned and can be analyzed and visualized together.

![[Pasted image 20230503232546.png|500]]

The reasons to use a feature dataset
![[Pasted image 20230503232205.png|400]]



**==NOTE:==** **Tabular feature classes cannot be added directly to a feature dataset**, because they are not spatial data. Unlike feature classes, which contain geographic features with a spatial location, tabular data represents non-spatial information, such as attributes, that can be associated with geographic features.

## Adding an entry to a polygon feature class
Simple go to `Edit` and click on `Create`. Then select the desired class
![[Pasted image 20230530183507.png]]

You can also edit an entry by first selecting it in the attribute table and clicking on `Edit Vertices`

## Calculating Fields Automatically
To automatically calculate a field, you can simply go to the attribute table of the desired layer, right click the desired column and select either `Calculate Field` or `Calculate Geometry` depending on the desired result. **Geometry** is mostly used for things to calculate things related to polygon data, like the area of a polygon for example.

![[Pasted image 20230530193853.png]]