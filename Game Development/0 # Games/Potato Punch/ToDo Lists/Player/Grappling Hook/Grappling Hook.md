# Grappling hook
I want when the raycast hits an anchor collider, we let the player press right click and he will start grappling towards the direction of the anchor.

# ToDo List
- [x] Make a raycast from the player extending with a designated length
- [x] Make collider anchors and let them not collide with anything
- [x] If the raycast hits an anchor and the player right clicks, make a bool to start the grappling function
- [x] Grab the position of the anchor that was hit by the raycast
- [x] While grappling, keep updating the direction of the anchor
- [x] Keep the momentum
- [x] add a visual indicator of nearby anchors
- [x] Make indicator point at anchor and only show when in range
- [x] Make indicators show actual direction
- [x] Make new anchor and pointer sprites
- [x] add a grappling string
- [x] camera zoom out or some speed effect
- [x] space bar can cancel the grappling
- [x] fix the speed of the grapple gets canceled when bounced off an anchor and player controller receive input
- [x] Timer before being able to grapple again
- [x] UI for the Grappling Timer
- [x] direction arrows game object
- [x] turn green the ones that are selected
- [x] deselect the arrows when the button is pressed again
- [x] give the final force the direction of the final direction arrows
- [x] give an extra upper force when applying force horizontally
- [x] the force of grappling stops relying on physics once the player is very close to the anchor and just moves him towards the anchor
##### Optional
- [ ] make the `distanceToDetachGrapple` smaller if there is `finalGrapplingForceDirection`
- [ ] perk, player drops bombs while grappling
- [ ] fix the colors issue (Or avoid it by just making the distance between each anchor greater than the distance of player grappling )

#### How to fix the momentum ?
So far i have noticed that the moment on the Y axis is normal and its only broken on the x axis
My guess is the movement code
Yep it was it, its because in the line were we set the x velocity, its always active and setting the players velocity to 0 while theres no input, this is why when he got knocked it didnt feel smooth
Im not really sure how to fix this, we can make it so that if the player is in the air and the input is 0, just ignore that input...
Or maybe make a different acceleration time while in air which should be quite longer than the accelaration time thats on the ground