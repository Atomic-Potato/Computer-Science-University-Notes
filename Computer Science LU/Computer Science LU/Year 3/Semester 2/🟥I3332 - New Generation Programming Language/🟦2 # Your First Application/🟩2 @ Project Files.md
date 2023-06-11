# The Project Layout
![[Pasted image 20230602154539.png]]

# The `csproj` project file: defining your dependencies
It contains the details required for the .NET tooling to build your project.

It defines the type of project being built *(web app, console app, or library)*, which platform the project targets *(.NET Core 3.1, .NET 5, and so on)*, and which NuGet packages the project depends on.

![[Pasted image 20230602154918.png]]

# The Program class: building a web host
Main uses a `IHostBuilder`, created by the call to `CreateDefaultBuilder`, to define how the `IHost` is configured, before instantiating the `IWebHost` with a call to `Build()`.

![[Pasted image 20230602155051.png]]
>\#A Create an IHostBuilder using the CreateHostBuilder method .
\#B Build and return an instance of IHost from the IHostBuilder.
\#C Run the IHost, start listening for requests and generating responses.
\#D Create an IHostBuilder using the default configuration.
\#E Configure the application to use Kestrel and listen to HTTP requests
\#F The Startup class defines most of your application’s configuration.

# Program Class vs Startup class
![[Pasted image 20230602160548.png]]
