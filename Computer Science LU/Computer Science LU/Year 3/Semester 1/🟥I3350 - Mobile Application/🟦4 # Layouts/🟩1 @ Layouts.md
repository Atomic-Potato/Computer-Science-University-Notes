_Next [[🟩2 @ Attributes]]_

---

# LinearLayout
Lays out widgets/views on a single line with either a **horizontal** or a **vertical** orientation _(Note that items do not wrap if the reach the edge of the screen)_
![[Pasted image 20230110163109.png|100]]
![[Pasted image 20230110163121.png|100]]

# GridLayout
_This layout replaces `TableLayout`_
Lays out widgets/views in lines of rows and columns. The `orientation` attribute defines `row-major` or `column-major`, i.e. if the new widget will be added row by row or column by column.

Each widget is placed into the next available row/column index unless it is given an explicit `layout_row` and `layout_column` attribute.
We can specify how many rows/columns exist using the `rowCount`/`columnCount` attributes. 
To make columns/rows span over multiple cells we use the `layout_columnSpan`/`layout_rowSpan` attributes.

![[Pasted image 20230110170508.png|100]]

# RelativeLayout
_Very similar to ConstraintLayout_
Each widget's position and size is relative to other views.
- Relative to parent
- other widgets/views
- x-positions of reference: left, right, center
- y-positions of reference: top, bottom, center

**Its intended to reduce the need for nested layouts**

![[Pasted image 20230110171020.png|700]]

## Relative Anchor Points
- Attributes for x/y relative to another widget:
	`layout_X` _(X can be: below, above, toLeftOf, toRightOf)_. Set the value of this attribute to the ID of another widget in the format: **"@id/theID"**
- Attributes for x/y relative to layout container _(the activity):_
	- `layout_alignParentX` _(X can be: Top, Bottom, Left, Right)_. This attribute is a flag _(boolean)_, set it as **"true"** to enable it
	- `layout_centerX` _(X can be: Horizontal, Vertical, InParent)_. This attribute is a flag _(boolean)_, set it as **"true"** to center the control within its parent in a dimension.

# FrameLayout
Meant to hold **only a single widget** inside, which occupies the entirety of the activity. Most commonly used with layout fragments. 

It is used more like to stack activities. Sort of like how you swipe between left and right tabs.

---
_Next [[🟩2 @ Attributes]]_