_Next [[🟩2 @ FTP]]_

---

Web page consists of **objects.**  An object can be: _HTML file, JPEG image, Java applet, audio file,..._ 
Web page consists of base HTML-file which includes several referenced objects. **Each object is addressable by a URL** .
Example URL:
![[Pasted image 20230223192558.png|400]]

# HTTP Overview
HTTP: hypertext transfer protocol

Its a client/server application where:
- **Client:** is a browser that requests, receives, "displays" Web objects 
- **Server:** Web server sends objects in response to requests
![[Pasted image 20230223193056.png|300]]

Theres multiple versions of HTTP:
- HTTP 1.0: RFC 1945 
- HTTP 1.1: RFC 2068 

HTTP uses [[🟩5 @ Transmission Control Protocol (TCP)|TCP]] with the following steps: 
- client initiates TCP connection _(creates socket)_ to server _(port 80 by default)_. 
- The the server accepts TCP connection from client 
- HTTP messages _(application-layer protocol messages)_ exchanged between browser _(HTTP client)_ and Web server _(HTTP server)_ 
- Finally TCP connection is closed 

HTTP is _"stateless"_, i.e. server maintains no information about past client requests.

# HTTP Connection
There are 2 types of HTTP connections:
- `Non-persistent HTTP:` Where at most one object is sent over a TCP connection. 
- `Persistent HTTP:` Where Multiple objects can be sent over single TCP connection between client and server. 

## Non-persistent HTTP
When you enter the following URL to your navigator: www.ul.edu.lb/files/lecture3.html _(or any URL, this is just an example)_, the following happens:
1. Step 1:
	- HTTP client initiates TCP connection to HTTP server _(process)_ at www.ul.edu.lb on port 80 _(the default port)_ 
	 - HTTP server at host www.ul.edu.lb waiting for TCP connection at port 80. _"accepts"_ connection, notifying client
 2. HTTP client sends HTTP request message _(containing URL)_ into TCP connection socket. A message indicates that client wants object _files/lecture3.html_
 3. HTTP server receives request message, forms a **response message** containing requested object, and sends a message into its socket
 4. HTTP client receives response message containing html file, and displays html. Parsing the html file, it finds 10 referenced _jpeg_ objects.
 5. HTTP server closes TCP connection
 6. Steps 1-5 repeated for each of the 10 jpeg objects

### Response time
To check for `RTT` _(round trip time)_, a small packet is sent to the client and the round trip time is measured.

`Response time:` To check for response time, several things are checked: 
- one RTT to initiate TCP connection 
- one RTT for HTTP request and first few bytes of HTTP response to return 
- file transmission time 
And the response time total would be `= 2RTT + transmit times` 

The issues with this: 
- requires 2 RTTs per object 
- OS overhead for each TCP connection
- browsers often open parallel TCP connections to fetch referenced objects 

## Persistent HTTP
In persistent HTTP, the server leaves connection open after sending the response message.

There are 2 types of persistence:
- `Without pipelining:` client issues new request only when previous response has been received. I.E. one `RTT` for each referenced object
- `With pipelining:` client sends requests as soon as it encounters a referenced object. I.E. as little as one `RTT` for all the referenced objects.

# HTTP Methods
- `GET` : check out the php course 
- `POST` : check out the php course
- `HEAD` : asks server to leave requested object out of response
- `PUT` : uploads file in entity body to path specified in URL field
- `DELTE` : deletes file specified in the URL field.

Anyways only GET and POST are important

## Uploading from input
To upload 


## HTTP Request message: general form
![[Pasted image 20230223195612.png|500]]

There are 2 types of HTTP messages: **Requests and Responses**

An example of an HTTP request message _(It is also in ASCII, i.e. human readable format)_
![[Pasted image 20230223195746.png|500]]

An example of an HTTP response message _(It is also in ASCII, i.e. human readable format)_
![[Pasted image 20230223195818.png|500]]
You can notice a _"200 OK"_ in the status line, this is the status code, and there several ones:
![[Pasted image 20230223200206.png|500]]

# Misc. Webb Stuff

## TELNET
Telnet is a tool to connect to a remote computer. It can also be used to communicate with a web server. 

Telenet does this by doing the following:
1. Opens a TCP connection with the server
2. Reads from the keyboard and sends directly to the server
3. Reads from the connection _(TCP)_ and writes to the server.

To use telnet type `telnet www.ul.edu.lb 80` in cmd _(80 is used to specify a port number. HTTP uses port 80. By default Telnet uses port 23)_. And then try using the GET command.

## Cookies
![[t9y87m5f0pz41.webp | 250]]
![[Pasted image 20230223204215.png | 500]]

Example of cookies:
![[Pasted image 20230223204303.png | 500]]

# Web cache
Basically it is saving the content of a page into the clients computer / browser for it to be used later for faster access.

The problem with this though that we dont know if the data is different in the database.
In that case we can just get the last modified date of the page the first time it enters the cache, and the second time we include an if statement in the URL to check the difference of the last modified to see if we need to update the page _(download the page / update the cache)_ or just load the page from the cache
![[Pasted image 20230223204751.png | 600]]

---
_Next [[🟩2 @ FTP]]_
