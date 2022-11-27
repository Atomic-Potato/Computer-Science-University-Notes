`Terminals:` vertices with either only in or out degree
`intermediate:` vertices with both in and out degrees
`cpacity c(e)` is the max weight of an edge

`legal flow f:`
![[Pasted image 20220211155447.png | 600]]
(s and t are source and sink)

`total flow F` in a network N is defined to be the flow out of the source s, or, equivalently, the flow into the sink t; that is:
![[Pasted image 20220211155745.png | 350]]

`slack:` c(e) - f(e)
`saturated:` slack(v) = 0