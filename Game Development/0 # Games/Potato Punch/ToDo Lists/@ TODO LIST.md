# Specific Tasks
## Technical
- [ ] Key mapping

## Main
#### Player
- `Code`
	- [ ] Clean it, especially the dash
- `Movement`
	- [ ] Max `-y` velocity
	- [ ] Put the delay timer above the dashes count 
	- [ ] Dashing cancels rolling and dashes (i think i meant grappling)

- `Visuals`
	- [ ] Better square sprite
- `Bugs`
	- [ ] can dash while rolling
	- [ ] keeps rolling when colliding with a wall
	- [ ] dont switch to the companion unless your speed is greater than 1 (thats the fix not the bug)

- [x] [[Grappling Hook]]
- [x] [[Roll]]
- [x] [[Dash]]
- [x] New camera system
- [x] Experiment with making movment slow and making world more compact
#### Enemies & AI
- [x] [[Rocketato]]

##### World
- [x] polish up world text
- [x] Close up the ceilings
- [x] Delay before respawning the player from death colliders
- [x] Create  a small world for the slow player test

#### User interface (UI)
- [x] On scene load animation
- [x] add an icon for dashing delay
- [x] Put in the menu an option to increase the amount of dashes
- [x] change the grappling icon
- [x] change the icons to become above the player
- [x] fix timer appears when unpausing
- [x] fix menu readability 


- `Pause Menu`
	- [x] Add a reload level button
	- [ ] Mute Music Button
	- [ ] Mute SFX Button
	- [ ] Fix the reload scene button
	- [ ] Credits

##### Audio
- `Audio Manager`
	- [x] Setup
	- [ ] PauseWithTag() & PlayWithTag()
	- [ ] FadeOut/InWithTag()
	- [ ] Dynamic Audio that adapts with speed  (Increase speed and pitch as player gets faster and in reverse as he gets slower)
		 https://answers.unity.com/questions/25139/how-i-can-change-the-speed-of-a-song-or-sound.html
- `ambience`
	- [x] wind
	- [x] hawk
	- [x] owl
	- [x] crickets
	- [x] birds
- `SFX`
	- [x] Movement
	- [x] Dashing 
	- [x] Rolling
	- [x] Jumping
	- [x] On Grounded
	- [x] Grappling
	- [x] On Grappling
	- [x] On Grapple Break
	- [x] On Grappling Finish
	- [x] Shooting
	- [x] Ability loaded
	- [ ] High Speed Wind
		
- [x] ambient music 
	- [x] Training area
	- [x] Speed Test area

# Minor Tasks
- [x] Add a UI text saying `"Press escape for controls"`
- [x] Add the new button for grappling in the pause menu
- [x] fix background issues
- [x] remove the rolling end jump canceling