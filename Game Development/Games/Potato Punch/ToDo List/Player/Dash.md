# Dash
The player can dash and knock enemies that he hits, he is still vulnerable to bullets and rocketatoes

# ToDo List
- [x] Start
- [x] theres that video about dashing, watch do it like him
- [x] fix the dash
- [x] Replenish the dashes once grounded
- [x] Put a delay after depleting the dashes count
- [x] Disable shooting while dashing for both comp and player
- [x] give the player the power to knock off enemies
- [x] If player hits a wall make him pause and let him jump
- [x] switch back to the raycast collision detection again
- [x] set the velocity to 0 if the player hits a collider and didnt `isDashingWall`
- [x] comment the code
- [x] fix dashing while rolling 

## Extra
- [x] Make the dash delay only if is dashing and grounded
- [ ] if the getting stuck to edges is annoying then use 3 raycasts and check if the top and bottom raycasts hit a collider then `dashingWall = true`
- [ ] dash feels wrong, get feedback
- [ ] get the player velocity during the dash
- [ ] if the player velocity is greater than the dash velocity the make the dash velocity equal to the current player velocity when initiating the dash interrupted
- [ ] keep dashing while rolling but let the player dash in the opposite directions of the roll except the downward dashing

# Bugs
- [x] Player sometimes ignores the dash curve when grounded and directly returns the original gravity (damn how did i fix that)
- [x] dashing while grappling sometimes makes you not able to grapple again
# Animation idea
make it silly looking, let the player use his belly to knock the enemies and his arms and legs behind him wiggling 