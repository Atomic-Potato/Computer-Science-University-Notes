The main 2 ways to collect data are through `Field Maps` and `Surveys`
![[Pasted image 20230531184535.png]]
We will mainly be focusing on surveys

# Surveys
Once you make a blank survey, you'll start building it by simply using drag and drop, so go nutz
![[Pasted image 20230601123146.png]]

When you create a survey, 2 files are created. The `Form` file and a `Feature Layer` file which contains the data collected by the survey _(i think)_
![[Pasted image 20230601123315.png]]
If you make your survey public you get 3 feature layers instead
![[Pasted image 20230601130204.png]]
The first layer is the main layer while the other 2 are views of the main layer. This views are the ones used when filling a survey because they have restrictions on editing the data.

After you publish your survey u can see the collected data in the `Data` tab 
![[Pasted image 20230601123501.png]]

And modify the sharing levels through the `Collaborate` tab
![[Pasted image 20230601124659.png]]

## Appending Existing Data
You can add existing data to the survey data by going into the survey feature layer -> `Data` tab -> `Append Data to Layer`
![[Pasted image 20230601130721.png]]

The appended data must of the following formats
![[Pasted image 20230601130749.png]]


# Converting Excel to a Feature Layer
In the `Content` tab, you can upload an excel file by pressing on `New Item` and it will ask you if you wanna upload it as it is or convert it into a feature layer _(cant bother show u pics but its quite simple to do, im just letting u know that u can do this)_
![[Pasted image 20230601124418.png]]

==Note:== You can do the same with other things, such as shape files *(polygon layers and shit)* or geojson files.

# Making Feature Layers Online
You can simply create a feature layer online as you do in [[#Converting Excel to a Feature Layer]]
![[Pasted image 20230601125509.png]]

==Note:== I added this section for the sole reason of saying that using `Analysis` tools will exhaust your credits which will block your account, so its better to use it on Pro.

# Map Viewer
its basically ArcGis Pro but online with a different UI