# Maps
In ArcGIS a map is contained of a base and optional layers
![[Pasted image 20230503161137.png|500]]

## Planar Coordinate System
The **Geographic / Planar coordinate system** is a spherical or ellipsoidal coordinate system for measuring and communicating positions directly on the earth as latitude and longitude 
![[Pasted image 20230503184040.png]]


## Datum
A datum is basically trying to fit an ellipsoid to match the surface of the earth
![[Pasted image 20230503184158.png]]

## Projection
We have 3 types of projection
- `Planar` : conserves the angle
- `Conical` : idk what it conserves
- `Cylindrical` : conserves distances

![[Pasted image 20230503184513.png]]

We can change the projection of a datum using the [[#Define Projection]] tool


# Types of Data
The types of data that can be placed on the map.

## Vector Data
There are 3 types or Vector Data:
- `Polygons`
- `Lines`
- `Points`

![[Pasted image 20230503160722.png|500]]

## Raster Data
Raster data is basically an image / grid of pixels
![[Pasted image 20230503160825.png|500]]

In the attributes table of a raster data, it contains the value of the pixel *(i.e. intensity)* and the count of the pixels with that value

## Tabular Data
tables duh.

Every row from the table is called a feature ^763d56

When creating new table, an ObjectID column is created by default to keep track of each entry.

# Layouts
Layouts are these like index maps, idk just look at dis:
![[Pasted image 20230503163504.png]]

Before we make a layout its better if we bookmark the location we want the layout to be on.
![[Pasted image 20230503164011.png]]

Now we can get a layout like so:
![[Pasted image 20230503164055.png]]

After we're done editing the layout we can export it like so:
![[Pasted image 20230503164306.png]]

# Navigation

## Bookmarks
Bookmarks allow you to save the position of the screen you were looking at.
![[Pasted image 20230503164011.png]]

## Selection
There are 3 types of selection
![[Pasted image 20230503183044.png]]

# Tools
In the Geoprocessing pane you can search for tools *(On the Analysis tab, click Tools)*

## Define Projection
ArcGIS geoprocessing tool that overwrites the coordinate system information _(map projection and datum)_ stored with a dataset.

## Project
Projects spatial data from one coordinate system to another

## Table To Domain
Creates or updates a coded value domain with values from a table

## Frequency
Basically reads the values of a table column and makes a new table containing the value and its frequency