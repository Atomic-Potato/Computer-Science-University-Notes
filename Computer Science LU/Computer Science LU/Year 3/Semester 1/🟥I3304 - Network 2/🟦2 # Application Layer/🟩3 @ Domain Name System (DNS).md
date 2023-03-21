_Previous [[🟩2 @ FTP]]_

---

In a nutshell, the DNS maps an IP address to a domain name. So the client asks the DNS server whats the IP address of this domain name and the DNS responds with one or multiple IPs for this domain _(multiple ones to handle the load on this website)_.

# DNS services
- hostname to IP address translation
- host aliasing: canonical, alias names
- mail server aliasing
- load distribution: Many IP addresses correspond to one name to reduce load on the same IP.

# Distributed & Hierarchical Database
There are many DNS servers, and each one handles a domain and the websites on it.
![[Pasted image 20230224100040.png]]

How to find the IP of a host name: _(say we are looking for amazon.com)_
- client queries root server to find .com DNS server 
- client queries .com DNS server to get amazon.com DNS server
- client queries amazon.com DNS server to get IP address for www.amazon.com 

DNS servers locations:
![[Pasted image 20230224100450.png]]

Issues of centralizing the DNS server:
- The internet shuts down if the DNS server fails
- Too much traffic
- Will be too far from many countries
- Will need constant maintenance

# TLD &  Authoritative Servers
- `top-level domain TLD servers:` 
  Responsible for com, org, net, edu, aero, jobs, museums, and all top-level country domains.
  Network Solutions maintains servers for .com TLD 
  Educause for .edu TLD 
- `authoritative DNS servers:`
  Organization's own DNS server(s), providing authoritative hostname to IP mappings for organization's named hosts. They can be maintained by organization or service provider 

# DNS name resolution
Say a host at cis.poly.edu wants IP address for gaia.cs.umass.edu
## Iterated query
Contacted server replies with name of server to contact _("idk this name, but ask this server")_
![[Pasted image 20230224102125.png|400]]

## Recursive Query
Puts burden of name resolution on contacted name server. _This will probably put heavy load at upper levels of the hierarchy_
![[Pasted image 20230224102636.png|400]]

# DNS records
The DNS is a database after all, and when requesting an IP, the following query format is used: _(hopefully that made sense, also TTL is time to live)_ 
![[10.png|700]]

# Load Balancing
The basic idea of DNS load balancing is to distribute incoming client requests across multiple servers by using multiple IP addresses for a single domain name.

The DNS load balancing process typically involves the following steps:

1.  The domain owner creates multiple A records with the same name but different IP addresses in the DNS server. These IP addresses correspond to the multiple servers that will handle client requests.
2.  When a client sends a DNS query for the domain name, the DNS resolver randomly selects one of the IP addresses associated with the domain name and returns it as the answer to the client. The client uses this IP address to establish a connection to the server.
   
The server then handles the client request and sends back the response. Since the DNS resolver randomly selected one of the IP addresses associated with the domain name, the load is distributed across the multiple servers.

---
_Previous [[🟩2 @ FTP]]_
