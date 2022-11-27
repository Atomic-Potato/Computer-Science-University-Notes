# Table overview
![[Pasted image 20220125104345.png | 600]]

`border="1"` attribute renders a default border for the table
`<caption>TableTitle</caption>` will put a title over the table (put it inside the table element)

![[Pasted image 20220125104909.png | 600]]

Example of `colsapn`
```html
<td colspan = "value">Monthly Savings</td>
```
![[Pasted image 20220125104959.png | 200]]

**`Table Header Element`**: The table header element is similar to a table data element and
configures a cell within a row in a table on a web page. Its purpose is to configure column
and row headings. Text displayed within a table header element is centered and bold.
The table header element begins with a `<th>` tag and ends with a `</th>` tag.

# Style a table with CSS
![[Pasted image 20220125105413.png | 600]]
![[Pasted image 20220125105909.png | 600]]

# CSS3 Structural Pseudo-Classes
 CSS3 structural pseudo-class selectors allow you to select and apply classes to elements based on their position in the structure of the document, such as every other row.
 ![[Pasted image 20220125110535.png | 600]]

 # Configure Table Sections
 There are a lot of configuration options for coding tables. Table rows can be put together into three types of groups: table head with **`<thead>`**, table body with **`<tbody>`**, and table footer with **`<tfoot>`**.
 
These groups can be useful when you need to configure the areas in the table in different ways, using either attributes or CSS. The **`<tbody>`** tag is required if you configure a **`<thead>`** or **`<tfoot>`** area, although you can omit either the table head or table footer if you like.

Example
![[Pasted image 20220125111119.png | 300]]
