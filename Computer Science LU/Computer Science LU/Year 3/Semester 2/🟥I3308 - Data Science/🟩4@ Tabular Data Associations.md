# Relate
A relate is a temporary relationship between two tables or feature classes based on a common field. When you perform a relate, you combine the attribute data from two tables or feature classes into a single output table or feature class. This allows you to query, analyze, and display the combined data as if it were a single dataset. However, the original data in the input tables or feature classes remains unchanged.
![[Pasted image 20230504143443.png]]

## Creating a joined table

![[Pasted image 20230504143546.png]]

# Join
A join is a relationship between two tables or feature classes based on a common field, but it is not a temporary relationship like a join. Instead, a join establishes a permanent link between the two datasets, so that changes to one dataset are reflected in the other. When you perform a join, you create a table that shows the joined records from one dataset for each record in the other dataset.

![[Pasted image 20230504145935.png]]

## Creating a related table

![[Pasted image 20230504143546.png]]

# Join VS Relate
The main difference between join and relate is that a [[#Relate]] creates a temporary relationship between two datasets that does not change the original data, while a [[#Join]] creates a permanent relationship that does change the original data.
 
**==Note:==** **I THINK ITS ACTUALLY THE OPPOSITE, TOO LAZY TO EXPERIMENT BUT YOU GET THE GIST OF THESE RELATIONS**

![[Pasted image 20230504150130.png]]

# Creating Relationship Classes
Relationship classes in ArcGIS are a way to establish and define the relationships between two or more feature classes or tables. They allow you to associate and link related data across different datasets.

To create a relationship class:
1. Right click the geodatabase -> `New` -> `Relationship Class`
2. Select the origin and destination tables
3. Select the cardinality
4. Run

![[Pasted image 20230530182615.png]]

# Spatial Join
In ArcGIS, spatial join is a geoprocessing operation that combines attribute data from two or more spatial datasets based on their spatial relationship. It allows you to transfer attributes from one dataset *(the target)* to another dataset *(the join)* based on the spatial relationship between their features.

Spatial join is particularly useful when you want to combine attribute information from one dataset with the spatial characteristics of another dataset. For example, you might have a polygon feature class representing census tracts and a point feature class representing retail stores. By performing a spatial join, you can transfer the attributes of the census tracts (such as population or median income) to the retail store points based on their spatial relationship. This enables you to analyze and visualize the attributes of the census tracts in the context of the retail store locations.

To make a spatial join, just right click the desired layer -> `Joins & Relates` -> `Spacial Join`
And pick all the fields you wanna join
![[Pasted image 20230530193626.png]]

Finally if youre done with the spatial join you can simply remove it by going back to `Joins & Relate` -> `Remove All Joins`


# ==Notes==
- `Join` and `Relate` are saved on a project level. While a `Relationship class` is saved on a gdb level.
- Sometimes its better to do [[#Spatial Join]] with the [[🟩1@ ArcGIS#Spatial Join|spatial join tool]]