# Its worthless now

# Discord message
```
alright so whenever i know that i will probably be doing something hard i stop working on the game because im afraid of it (i do it unconsciously) and i wanna stop this now
So if you dont know the grappling hook is almost done and heres a video showcasing it but the only thing left is to create a grappling string. I just want to spawn a sprite from the player to the grappling anchor, no fancy animation stuff. 
I just want you to read my way and tell me if theres an easier way to do this.

Alright so the thing would be simple if the spring sprite was just a solid color or some sprite that doesnt get affected when stretched but i want a sprite that doesnt work if stretched (like the one i will send after this message).
So i was thinking by making a game object for a part of the string and spawning 
```

# Thinking section 

I dont really want the line to pop out of nowhere so it will start expanding from the player to the anchor, and as it expands it will generate string segments, alright so that we dont go with this randomly lets start from the moment the player right click to an anchor to the moment he releases.
**Setting up**
- Give the player an empty game object in his center with a trigger collider (call it player point)
- Do the same for the anchor point (call the object anchor point)
- Make a game object for one segment of the string which has a trigger collider and the sprite of the segment
- Set the pivot point of the sprite to the bottom of the sprite
Note that the string sprite will be behind the player and the anchor sprites so both of ends of the strings dont really need to be right on each empty trigger objects mentioned above
**What happens when the player right clicks on an anchor point?**
- We create an array to store all the string segments game objects (Call it segmentsArray[])
- We spawn the first segment as a child of the player from the "Player Point" and with some velocity that keeps getting directed towards the "Anchor point" and add this segment object to our array `segmentsArray[]`
- Once this first segment exits contact with the "Player point" we get the pivot point position of the sprite and spawn a new segment object on the pivot point + the length of the sprite / 2 (note: we can just use another empty game object instead of using the pivot location), and add this segment object to the end of the `segmentsArray[]`
   `Note: remember to only spawn it once`
- Keep repeating the process until the first segment `segmentsArray[0]` is in contact with the "Anchor Point". Once this happens we now disable all of the above and start a new function for deleting the segments.
- So if the first segment is connected, we see if the player is approaching the "Anchor point" and if the "Player Point" has collided with the last gameObject in the array, then we destroy that segment.
- if the player is getting away (note that the string is still connected), and if the "Player Point" has collided with something that is != to a string segment then we spawn a string segment at the end point of the last string segment object in the array (This is not necessary but just in case it happens)
- Once done grappling we destroy all the objects in the array