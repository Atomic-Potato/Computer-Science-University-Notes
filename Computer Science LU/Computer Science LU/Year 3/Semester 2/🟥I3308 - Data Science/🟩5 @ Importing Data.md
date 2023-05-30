> Session 6 (May 8)

---

# Importing layer data into the geodatabase as feature classes

1. Head to `Map` and then `Add Data` and open all the xml layer files u want to import
   ![[Pasted image 20230530174314.png]]
   This will add all the data as layers in the map
2. Next right click the `Database` folder and create a new `Geodatabase File`
3. Right click the newly created geodatabase and click on `Import` -> `Feature Class`. And select all the layer you added earlier
   This will create a feature class out of each layer

Finally you can delete the layers that were in the map and import them again from the feature class _(i assume this makes it so they can both update if one of them got edited)_

# Cleaning Data
Sometimes there might be duplicate fields which needs to be removed. To do so:
1. Right click any of the layers and open its `Attributes Table`
2. In the `Attribute Table` click the on the dropdown list and open the `Fields View`
   ![[Pasted image 20230530175625.png]]
3. Delete the fields that you want and save
   ![[Pasted image 20230530175638.png]]
