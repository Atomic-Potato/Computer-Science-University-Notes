# Sequential coloring
**Algorithm for vertex coloring**
- Color the the vertex with the smallest label with one 
- move to the next smallest labeled vertex and color it with a number that is different from all of its neighbor
- and so on till the last vertex

`Note: the chromatic number might change depending on the labeling of the vertices`

# Maximum Color-Degree Coloring
`This algorithm ensures that we get the minimum amount of colors`
- Calculate the number of degrees for each vertex
- assign a pair for each vertex, containing the vertex and its degree
- make a comparison function that compares the pairs depending on their second value
- order the pairs in descending order (if 2 have the same degree, order in ascending order with the vertices labels)
- apply the sequential coloring algorithm starting from the greatest in the list created for the max degrees and delete each vertex that is given a color