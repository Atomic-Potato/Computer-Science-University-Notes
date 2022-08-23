# **Big changes**
- Added a grappling hook
- New camera "Peek" system
# **Tweakings**
- If there's no input while in air, the velocity of the player will stay the same unless applied opposite input, instead of the player velocity going to zero while there's no input while in air
- Added ground acceleration time of **0.25 seconds** and ground deceleration time of **0.15 seconds**

# **Bug fixes**
- Fixed the weak ass unsatisfying knock by the Rocketato into a more natural one for the player
- Increased the field of aiming for the player while going left, which was smaller than the one going to the right
- Fixed the weapon going back to default position instantly when moving and aiming in the opposite direction of movement
- Smoll gaps between walls and ground and the player, leading the player to getting stuck
- Wall jumping without the dash


# **How does the new stuff work ?**
***Grappling Hook:***
Aiming at the direction of the *"Red Anchors"* will turn them into *"Green Anchors"*, once they are green you can right click the mouse and the player will grapple towards them. 
You can cancel a grapple by right clicking again or by getting knocked by a *"Rocketato"*. However letting the grappling finish by itself will give the player an impulse into the direction of the grapple. `(Once canceled, you can't grapple until 1 second passes which is represented by a UI icon in the lower left corner)`
Grappling anchors are still accessible when out of bounds of the camera view. On the edges of the screen you will see a *"Red Arrow"* pointing towards a nearby anchor, aiming to the direction of the Arrow will turn it *"green"* and then you can right click to grapple to that anchor.
