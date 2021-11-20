- Velocity never reaches 0 while using smooth damp
```
Put full friction when idle
```
- Velocity on the y axis is never 0 while moving
```
if you are using composite colliders for the tilemap, set the "Offset distance value" to 0
```
- if you want to have a custom 2D sprite material then create a standard material and assign the sprite to the to the *Albedo* variable and then switch the shader to *"Sprites->Default"*