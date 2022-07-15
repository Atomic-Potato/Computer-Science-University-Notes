```python
%matplotlib inline
import matplotlib.pyplot as plt
networkx.draw(G)
#it will give an image of the graph
```

```python
import pygraphviz as pgv
d={'1': {'2': None}, '2': {'1': None, '3': None}, '3': {'1': None}}
A = pgv.AGraph(data=d)
print(A) # This is the 'string' or simple representation of the Graph
```
![[Pasted image 20220211130037.png]]

```python
from google.colab.patches import cv2_imshow
from google.colab.patches import cv2

# Let us create another Graph where we can individually control the colour of each node
B = pgv.AGraph()

# Setting node attributes that are common for all nodes 
B.node_attr['style']='filled'
B.node_attr['shape']='circle'
B.node_attr['fixedsize']='true'
B.node_attr['fontcolor']='#FFFFFF'

# Creating and setting node attributes that vary for each node (using a for loop)
for i in range(16):
 B.add_edge(0,i)
 n=B.get_node(i)
 n.attr['fillcolor']="#%2x0000"%(i*16)
 n.attr['height']="%s"%(i/16.0+0.5)
 n.attr['width']="%s"%(i/16.0+0.5)

B.draw('star.png',prog="circo") # This creates a .png file in the local directory. Displayed below.
img = cv2.imread("star.png")
cv2_imshow(img )# The Graph visualization we created above.
```
![[Pasted image 20220211130248.png | 400]]
