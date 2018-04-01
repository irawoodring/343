---
CIS 343 - Structure of Programming Languages

Ira Woodring

***
Subprograms

(Chapter 9 in Sebesta)
---
Recall that there are two types of abstractions in a programming language - data abstraction and process abstraction.

Process abstraction has been around for some time; data abstraction came much later.
---
Process abstraction allows us to reuse code - typically through the use of a subprogram.

A **subprogram** is a binding of a grouping of statements to a process.  This binding may or may not have a name.
---
Subprograms help us to divide our code into logical units of repeated processes.  Subprograms have the following:

- each subprogram has a single entry point
- the code that calls the subprogram is suspended while the subprogram runs
- control of the program returns to the calling code when the subprogram finishes

(Notice here we are not talking about any kind of concurrency).
---
The interface and the process of the subprogram are called the **subprogram definition**.  A **subprogram call** asks our runtime to create a new instance of a subprogram and to execute it.

When our subprogram is in the process of executing it is said to be **active**.
---
A **subprogram header** provides the details about the subprogram, such as the type of subprogram it is.  A subprogram can be of two types:

- **procedures** - can be thought of as defining new statements; these do not return values.
- **functions** - are subprocesses that can return values (they could also be void).
---
The header also provides the name for the subprogram (if it is given a name), and may also list any parameters the subprogram may take.

We may often call subprogram headers a **signature**.
---
Every language that implements subprograms decides upon the syntax of creating a function.  In C and C++ for instance we might have:

```C++
void doStuff(int a, double c);
```
---
Javascript and PHP begin each subprogram with the ```function``` keyword:

```Javascript
// Javascript
function doStuff(a, c){ }

// PHP
function doStuff($a, $c){ }
```
---
Perl uses the ```sub``` keyword:

```Perl
sub doStuff {
  my($a, $c) = @_;
}
```
---
Ruby and Python both use the ```def``` keyword:

```Python
// Ruby
def doStuff(a, c)
  ...
// Python
def doStuff(a, c):
  ...
```

Though Python requires the ```:``` to denote a new scope
---
Interestingly, in Python the ```def``` statements are executable code.  This causes a name to be given to the function.  Since we can execute the function definition we can do some interesting things:

```Python
if i==1:
  def doStuff(a, b):
    return a + b
else:
  def doStuff(a, b):
    return a * b
```
---
This causes the program to make a choice about how to define ```doStuff()```, and can lead to some interesting behavior in a program.
---
A subprogram may have a **parameter profile** which provides the

- number
- order
- type(s)

of its formal parameters.
---
**Formal parameters** are listed in the subprogram header.  The variables listed in this header are sometimes called dummy variables; when defining the subprogram they aren't instantiated or usually even bound.  Typically this happens when the subprogram is called.

Even then the dummy variables may just be bound to other program variables.
---
When we call a subprogram and pass parameters we are passing **actual parameters**.

```C
// Formal parameters
int doStuff(int a, float c);

...

int main(int argc, char** argv){
  int x = 42;
  float y = 1701.0;
  // Actual parameters
  doStuff(x, y);
}
```
---
There are different ways to relate actual parameters to formal parameters.  Most languages do so through inspection of the parameter positions (these are, unsurprisingly enough, called **positional parameters**).

However, some languages also provide for **keyword parameters**:
---
```Python
def calcVolume(height, width, depth=1):
  return height * width * depth

// All of these are valid calls
calcVolume(height=10, width=5)
calcVolume(width=5, height=10)
calcVolume(height=10, width=5, depth=3)
calcVolume(width=5, height=10, depth=3)
calcVolume(10, 5)
calcVolume(10, 5, 3)
// Even mixed! (Though once we use a keyword we
// must continue them.  No more positional after that!
calcVolume(5, depth=8, width=8)
```
---
Notice that in the above example ```depth``` was given a default value.  This meant that we did not need to expressly provide a value for depth.  This would allow us, for instance, to reuse this function for 2d or 3d objects easily.
---
Some languages allow us to provide a variable number of parameters.  In C for instance, the ```printf``` function has the following function header:

```C
int printf ( const char * format, ... );
```

The ellipsis here means that the function can take any number of parameters:
---
```C
printf("The meaning is %d.\n", meaning);
printf("%d + %d * %d = %d\n", a, b, c, d);
```

We certainly don't want to write a separate function for each possible number of parameters passed in.
---
