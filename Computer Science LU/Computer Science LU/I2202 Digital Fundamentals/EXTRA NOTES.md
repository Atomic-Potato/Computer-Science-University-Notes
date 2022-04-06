# TECHNIQUES
- Remember to make a truth table when youre asked to draw a circuit or something from chapter 6
- Also in chapter 6, remember after drawing the truth table, compare the results with the input to find any patterns, its better to split the table into chunks
# QUESTIONS CLUES
- **`DESIGN`** = write the expression
- **`IMPLEMENT`** = draw the system

When we say `X` we mean we dont care for the sign of the bit. In `Karnaugh` maps we can use it as either a `0` or a `1` but we dont consider it as a case on its own.

# SHORTCUTS
- **FILLING KARNAUGH MAPS**
![[2.jpg | 200]]
![[1.jpg | 200]]



# DUAL SYMBOLS
If we have to derive an expression from a circuit with a lot of `NAND` gates, 
we can replace the `NAND` gate at each two non consecutive levels a `NOR` gate 
where the bubble are for the input instead of the output
which will cancel the bubbles for the parent `NAND` gates level
and so we wont have to apply De Morgan's theorem to derive the expression anymore 

Note we can do the same if we have `NOR` gates instead of `NANDs`
And this is generally used when we have only `NAND` or `NOR` gates	
![[3.jpg | 600]]

# MEALY & MOORE / State diagram
In both of these systems we have `states` and we start from state `A` till we reach state `Z (END)`  and we move to a state depending on our `input 'x'`
- **`Mealy:`**
In this type we dont need to go to the last state to know that we reached what we are looking for, if we reached the before last state and our current input `x` equals to the last input of the last state then it means we found the pattern we need.
![[Pasted image 20220315151025.png | 600]]
- **`Moore:`**
In this type we need to reach the final state to declare we found the searched pattern instead of comparing the input `x`
![[Pasted image 20220315151058.png | 600]]


Just note that you can construct a state diagram from a state table with the results on the size (z)

# State tables
This is basic state table
The general idea is that `q` is our `current state` and `q*` is the `next state`
![[Pasted image 20220404191958.png | 500 ]]

But when developed / we put in the values for `q1` and `q2`, it becomes like so
![[Pasted image 20220404192133.png | 500]]


What we mean by this table is this system:
![[Pasted image 20220404192211.png]]

So `x` is our `next state` and `z` is our `output`
And `q1 & q2` are the `current states` that depend on the value of `x`, these combined will give us the final result in `z`

Now back to the developed table, this is basically a truth table we can design systems from.
- To design `z` just removed the middle section, and all that you are left with is `q1q2\z` which is the Karnaugh map of `z` (just remember to switch the positions of `10` and `11` since its not in gray code in this order)

## Flip flops with state tables
### D flip flop
we have a property that `D = q*` which will allow us to extract Karnaugh maps to make flip flops
Since we have 2 sub inputs, then it means that we will have a 2 flip flops.
First lets get the `q1*` flip flop, the Karnaugh map is already build for us, we just take both of the `q1` columns and these will be the results of the truth table.
Now we just apply the same steps as above for `z`
![[Pasted image 20220404194520.png]]

Same for `q2*` and we just extract the equation.
![[Pasted image 20220404194223.png | 500]]
`[NOTE THAT IF YOU HAVE 3 STATES OR MORE YOU DONT PUT THE WHOLE COLUMN, YOU START TAKING A NUMBER FROM THE FIRST COLUMN, THEN THE OTHER FROM THE SECOND COLUMN, AND CONTINUE JUST LIKE IN #SHORTCUTS]`

And we draw the system with the equations, note that `D` is the input and `q & q bar` are the output.
![[Pasted image 20220404194629.png | 500]]

### Other flip flops
First just draw the state diagram for the desired flip flop (`T is the tooggle flip flop`)
![[Pasted image 20220404200618.png | 500]] 

Now you can fill the truth table for each flip flop
For the first flip flop in the state `q1*` you just take the current state `q1` and the next state `x` and see where it takes in you in the above diagram and put the result in the same column for `x`
Same for the state `q2*`
![[Pasted image 20220404201111.png | 600]]

And now the reset can be done the same as a `D-flip flop`
Just not that for the S we take the first column in each x value and for the R we take the second column in each x value. Because remember these are the results that we took from the diagram.

Same thing can be done on `JK` but theres a faster way

#### **FINDING J-K FOR EACH FLIP-FLOP**
- First we fill the Karnaugh map for each `state` 
- Second you mark the territory where the output of the `state` (A*, the state will be A, q1*, the state will be q1) is `0` in the map
- Third in the marked area you find the `SOP` as normally `[DONT USE ANYTHING FROM OUTSIDE THE MARKED AREA]` and this will be the `J` of the current flip-flop
- Fourth in the unmarked area we consider the `0s` to be `1s` and vice versa, and we find the `SOP` of these new `1s` and that will be the `K` of the current flip-flop
- `[NOTE THAT IF WE FIND IN THE EQUATON AN INPUT THAT IS EQUAL TO THE OUTPUT WE SIMPLY IGNORE IT BY REPLACING IT WITH 1]`
	![[Pasted image 20220315152807.png | 600]]
	  
All of this is derived from this equation
![[4 2.jpg | 200]]

## Dealing with an xxx case
If youre asked to determine next case of an input where the current case is not relevant. All you have to do is after extracting the design of the clock, you just fill this case into the equations, and put the results into a table
![[Pasted image 20220405000429.png | 500]]
And as in example, here Ja and Ka toggles the current input, so we will get A* as 0