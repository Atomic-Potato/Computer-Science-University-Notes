# Configuring Lines and Borders
`Horizontal rule element <hr>` (void element)
Just puts a line across the page 

`Border property`
It puts a border around the element, by default the width is 0. You can set the border-width/color/style.

`Pading Property`
The padding is the empty space between the border and the components of the element. You can configure it with padding-bottom/top/left/right
==Note: the margin is the empty space between the border and the browser border==

# Types of graphics
## `GIF | Graphic Interchange Format image`
GIFs support transparency and can only contain 256 colors
GIFs can play animation frames and get compressed while saved meaning they will get smaller in size and when used will unpack the original data to have the same pixel size as the original
Theres also optimization which is balancing between the file size and the quality

## `JPEG`
![[JPEG.jpg | 500]]

## `PNG and WEBP`
![[PNG and WEBP.jpg | 500]]

# Image element
Its a void element
```html
<img src="logo.gif" height="200" width="500" alt="My Company">
```
We should put the gif in the same folder of the html file to avoid putting the path
The alt is the text displayed if no image is found

We can also use an image as a hyperlink
```html
<a href="index.html"><img src="home.gif" height="19" width="85" alt = "Home"></a>
```

# HTML5 Visual Elements
To put an image caption you could put the image inside a `<div>` and put the text inside it and center it.
Or we could use `<figcaption>`
![[figcaption.jpg | 300]]
![[figcaption example.jpg | 500]]

`Meter element`
```html
<meter value="69" min="0" max"420">69</meter>Text<br>
```
<meter value="69" min="0" max"420">69</meter>Text
Theres also `progress element` which is quite similar

`Favorite Icon`
Put in the head element
```html
<link rel="icon" href="favicon.gif" type="image/ico">
```

# Background image
```html
body{background-image: url(texture1.png); background-repeat : no repeat}
```
by default the image keeps repeating itself

# CSS3 opacity Property
The transparency property ranges from 0 (transparent) to 1 (non transparent)
```html
h1{bacground-color: #FFFFFF; opacity: 0.6;}
```

# Plug-ins, Containers, and Codecs 
Common Plug-ins
![[common plug-ins.jpg | 500]]

Codecs and containers
![[containers and codecs.jpg|500]]
![[video containers.jpg|500]]

# Getting Started with Audio and Video
![[hyperlink to video.jpg| 500]]

`Audio element`
![[audio tag.jpg | 500]]
![[example of audio tag.jpg |500 ]]
==Having multiple sources lets the browser use the one it supports==

`Video element`
![[video element.jpg | 650]]
![[video example.jpg | 650]]