Modular Calculator

A small calculator application in C++

The calculator supports the following commands:
+ <param> - addition - adds param to the memory
- <param> - subtraction - subtract param from memory
* <param> - multiplication
/ <param> - division
Set <param> - sets the memory to param
^ <param> - power - raises the memory to the power param
Sqrt - calculates the square root of the current value in memory
Off - stop requesting inputs and exit

Examples of usage

Welcome to Modular Calculator
---> + 100
Current value: 100
---> + 100.3
Current value: 200.3
---> + -30
Current value: 170.3
---> + -30.5
Current value: 139.8
---> - 4
Current value: 135.8
---> / 0
MathException:DivisionByZeroException
Current value: 135.8
---> * 14
Current value: 1901.2
---> Set 2
Current value: 2
---> Sqrt 
Current value: 1.41421
---> ^ 3
Current value: 2.82843
---> Off
guy@guy:~/workspace/try_modular_calculator/Debug$

The main class is Calculator - handles the user inputs and calls the necessary operations.
In order to to turn on the calculator you must construct a Calculator object and call the function start().
The parsing is done using an input string stream.

The file utility contains some generic functions that are mostly used by operations classes, e.g stod (I couldn't find that 
function so I just implemented my own version using string streams) and is_overflowed(checks if double is overflowed)

All the operations classes are in the folder Operations. The classes are fairly similar, they are different solely in logic and 
not in structure. The base class of all operations is CalculatorOperation. It is an abstract class and has three pure virtual 
functions.

There are some math exception classes in the Exceptions folder. The MathException class is the base class in this case.
All the exceptions classes differ only in the default message attached to them. I might add specific properties to each one 
later on, though it doesn't seem like a necessity. BTW I didn't actually handled each type of exception differently, but I made
the hierarchy anyway.

Hopefully it is documented enough.