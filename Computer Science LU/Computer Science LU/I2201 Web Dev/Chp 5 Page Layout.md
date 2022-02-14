# The Box Model
![[Pasted image 20220103111122.png | 500]]
**Content** area contains things such as text and images. The visible width of the element on a web page is the total of the content width, the padding width and the border width
**Padding** The default padding value is 0. When the background of an element is configured , the background is applied to both the padding and the content.
**Border** Default value is 0. not much to say, each element has its own border that can be edited with the `border` property/
**Margin** determines the empty space between the element and any adjacent elements. 

# The Margin property
To configure the size of the margin, use a numeric value `(px or em)` or a percentage. Use the value auto to indicate that the browser should calculate the margin.
![[Pasted image 20220103112631.png | 500]]
![[Pasted image 20220103112704.png | 400]]
`Usually when you have to adjacent margins, the browser will take the largest margin and display that one only instead in between the elements`

# Normal Flow
Browsers render your web page code line by line in the order it appears in the .html document.

# CSS Float
Elements that seem to float on the right or left side of either the browser window or another element are often configured using the float property. The browser renders these elements using normal flow and then shifts them to either the right or left as far as possible within their container.

`Use float: right; to float the element on the right side of the container.`
`Use float: left; to float the element on the left side of the container.`

Other elements and web page content will flow around the floated element.

# CSS: Clearing a Float
![[Pasted image 20220103113902.png | 500]]

## Clear a float with a line break
![[Pasted image 20220103114106.png | 650]]

# CSS Box Sizing
The box-sizing property causes the browser calculation of the width or height to include the content’s actual width or height in addition to the width or height of any padding and border that may exist.
Valid box-sizing property values include content-box (the default) and border-box.

Use the CSS `box-sizing: border-box;` declaration to configure the browser to also include the values of the border and padding when calculating the width and height properties of an element.

t’s also - common practice to apply box-sizing by configuring the `*` universal selector, which will target all HTML elements, like so: `* { box-sizing: border-box; }`

# CSS Two-Column Layout
![[Pasted image 20220103114800.png | 400]]
 check out the hands on practice in chap 5 pdf

 # Hyperlinks in an Unordered List
 Use the `list-style-type` property to configure the marker for an unordered or ordered list.
 ![[Pasted image 20220103115502.png | 500]]


 # CSS interactivity with Pseudo-Classes
 ![[Pasted image 20220103115745.png | 500]]

# CSS Buttons
![[Pasted image 20220103115915.png | 500]]

# HTML5 Compatibility with Older Browsers
The most basic way to provide for backward compatibility of HTML5 with older, outdated browsers is to configure block display with CSS.

Add one style rule to your CSS to inform older browsers to display HTML5 elements such as header, main, nav and footer as block display (with empty space above and below).

Example CSS follows:
header, main, nav, footer `{ display: block; }`
This technique will work well in browsers including Internet Explorer 9 and later versions.