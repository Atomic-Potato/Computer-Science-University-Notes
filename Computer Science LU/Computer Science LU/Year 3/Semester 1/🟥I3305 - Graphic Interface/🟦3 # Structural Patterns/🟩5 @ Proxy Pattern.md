_Next [[🟩6 @ Adapter Pattern]]_
_Previous [[🟩4 @ Composite Pattern]]_

---
`Proxy` is a structural design pattern that lets you **provide a substitute or placeholder for another object**. 
A **proxy controls access to the original object**, allowing you to perform something either before or after the request gets through to the original object.

Types of proxies
- `Remote proxy:` local representative of an object located in a different address space _(Web Services, ...)_
- `Virtual proxy:` create an expensive object if needed only
- `Protection proxy:` controls access to the original object
- `Smart Proxy:` A smart proxy provides additional layer of security by interposing specific actions when the object is accessed.

# Problem
A very simple real life scenario is our college internet, which restricts few site access. The proxy first checks the host you are connecting to, if it is not part of restricted site list, then it connects to the real internet. This example is based on Protection proxies.

_(This is a protection proxy problem)_

# Solution
**The Proxy pattern suggests that you create a new proxy class with the same interface as an original service object. Then you update your app so that it passes**
![[Pasted image 20230210140647.png|300]]

The `Service Interface` declares the interface of the Service. The proxy must follow this interface to be able to disguise itself as a service object.

The `Proxy class` **has a reference field that points to a service object**. After the proxy finishes its processing _(e.g., lazy initialization, logging, access control, caching, etc.)_, it passes the request to the service object.

The `Service` is a class that provides some useful business logic. _(It is the actual object)_

## Example Solution
![[Pasted image 20230210140955.png|600]]
![[Pasted image 20230210141014.png|500]]
![[Pasted image 20230210141034.png|450]]

---

_Next [[🟩6 @ Adapter Pattern]]_
_Previous [[🟩4 @ Composite Pattern]]_
