# Registering Services to the Container
The dependency injection container is set up in the `ConfigureServices` method of your `Startup` class in `Startup.cs`.

Most nontrivial libraries that you add to your application will have services that you need to
add to the DI container. **By convention, each library that has necessary services should expose an `Add*()` extension method that you can call in `ConfigureServices`.**

![[330.png]]
These statements are made by calling various **`Add*()`** methods on `IServiceCollection` in the `ConfigureServices` method. Each method provides three pieces of information to the DI container:
- `Service type`—`TService`. This is the class or interface that will be requested as a dependency. Often an interface, such as *IEmailSender*, but sometimes a concrete type, such as *NetworkClient* or *MessageFactory*.
- `Implementation type`—`TService` or `TImplementation`. This is the class the container should create to fulfill the dependency. Must be a concrete type, such as *EmailSender*. May be the same as the service type, as for *NetworkClient* and *MessageFactory*.
- `Lifetime`—**Transient, Singleton, or Scoped**. This defines how long an instance of the service should be used for.

![[331 - Configuring via 3 methods.png]]

## The assumptions of `Add*()`
The preceding `Add*` methods use generics to specify the `Type` of the class to register, but they don’t give any indication of how to construct an instance of that type. Instead, the container makes a number of assumptions that you have to adhere to:
- The class must be a concrete type.
- The class must only have a single “valid” constructor that the container can use.
- For a constructor to be “valid,” all constructor arguments must be registered with the container, or must be an argument with a default value.

## `AddSingleton()`
![[332 - AddSingleton().png]]

**When the same object is used whenever it’s requested, it’s known as a singleton**

# Creating Multiple Instances of The Same Class
![[333 - using a provider to create mutliple instances of the same class.png]]
# Extension Methods
just use them to make ur services cleaner
![[335 - using extension methods to clean up registering services.png]]

# Injecting Multiple Implementations
![[336 - injecting multiple implementations of an ineterface 1 .png]]
![[337 - injecting multiple implementations of an ineterface 2 .png]]

> ==**Note:**== You must use `IEnumerable<T>` as the constructor argument to inject all the registered types of a service, `T`. Even though this will be injected as a `T[]` array, you can’t use `T[]` or `ICollection<T>` as your constructor argument. Doing so will cause an `InvalidOperationException`

> ==**Note:**== The DI container will use the last registered implementation of a service when resolving a single instance of the service.

# Conditionally registering services using `TryAdd()`
![[339 - conditionally registering servives using TryAdd().png]]

# Replacing previously registered implementation with Replace()
![[339 - replacing previously registered implementation with Replace().png]]

# Injecting services into action methods, page handlers, and views

## Injecting into action methods
![[341 - injecting dependicies directly to an action method.png]]
## Injecting into handlers
![[342 - injecting dependincies into page handlers.png]]

## Injecting into views
![[343 - injecting dependencies into views.png]]