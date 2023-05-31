_Sharing is caring bob_

> Session 9 May 22

---

In general you can share by going to the `Share` tab. The options are different depending on what you have selected, either be a map, layer or layout.
![[Pasted image 20230531162514.png]]

# Save As
## Layer File
Sharing as a layer file will export your layer properties **ONLY**. It will not take a copy of the data with it. This is particularly useful if you just need to play around with your labeling and stuff.

However this doesnt mean you cant use it, if you have the original data in your project, then you can make this layer reference that data so it can be displayed on the map.

## Map File
pretty much the same as [[#Layer File]] but for the entire map.

# Package
same as [[#Save As]] but the saved package also contains a copy of the required data instead of referencing it.

There are 2 ways you can share a package. Either save it locally or upload it to your online account.
![[Pasted image 20230531163547.png]]

If you share it online you get these extra options
![[Pasted image 20230531180451.png]]

You can find these packages online in the `Content` tab
![[Pasted image 20230531181232.png]]
![[Pasted image 20230531181452.png]]

## Online sharing
If you press share on any package *([[Pasted image 20230531181452.png]])* you get these options
![[Pasted image 20230531181604.png]]

You can share with specific people using **group sharing**.
To create a new group head to the `Groups` tab
![[Pasted image 20230531181720.png]]

### Credits
The more you share online / use your online storage the less credits you have. If you run out of credits you wont be able to store data online.
![[Pasted image 20230531182017.png]]

# Share As
Sharing here will allow people to view your map or layer without the viewer having access over the data or editing privileges. Its only for view purposes.

==Note:== Your layers must be in `WGS 1984` coordinate system for them to be viewed on the online map viewer. In this case we can use `Transformation` to keep the original coordinate layer but convert it to the `WGS 1984` system _(Kinda like an adapter)_
![[Pasted image 20230531182657.png]]

When you share the web map/layer, actually 3 things get shared
![[Pasted image 20230531183009.png]]
The `Web Map` references the data that is in the `Feature Layer`. While the `Service Definition` lets us see the fields and their stuff and shit _(the schema)_

If you do decide and make the `Web Map` public for everyone, then the data should be public as well _(i.e. the `Feature Layer`)_. 
Now if you want to allow anyone to edit the data then you have to go into the `Feature Layer` settings and tick these features:
![[Pasted image 20230531183550.png]]
![[Pasted image 20230531183726.png]]
