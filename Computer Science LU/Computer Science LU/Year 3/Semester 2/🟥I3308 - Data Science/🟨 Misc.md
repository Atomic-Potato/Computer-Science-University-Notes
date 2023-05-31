# Definition Query
Definition queries allow you to define a subset of features to work within a layer by filtering which features are retrieved from the dataset by the layer. 
This means that a definition query affects not only drawing, but also which features appear in the layer's attribute table and can be selected, labeled, identified, and processed by geoprocessing tools. 
_(Basically a filtering tool)_

To make a query, just simply right click the layer and go to `Properties` and you can create it in the `Definition Query` Section
![[Pasted image 20230530184648.png]]

# Setting the default directory
To set the default directory of the project you can simply right click the folder u want under `Folders` in the `Catalog` pane and set it as default
![[Pasted image 20230531112244.png]]

# Adding entire data folders to the project
Just right click `Folders` -> `Add Folder Connection`

# Summarize option
The summarize option can be used on a field to, for example, sum up all the values in the fields of that column
![[Pasted image 20230531151133.png]]

# Attachments
In here we will see how to include images and various media in a feature class.

First enable attachments by going to the `Properities` of the feature class -> `Manage` -> `Attachments`
![[Pasted image 20230531160432.png]]

This will create a table that contains the attachments and a [[🟩4@ Tabular Data Associations#Creating Relationship Classes|relationship class]] between the attachments table and the original feature class.
![[Pasted image 20230531160623.png]]

And now simply to add an attachment to a field, you go to the attribute table of the layer and right click the field -> `Manage Attachements`
![[Pasted image 20230531160941.png]]

# Pop Ups
Pop ups are basically a menu that displays more information on a field once you click on it, and you can configure it like in the image below
![[Pasted image 20230531161241.png]]
