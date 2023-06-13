# Dependency graph
The dependency graph is the set of objects that must be created in order to create a specific
requested “root” object.
![[316 - dpenendency graph example.png]]

Generally speaking, any dependencies in your code **should be explicit, not implicit**. Implicit dependencies are hard to reason about and difficult to test, so you should avoid them wherever you can. DI is useful for guiding you along this path.

> Explicit example:
>```cs
>private readonly UserRepository userRepository;
>public UserService(UserRepository userRepository){
>	this.userRepository = userRepository;
>}
>```
>Implicit example:
>```cs
>public void SendEmail(string recipient, string subject, string body){
>	string smtpServer = ConfigurationManager.AppSettings["SmtpServer"];
>}
>```

# Dependency Injection Container
The DI container or IoC container is responsible for creating instances of services. It knows how to construct an instance of a service by creating all its dependencies and passing these to the constructor.
![[320 - DI container example.png]]

> ==**Note:**== Many DI containers are available for .NET: Autofac, Lamar, Unity, Ninject, Simple Injector... The list goes on! 

# Coupling
**Coupling** is an important concept in object-oriented programming. It refers to how a given class depends on other classes to perform its function. Loosely coupled code doesn’t need to know a lot of details about a particular component to use it.

Coding to interfaces is a common design pattern that helps further reduce the coupling of a system, as you’re not tied to a single implementation. This is particularly useful in making classes testable, as you can create “stub” or “mock” implementations of your dependencies for testing purposes
![[Pasted image 20230613160958.png]]

> Example: using interfaces with dependency injection
> ![[232 - using interfaces with dependency injection.png]]

# How the DI works
![[324 - Controller activator.png]]
but for this to work, the service must be registered to the DI container
> ==**Definition:**==  You register services with a DI container so that it knows which implementation to use for each requested service. This typically takes the form of, “for interface X, use implementation Y.”
