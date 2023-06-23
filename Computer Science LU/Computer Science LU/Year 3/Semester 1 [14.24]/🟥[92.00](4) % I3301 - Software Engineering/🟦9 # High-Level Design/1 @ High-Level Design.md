High‐level design provides a **view of the system at an abstract level.** It shows how the major pieces of the finished application will fit together and interact with each other.

**The high‐level design does not focus on the details of how the pieces of the application will work.**

Software dev is the process of chopping down a system into smaller pieces so they can be implemented. _High level design is the first step of the process._

# What To Specify
Exactly what you should specify in the high‐level design varies somewhat, but some things are constant for most projects, which are:
- `Security`
- `Hardware`
- `User Interface`
- `Internal Interfaces`
- `External Interfaces`
- `Architecture`
- `Reports`
- `Database`

And we shall discuss them in the following headings.

# Security
The sections that require security are:
- `Operating system security :` This includes the type of login procedures, password expiration policies, and password standards.
- `Application security :` may use a separate application username and password. It also means providing the right level of access to different users.
- `Data security` 
- `Network security`
- `Physical security :` I think whats meant by this is the security of the device hardware?

All these forms of security interact with each other, sometimes in non‐obvious ways.

# Hardware
You can build systems that run on desktops to even glasses.

Additional hardware that you need to specify might include the following:
- Printers
- Network components _(cables, modems, gateways, and routers)_
- Servers _(database servers, web servers, and application servers)_
- Specialized instruments _(scales, microscopes, programmable signs, and GPS units)_
- Audio and video hardware _(webcams, headsets, and VOIP)_

# User Interface
Indicate the main methods for navigating through the application _(the application’s basic navigational style)._

Can describe special features such as
- clickable maps
- important tables
- methods for specifying system settings _(such as sliders, scrollbars, or text boxes)_.

Can also address **general appearance issues** such as color schemes, company logo placement, and form skins.

# Internal Interfaces
Internal interfaces are things as systems / features within the application that dont need to interact with external apps. _(My own definition, take it with a grain of salt)_

When you chop the program into pieces, you should specify how the pieces will interact. Then the teams assigned to the pieces can **work separately** without needing constant coordination.

Unfortunately, you may not be able to define the interfaces before writing at least some code.

It’s important that the high‐level design specifies these internal interactions **clearly and unambiguously** so that the teams can work as independently as possible.

# External Interfaces
Many applications must interact with external systems.

In a way, external interfaces are often easier to specify than internal ones because you usually don’t have control over both ends of the interface.

Try to make your interface simple and flexible so that you don’t get flooded with change requests.

# Architecture
An application’s architecture describes how **its pieces fit together** at a high level.

Developers use a lot of _“standard”_ types of architectures.

Many of these address particular characteristics of the problem being solved:
- `Monolithic`
- `Client/Server`
- `Component‐Based`
- `Service‐Oriented`
- `Data‐Centric`
- `Event‐Driven`
- `Rule‐Based`
- `Distributed`

## Monolithic Architecture
In a monolithic architecture , **a single program does everything:**
- It displays the user interface,
- accesses data,
- processes customer orders,
- prints invoices, launches missiles,
- does whatever else the application needs to do.

## Client / Server Architecture
A client/server architecture separates pieces of the system that need to **use a function _(clients)_** from parts of the system that **provide those functions _(servers)_**.

That decouples the client and server pieces of the system so  that developers can work on them separately.

## Component-Based Architecture
In component‐based software engineering _(CBSE)_, you regard the system as a **collection of loosely coupled components** that provide services for each other.
![[Pasted image 20230208175331.png|200]]

## Service-Oriented Architecture
A service‐oriented architecture _( SOA )_ is similar to a [[1 @ High-Level Design#Component-Based Architecture|component‐based architecture]] except the **pieces are implemented as services.**

A service is a self‐contained program that runs on its own and provides some kind of service for its clients.

Sometimes, services are implemented as web services . Those are simply programs that satisfy certain standards, so they are easy to invoke over the Internet.

## Data-Centric Architecture
Data‐centric or database‐centric architectures come in a variety of flavors that all use data in some central way:
- Storing data in a **relational** database system. 
- Using **tables** instead of hard‐wired code to control the application. 
- Using **stored procedures** inside the database to perform calculations and implement business logic.

## Event-Driven Architecture
In an event‐driven architecture _( EDA )_, various parts of the system **respond to events as they occur**.

## Rule-Based Architecture
A rule‐based architecture uses a **collection of rules to decide what to do next.** _(These systems are sometimes called **expert systems** or **knowledge‐based systems**.)_

Rule‐based systems work well if you can identify the rules necessary to get the job done.

It is often used in artificial intelligence applications and research.

_For example:_
An expert system might help a doctor choose the correct diagnosis based on a cluster of symptoms, or select tactical moves to play a game.

## Distributed Architecture
In a distributed architecture, **different parts of the application run on different processors** and may run at the same time.  _(The processors could be on different computers scattered across the network, or they could be different cores on a single computer.)_

[[1 @ High-Level Design#Service-Oriented Architecture|Service‐oriented]] and _multi-tier_ architectures are often distributed, with different parts of the system running on different computers.

[[1 @ High-Level Design#Component-Based Architecture|Component‐oriented]] architectures may also be distributed, with different components running on different cores on the same computer.

# Reports
Almost any nontrivial software project can use some kinds of reports.

Business applications might include reports that deal with:
- `customers` _(who’s buying, who has unpaid bills, where customers live)_
- `products` _(inventory, pricing, what’s selling well)_
- `users` _(which employees are selling a lot, employee work schedules)._

# Other Outputs
The application could generate :
- printouts _(of reports and other things)_,
- web pages,
- data files, 
- image files,
- audio _(to speakers or to audio files)_,
- video,
- output to special devices (such as electronic signs),
- e‐mail,
- text messages

# Database
The first part of database design is to decide **what kind of database the program will need.**

You need to specify whether the application will store data in:
- text files,
- XML files,
- a fulfill edged relational database

Even a program that doesn’t use any database still needs to store data, perhaps inside the program within arrays, lists, or some other data structure.