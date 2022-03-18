# Latches
## Basic latch
### `active-high `latch
![[Pasted image 20220314131104.png | 600]]
Assuming that the latch is initially `RESET` (Q=0) and `R` and `S` are inactive then to set the latch (Q=1) we pass `HIGH` signal through `S` and to reset a high through `R`

### `active-low` latch
Same concepts of the `active-high` but in reverse
![[Pasted image 20220314131500.png]]

## Gated latch
A gated latch is just a normal `active-low` latch but we just added a `NAND` gate with an enabling signal `EN` to tell the system when to change the latch depending on `R and S`
![[Pasted image 20220314131653.png]]

## `D` latch
The `D` latch is just your normal `S-R` latch but combined into a single input
![[Pasted image 20220314131810.png | 600]]
(I dont think the `EN` is necessary)
Also a simple rule for the above system:
**`Q follows D when the EN is active`**

Truth table:
![[Pasted image 20220314132022.png]]

# Flips flops
Flip flops will only allow a change in the state once theres a change from either `0 to 1 (Positive edge-triggered)` or `1 to 0 (Negative edge-triggered)`, this is done by using a clock `C`
![[Pasted image 20220314133438.png | 600]]

## `D` flip-flop
The truth table for a positive-edge triggered `D flip-flop`
![[Pasted image 20220314133639.png]]
The negative-edge triggered is the same but the arrow is down to remind you when you can switch
![[Pasted image 20220314133720.png]]

## `J-K` flip-flop
This flip flop has two inputs `J` and `K` additional to the clock `C`. When both `J and K = 1`, the output switches states `(toggles)` 
![[Pasted image 20220314134033.png]]

you can also toggle the `D flip-flop` if you hardwire the `Q bar` back to `D`
![[Pasted image 20220314134208.png]]

## Asynchronous inputs
`synchronous`  inputs are the inputs transferred in the triggering edge of the clock (like D or J-K).
`Asynchronous` inputs affect the state output independent of the clock. Theres usually two inputs `PRE` and `CLEAR` which are equivalent to `S` and `R`, which when reached will `SET` the output if its not and `RESET` the output if it is not.
![[Pasted image 20220314134640.png]]