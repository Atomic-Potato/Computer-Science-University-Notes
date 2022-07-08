# Asynchronous Counters
These counters count for each column of bits depending on the previous column of bits, so theres a delay for each column counting

## Three bit Asynchronous Counter
In this counter we use the `Q bar` from the previous flip-flop as a clock for the next flip-flop, thus the result for each flip-flop alters every new clock time of the previous but doubled
![[Pasted image 20220314142118.png | 600]]
![[Pasted image 20220314142242.png | 600]]

if we want for example to reset the counter back to `0000` when we reach `1001` in a 4-bit counter, all we have to do is go to the next number `1010` and just make a `CLR` asynchronous input when `Q3 = 1` and `Q1 = 1` 
![[Pasted image 20220314142520.png | 600]]

# Synchronous Counters
These counters count for each column without the need for multiple clocks for each column, thus theres no delay in counting.

## Three bit counter
![[Pasted image 20220314143004.png | 600]]

We use a table to represent the counting for this counter.
Start by setting up the outputs as shown then write the logic equation for each input.
- Put the counter in an arbitrary state; then determine the inputs for this state
- Use the new inputs to determine the next state: Q2 and Q1 will latch and Q0 will toggle.
- Set up the next group of inputs from the current output.
  ![[Pasted image 20220314144634.png | 600]]

==**THE FOLLOWING COUNTERS ARE NOT REQUIRED FOR MEMORIZING**==
## BCD decade counter
![[Pasted image 20220314145111.png | 600]]

## Up/Down counters
![[Pasted image 20220314145200.png | 600]]
