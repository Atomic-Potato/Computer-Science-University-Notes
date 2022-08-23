# Steps
[x] Make an animation for rolling
[x] Make the rolling animation start once the player has finished a fall and is being grounded and is holding `S`
[x] Keep the rolling going while the player is holding `S` and `isGrounded`
[x] Apply movement in the direction of the fall horizontally and the player cannot switch directions while rolling
[x] Let the movement start from a high speed and use `SmoothDamp()` to slow it down to `0`
[x] Stop the rolling if the player reaches `0` velocity
[x] Stop the rolling if the player falls off an edge
[x] Stop the rolling if the player jumps and give him a stronger jump force than the normal force
[x] Make it that when the player hits the ground he can release the button `S` and will only stop rolling if interrupted by a rocket or jumped or received input in the opposite direction of the roll
[x] Disable shooting while dashing for both comp and player
