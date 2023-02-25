_Next [[🟩4 @ Dynamic Routing Algorithms]]_
_Previous [[🟩2 @ Routing]]_

---

Static routing provides some advantages over dynamic routing, including:
- Static routes are not advertised over the network, resulting in better security.
- Static routes use less bandwidth than dynamic routing protocols.
- The path a static route uses to send data is known.

![[Pasted image 20230225103916.png|600]]

# When to Use
Static routing has three primary uses:
- Providing ease of routing table maintenance in smaller networks.
- Routing to and from stub networks. _(A stub network is a network accessed by a single route, and the router has no other neighbors.)_
- Using a single default route to represent a path to any network that does not have a more specific match with another route in the routing table.

![[Pasted image 20230225104224.png|400]]

## Applications
Static Routes are often used to:
- Connect to a specific network.
- Provide a Gateway of Last Resort for a stub network.
- Reduce the number of routes advertised by summarizing several contiguous networks as one static route.
- Create a backup route in case a primary route link fails.

# Types of Static Routes

## Default Static Route
A default static route is a route that matches all packets. 

It identifies the gateway IP address to which the router sends all IP packets that it does not have a learned route or a static route.

A default static route is simply a static route with 0.0.0.0/0 as the destination IPv4 address.
![[Pasted image 20230225110453.png]]

## Summary Static Routes
Multiple  static routes can be summarized into a single network address. 
Just note that the destination networks must be contiguous and these static routes must use the same exit interface / next hop.
![[Pasted image 20230225104547.png|600]]

## Floating Static Routes
A floating static route is a backup route that is used only when the primary route is unavailable. 
It is a type of static route with a **higher administrative distance than the primary route.**
![[Pasted image 20230225110857.png|700]]

---

# Configuring Static and Default Routes
In the following we will see how to configure IPv4 static routes
_(I think the following commands only work on Cisco routers)_

## `ip route` Command
```
Router(config)# ip route network-address subnet-mask {ip-address | exit-intf}
```
![[Pasted image 20230225112454.png]]

# Next-Hop Options
The next hop can be identified by an IP address, exit interface, or both.
How the destination is specified creates one of the three following route types:
- `Next-hop route:` Only the next-hop IP address is specified.
  ![[Pasted image 20230225112928.png|600]]
- `Directly connected static route:` Only the router exit interface is specified.
![[Pasted image 20230225113026.png|900]]
- `Fully specified static route:`  The next-hop IP address and exit interface are specified.

## Verifying a Static Route
We can use the following commands to verify a static route:

![[Pasted image 20230225113333.png]]

```
Router(config)# show ip route static | begin Gateway
```
![[Pasted image 20230225113417.png]]

```
Router(config)# show ip route ip-address 
```
![[Pasted image 20230225113516.png]]

```
Router(config)# show running-config | section ip route
```
![[Pasted image 20230225113626.png]]

## Default Static Route
Default static route syntax:
```
Router(config)# ip route 0.0.0.0 0.0.0.0 {ip-address | exit-intf}
```
![[Pasted image 20230225113814.png]]

To verify a default static route use the command:
```
Router(config)# show ip route static
```

## Configuring an IPv4 Floating Static Route
![[Pasted image 20230225114220.png]]

To test a floating static route:
- Use the `show ip route` command to verify that the routing table is using the default static route.
- Use the `traceroute` command to follow the traffic flow out the primary route.
- Disconnect the link or shutdown the primary interface(s). _(In the curriculum example the serial interfaces on R2 are shutdown.)_
- Use a `show ip route` command to verify that the routing table is using the floating static route.
- Use a `traceroute` command to follow the traffic flow out the backup route.

## Troubleshooting a Missing Route
IOS troubleshooting commands include:
- `ping`: Extended ping enables you to specify the source IP address for the ping packets.
- `traceroute`
- `show ip route`
- `show ip interface brief`
- `show cdp neighbors detail`

### Solving a connectivity problem
Finding a missing _(or misconfigured)_ route requires using the right tools in a methodical manner.

Use the `ping` command to confirm the destination can’t be reached.

A `traceroute` would also reveal the closest router _(or hop)_ that fails to respond as expected. In this case, the router would then send an [[🟩1 @ ICMP & Trace Route|Internet Control Message Protocol (ICMP)]] destination unreachable message back to the source. 

The next step is to investigate the routing table using the `show ip route` command. Look for missing or misconfigured routes.

Incorrect static routes are a common cause of routing problems.

---
_Next [[🟩4 @ Dynamic Routing Algorithms]]_
_Previous [[🟩2 @ Routing]]_