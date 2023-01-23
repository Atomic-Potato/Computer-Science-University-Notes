_Next [[🟩4 @ Composite Pattern]]_
_Previous [[🟩2 @ Flyweight Pattern]]_

---
`Bridge` pattern decouples an **abstraction** from its **implementation** so that the two can vary independently.

In this pattern, the `abstract class` is separated from the `implementation class` and we provide a bridge `interface` between them. This interface helps us to make concrete class functionalities independent from the interface implementer class. We can modify these different kind of classes structurally without affecting each other.

# Problem
![[Pasted image 20230122171105.png|700]]
>- Remote is an abstract class. It contains:
>	• an instance variable sound
>	• methods **soundUp** and **soundDown**
>	• two abstract methods **onPressMiddle** and **onPressNine**
>- If it is remote for TV: **onPressNine** > go to the channel nine.
>- remote for DVD: **onPressNine** > pause.
>- Sony remote: **onPressMiddle** > open menu.
>- If it is Toshiba remote: **onPressMiddle** > turn off.

The problem with this implementation is if we wanted to add a new type, say LCD. Then we have to create three new data types _(RemoteLCD, RemoteLCDSony, RemoteLCDToshiba)_. **Which will result in methods duplication / code redundancy.**  And we hate that cuz its annoying.

## Example code
![[Pasted image 20230122171555.png|450]]
![[Pasted image 20230122171608.png|450]]
![[Pasted image 20230122171616.png|450]]

# Solution
![[Pasted image 20230122171630.png | 700]]

The `Bridge` pattern attempts to solve this problem by **switching from inheritance to the object composition.** What this means is that you extract one of the dimensions into a separate class hierarchy, so that the original classes will reference an object of the new hierarchy, instead of having all of its state and behaviors within one class.

## Example Solution Code
![[Pasted image 20230122171810.png|550]]
![[Pasted image 20230122171822.png|550]]
![[Pasted image 20230122171849.png|550]]
![[Pasted image 20230122171858.png|550]]

# Structure
![[Pasted image 20230122171913.png|600]]

---
_Next [[🟩4 @ Composite Pattern]]_
_Previous [[🟩2 @ Flyweight Pattern]]_