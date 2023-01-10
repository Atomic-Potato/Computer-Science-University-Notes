_Next [[🟩3 @ Widget Box Model]]_
_Previous [[🟩1 @ Layouts]]_

--- 

- `gravity:` used to center the content of view horizontally or vertically. 
	Takes these values: 
	- `center_horizontal` 
	- `center_vertical`
	- `center` 
	You can also add the keywords `right`, `left`, `top` or `bottom`  to justify the content in that direction like so: `center | right` _(Note that you can replace center with any of the other values or remove it entirely)_

- `layout_gravity:` centers the view either horizontally or vertically. 
	Takes these values: 
	- `center_horizontal` 
	- `center_vertical`
	- `center` 

- `layout_weight:` This specifies how much the view should take from the screen _(vertically only i think)_. Say for example all views have a weight of 0, this means all of them will just take their normal size. Say theres only one view and it has a weight of 1, then it will stretch to fill the whole screen, say theres 3 views, _A_ with weight _1_, _B_ with weight _1_, _C_ with weight _2_. Then the screen will be split into 4 parts _(1+1+2)_ and A will stretch to fit one part, B as well, and C will stretch to fill 2 parts of the screen
	![[Pasted image 20230110164337.png|500]]

- `orientation:` displays the elements inside this view either _horizontal_ or _vertical_

---

_Next [[🟩3 @ Widget Box Model]]_
_Previous [[🟩1 @ Layouts]]_