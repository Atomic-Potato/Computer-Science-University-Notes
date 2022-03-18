# QUESTIONS CLUES
- **`DESIGN`** = write the expression
- **`IMPLEMENT`** = draw the system

When we say `X` we mean we dont care for the sign of the bit. In `Karnaugh` maps we can use it as either a `0` or a `1` but we dont consider it as a case on its own.

# SHORTCUTS
- **FILLING KARNAUGH MAPS**
![[2.jpg | 200]]
![[1.jpg | 200]]

- **FINDING J-K FOR EACH FLIP-FLOP**
	- First we fill the Karnaugh map for each flip-flop
	- Second you mark the territory where the output of the flip-flop is `0` in the map
	- Third in the marked area you find the `SOP` as normally `[DONT USE ANYTHING FROM OUTSIDE THE MARKED AREA]` and this will be the `J` of the current flip-flop
	- Fourth in the unmarked area we consider the `0s` to be `1s` and vice versa, and we find the `SOP` of these new `1s` and that will be the `K` of the current flip-flop
	- `[NOTE THAT IF WE FIND IN THE EQUATON AN INPUT THAT IS EQUAL TO THE OUTPUT WE SIMPLY IGNORE IT BY REPLACING IT WITH 1]`
	![[Pasted image 20220315152807.png | 600]]
	  
All of this is derived from this equation
![[4 2.jpg | 200]]

# DUAL SYMBOLS
If we have to derive an expression from a circuit with a lot of `NAND` gates, 
we can replace the `NAND` gate at each two non consecutive levels a `NOR` gate 
where the bubble are for the input instead of the output
which will cancel the bubbles for the parent `NAND` gates level
and so we wont have to apply De Morgan's theorem to derive the expression anymore 

Note we can do the same if we have `NOR` gates instead of `NANDs`
And this is generally used when we have only `NAND` or `NOR` gates	
![[3.jpg | 600]]

# MEALY & MOORE
In both of these systems we have `states` and we start from state `A` till we reach state `Z (END)`  and we move to a state depending on our `input 'x'`
- **`Mealy:`**
In this type we dont need to go to the last state to know that we reached what we are looking for, if we reached the before last state and our current input `x` equals to the last input of the last state then it means we found the pattern we need.
![[Pasted image 20220315151025.png | 600]]
- **`Moore:`**
In this type we need to reach the final state to declare we found the searched pattern instead of comparing the input `x`
![[Pasted image 20220315151058.png | 600]]

