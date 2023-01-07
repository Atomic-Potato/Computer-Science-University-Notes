_Next [[🟩3 @ Event Handling]]_
_Previous [[🟩1 @ Views]]_

---

# Editor main toolbar
![[Pasted image 20230107145017.png|500]]
1. `Select Design Surface:` Design and Blueprint panes
2. `Orientation in Editor: `Portrait and Landscape
3. `Device in Editor:` Choose device for preview
4. `API Version in Editor:` Choose API for preview
5. `Theme in Editor:` Choose theme for preview _(These handle things like shape and color, top bar that says the name of the app)_
6. `Locale in Editor:` Choose language/locale for preview

# ConstraintLayout toolbar 
![[Pasted image 20230107145159.png | 500]]
1. `Show:` Show Constraints and Show Margins
2. `Auto-connect:` Enable or disable
3. `Clear All Constraints:` Clear all constraints in layout
4. `Infer Constraints:` Create constraints by inference
5. `Default Margins:` Set default margins
6. `Pack:` Pack or expand selected elements
7. `Align:` Align selected elements
8. `Guidelines:` Add vertical or horizontal guidelines
9. `Zoom controls:` Zoom in or out

## Attributes pane

![[Pasted image 20230107145436.png]]

![[Pasted image 20230107145454.png]]

1. Vertical view size control specifies `layout_height`
2. Horizontal view size control specifies `layout_width`
3. Attributes pane close button

### `layout_width` and `layout_height`
`layout_width` and `layout_height` change with size controls
- `match_constraint`: Expands element to fill its parent
	![[Pasted image 20230107145655.png|50]]
- `wrap_content`: Shrinks element to enclose content
![[Pasted image 20230107145722.png|50]]
- Fixed number of `dp` (density-independent pixels)
![[Pasted image 20230107145741.png|50]]

--- 

# Creating a different layout for different screen sizes and orientations

## Landscape
1. Click Orientation in Editor button
2. Choose Create Landscape Variation
3. Layout variant created: `activity_main.xml (land)`
4. Edit the layout variant as needed

![[Pasted image 20230107150022.png|200]]

## Tablet
Same as for Landscape but choose: _Create layout x-large Variation_

---
_Next [[🟩3 @ Event Handling]]_
_Previous [[🟩1 @ Views]]_
