_Next [[🟩4 @  Application Manifest]]_
_previous [[🟩2 @ Android OS & App Architecture]]_

--- 

Java is a portable language. Meaning it can run on any machine, Thats possible because Java  instead of compiling to **Native Machine Code**  (0s and 1s), it compiles it to **Byte Code**.

Now all devices have a **virtual machine** for the language  that compiles source code to **Native Machine Code**.  So say for example your code uses 4 bytes for integers, and the machine uses 2 bytes integers. Then there will be an overflow when the VM compiles the code to machine code. But when building a java application it is compiled to byte code, and then when the app runs it is then compiled to native machine code which fixes compatibility errors **but takes more time to execute** since the app is not compiled to machine code.

Thats how the standard `Java SE VM` works. But for mobile we have a different java, called `Java Dalvik VM` an additional step that **transforms the Java byte code to Dalvik byte code** . What Dalvik does is make the app use registers that are close to the cpu rendering execution a lot faster.

![[Pasted image 20230102175756.png | 700]]