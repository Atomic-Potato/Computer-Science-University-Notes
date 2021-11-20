# Steps
[] Make an animation for rolling
[] Make the rolling animation start once the player has finished a fall and is being grounded and is holding `S`
[] Keep the rolling going while the player is holding `S` and `isGrounded`
[] Apply movement in the direction of the fall horizontally and the player cannot switch directions while rolling
[] Let the movement start from a high speed and use `SmoothDamp()` to slow it down to `0`
[] Stop the rolling if the player reaches `0` velocity
[] Stop the rolling if the player falls off an edge
[] Stop the rolling if the player jumps and give him a stronger jump force than the normal force
[] If the roll velocity is `<=` half (subject to change) the original the start speed then apply the normal jump force