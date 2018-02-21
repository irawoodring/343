---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Abstract Data Types, Encapsulation, and Object Oriented Programming
(Follows the Sebesta Text Chapters 11 and 12)
---
Most all modern programming languages support Object Oriented (OO) programming.

The hallmarks of OO are data abstraction and encapsulation.

**Abstraction** is a way of looking at some entity that only focuses on the most significant parts.
---
We have learned about two types of abstraction in this class,

**Process abstraction** occurs when we give a name to a sequence of statements.  This allows us to call upon a sequence of statements instead of manually executing each statement ourselves.  We see this with subprograms (functions).  This was the first type of abstraction in Computer Science, and even Plankalkül supported it in the 1940s.
---
**Data abstraction** is much newer, with the ideas for it beginning in the 1960s and COBOL.  C also provided data abstraction with the concept of structs.  This allows us to create composit types.

**Abstract Data Types (ADTs)** are enclosures that define a specific type of data *and* the subprograms that operate on that data type.  For instance, we may define an ADT called Spaceship that includes spaceship information, and also the functions that we would call to operate on the spaceship data.
---
**Abstract Data Types (ADTs)**
***

ADTs are defined in a single syntactic unit.  This *does not* mean they are always defined in a single file though (think C++).

ADTs have access controls that can hide information from outside the ADT instances.

This is very important!  It means that the user doesn't have to know anything about the underlying storage or function of the ADT.  All the users need to know is how to use it.
---
**Abstract Data Types (ADTs)**
***

Through the rest of this semester we will use the term ADT to refer to the construct or definition of an ADT.  We will use the term **object** to refer to a particular instance of an ADT.
---
**Abstract Data Types (ADTs)**
***

We use ADTs as a means of making programs less complex.  It allows us to separate code into areas of concern.  Instead of concentrating on the big picture of what the program is trying to accomplish, we focus on writing robust definitions of the smaller units of which the program is composed.
---
**Abstract Data Types (ADTs)**
***

An important note:  **all** data types are ADTs.  We tend to forget this when we think of built-in types, but even built-in types are ADTs.

Consider a floating point number.  We don't have to understand how it is stored; in fact there have been multiple different ways to store a floating point number that systems have used in the past.  All we really care about is how to use one.
---
Even the concept of the byte is an ADT; in reality it is just the turning on or off of some switch.  We don't care how that happens - just that we can use one.
---
**Abstract Data Types (ADTs)**
***

This brings up an important point: **information hiding** is the concept that we can use an ADT without knowing how it works internally.

This implies:
---

- that ADTs can be very robust.  By hiding the information of implementation we prohibit users from "damaging" our internal data.

- that our code can still work the same regardless of the system on which we are running.  For instance, if we run on a system that doesn't follow the same standard for the storage of floating point numbers, we can still use floating point numbers.  How they are stored on the systems is not important to us.
---
We will use the term **clients** to refer to a program unit that uses a specific ADT.
---
**Abstract Data Types (ADTs)**
***

Other benefits of information hiding (besides increased integrity of the data) are

- the amount of variables and code the programmer has to be aware of is reduced.
- name conflicts are less likely (scope of the variables are smaller).
- changes in how the ADT was programmed do not cause us to have to rewrite all code that uses the ADT
---
**Abstract Data Types (ADTs)**
***

We need to be careful about designing our ADTs.  If we aren't careful about adhering to proper practice we run the risk of losing the benefits of information hiding.

Therefore we should (in general) not set access to our data as public.

We should always use accessors.
---
**Abstract Data Types (ADTs)**
***

The reasons accessors are better are

- we can have read-only data by having a getter but no setter.
- we can include constraints in our setters.  For example we might want to limit possible changes to our state to certain value ranges.
- (as already mentioned) changing the way the ADT is implemented does not affect clients.
---
**Abstract Data Types (ADTs)**
***

For a language to be able to provide ADTs it must

- provide a syntactic unit to enclose the declaration of the type and prototypes of the subprograms that implement the operations.
- a means to make subprograms visible to clients so they can ask the ADT to manipulate data on its behalf.
- must provide external visibility for the name, but hide the representation
---
**Abstract Data Types (ADTs)**
***

In addition to the syntactic unit issues, language designers must decide if an ADT can be parameterized. Parameterizing an ADT means specializing it so that can hold specific data types.

We have seen parameterized types in Java; for instance when defining an ArrayList<>.  ArrayLists<> require us to denote the type of ArrayList we wish to use by filling in the "<>" section of the declaration.  This is important for generic programming.
---
**Abstract Data Types (ADTs)**
***

In C++ for instance:

```C++
template <typename T>
class Stack {

  public:
    void push(T const & e);
    void pop();
    T top() const;

  private:
    std::vector<T> elements;
};
```
---
**Abstract Data Types (ADTs)**
***

We would then be able to create an object of this type by parameterizing our declaration:

```C++
Stack<int> intStack;
Stack<float> floatStack;
Stack<Concert> concertStack;
```
---
**Abstract Data Types (ADTs)**
***

Other issues are the types of access control provided and how those access controls are specified, and whether the ADT must be specified with its interface and implementation together or separately.
---
**Abstract Data Types (ADTs)**
***

Let's view some examples!

We'll start with Ada:
---
**Abstract Data Types (ADTs)**
***

Ada uses **packages** for encapsulation.  Packages have two parts:

- **package specification:** which provides the interface
- **body package:** which provides the implementation

Both of these parts are also called packages.

Packages are generalized encapsulations; they can define multiple types.
---
**Abstract Data Types (ADTs)**
***

Both the specification and the body package share the same name, but the reserved keyword ```body``` in the package header notes it is the body package.

The two parts can be compiled separately (as long as the specification is compiled first).
---
**Abstract Data Types (ADTs)**
***

The programmer of a type can decide if the representation is hidden or not.

>If it is not hidden, is this an ADT?

---
NO!

If we can manipulate the underlying data, it is not an ADT.
---
**Abstract Data Types (ADTs)**
***

In ADA there are two ways of hiding information.  The first is to use the keyword ```private```, the other is to define the ADT as a pointer in the package specification and that pointer points to a structure defined in the body package.

Since the implementation or body of the package is hidden from clients, the clients can't see how it is implemented.
---
Ada Package Specification

```Ada
package Stack_Pack is
-- The visible entities, or public interface
  type Stack_Type is limited private;
  Max_Size : constant := 100;
  function Empty(Stk : in Stack_Type) return Boolean;
  procedure Push(Stk : in out Stack_Type;
    Element : in Integer);
  procedure Pop(Stk : in out Stack_Type);
  function Top(Stk : in Stack_Type) return Integer;

  -- The part that is hidden from clients
  private
  type List_Type is array (1..Max_Size) of Integer;
  type Stack_Type is
    record
    List : List_Type;
    Topsub : Integer range 0..Max_Size := 0; end record;
end Stack_Pack;
```
---
Ada Body specification

```Ada
with Ada.Text_IO; use Ada.Text_IO;
package body Stack_Pack is

function Empty(Stk: in Stack_Type) return Boolean is begin
  return Stk.Topsub = 0;
  end Empty;

procedure Push(Stk : in out Stack_Type; Element : in Integer) is
  begin
  if Stk.Topsub >= Max_Size then
      Put_Line("ERROR - Stack overflow");
    else
      Stk.Topsub := Stk.Topsub + 1;
      Stk.List(Topsub) := Element;
    end if;
end Push;

procedure Pop(Stk : in out Stack_Type) is
  begin
  if Empty(Stk)
    then Put_Line("ERROR - Stack underflow");
    else Stk.Topsub := Stk.Topsub - 1;
    end if;
  end Pop;

function Top(Stk : in Stack_Type) return Integer is
  begin
  if Empty(Stk)
    then Put_Line("ERROR - Stack is empty"); else return Stk.List(Stk.Topsub);
  end if;
end Top;

end Stack_Pack;
```
---
**Abstract Data Types (ADTs)**
***

You may have noticed the keywords ```with``` and ```use``` in the packages.

```with``` makes names defined in external packages visible (includes or imports them).

```use``` makes it so we don't need to qualify the symbols explicitly (just like the ```using``` keyword in C++).
---
**Abstract Data Types (ADTs)**
***

Here is client code that makes use of the Stack.

```Ada
with Stack_Pack;
use Stack_Pack;
procedure Use_Stacks is
  Topone : Integer;
  Stack : Stack_Type;   -- Creates an Object of type Stack_Type
  begin
  Push(Stack, 42);
  Push(Stack, 17);
  Topone := Top(Stack);
  Pop(Stack);
  ...
end Use_Stacks;
```
---
**Abstract Data Types (ADTs)**
***

C++ also allows ADTs, through use of the class construct.  This differs from Ada; because Ada uses the more generalized encapsulation technique, if a program makes use of a package it has access to all of the public symbols defined in that package.

C++ use of the class construct means that when we are a client to an ADT we only have access to the ADT information.  We don't have names for any other types defined in the same file as the class.
---
**Abstract Data Types (ADTs)**
***

C++ classes define data called **members** and functions called **member functions**.  These members are of the type **instance** or **class**.

Class members are associated with the class (think ```static```).

Instance members share class member functions but have their own member data.
---
**Abstract Data Types (ADTs)**
***

Member functions in C++ can be defined in the class implementation file or just the header file.

If a function is defined (not just declared) in the header it is implicitly inlined.

An inline function is a function that the compiler replaces the function call with the function body.  In some situations this can save time (consider if the function is small, it might be quicker than creating a new stack frame).
---
**Abstract Data Types (ADTs)**
***

C++ classes have ```private``` and ```public``` sections to provide information hiding (also ```protected``` which is discussed later).
---
C++ Interface file

```C++
#ifndef IntCell_H
#define IntCell_H

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    explicit IntCell( int initialValue = 0 );
    int read( ) const;
    void write( int x );

  private:
    int storedValue;
};

#endif
```
---
C++ Implementation file (notice the namespace operator):

```C++
#include "IntCell.h"

/**
 * Construct the IntCell with initialValue
 */
IntCell::IntCell( int initialValue ) : storedValue{ initialValue }
{
}

/**
 * Return the stored value.
 */
int IntCell::read( ) const
{
    return storedValue;
}

/**
 * Store x.
 */
void IntCell::write( int x )
{
    storedValue = x;
}
```
---
C++ All in header example:

```C++
#include <iostream>
using namespace std;

/**
 * A class for simulating an integer memory cell.
 */
class IntCell
{
  public:
    /**
     * Construct the IntCell.
     * Initial value is 0.
     */
    IntCell( )
      { storedValue = 0; }

    /**
     * Construct the IntCell.
     * Initial value is initialValue.
     */
    IntCell( int initialValue )
      { storedValue = initialValue; }

    /**
     * Return the stored value.
     */
    int read( )
      { return storedValue; }

    /**
     * Change the stored value to x.
     */
    void write( int x )
      { storedValue = x; }

  private:
    int storedValue;
};
```
---
**Abstract Data Types (ADTs)**
***

We would then use the class as such:

```C++
Intcell iCell;
iCell.write(42);
```
---
**Abstract Data Types (ADTs)**
***

Objective-C is another language that supports ADTs.  In Objective-C we have classes as well.  They are defined in ```@interface``` and ```@implementation``` containers.

```
@interface class-name : parent-class {
  instance variable declarations
}
  method prototypes
@end
```

```
@implementation class-name
  method definitions
@end
```
---
**Abstract Data Types (ADTs)**
***

Objective-C uses a syntax much like Smalltalk for method prototypes:

```
(+ | -)(return-type) method-name [: (formal parameters) ];
```

Here, the ```+``` sign indicates that a symbol is a class type.

The brackets around the formal parameters section implies they are optional.

Much like many other languages, instances share methods but have their own data.
---
**Abstract Data Types (ADTs)**
***

Sample functions may then look similar to the following:

```
// Method name is method1:
-(void) method1: (int) x;
// Method name is method2:second:
-(int) method2: (int) x second: (float) y;
// Method name is method2:
-(int) method2: (int) x: (float) y;
```
---
We call these with the syntax ```[object-name method-name];```.  In the case of our examples, if we had an object called ```myObj``` we would call them as such:

```
[myObj method1: 42];
[myObj method2: 42 second: 3.14];
[myObj method2: 42: 3.14];
---
**Abstract Data Types (ADTs)**
***

A few notes; in Objective-C constructors are called **initializers**.  They only provide initial values, and can have any name so they must be explicitly called.  Their type is a pointer to the class name, provided by returning **self**.

We create a new object with the alloc statement, and typically call the constructor explicitly in the same statement:

```
MyObject *myObj = [[MyObject alloc] init];
```
---
**Abstract Data Types (ADTs)**
***

Objective-C uses the ```#import``` syntax to bring outside names into scope.
---
**Abstract Data Types (ADTs)**
***

Much like other languages, Objective-C use the public and private syntax, but they do so with the ```@public``` and ```@private``` keywords.

Convention for the language is that a getter has the same name as the variable, and the setter has the variable name preceeded by ```set```.  For instance, if we have a variable ```sum```:
---
```
-(int) sum {
  return sum;
}

-(void) setSum: (int) s {
  sum = s;
}
```
---
**Abstract Data Types (ADTs)**
***

For default getters and setters we can list the variable as a ```@property``` in the interface section and have the getters and setters created by using the directive ```@synthesize``` in the implementation:

```
// Interface section
@property int sum;

...

// Implementation section
@synthesize sum;
```
---
```
// stack.m - interface and implementation of a simple stack #import <Foundation/Foundation.h>
// Interface section
@interface Stack: NSObject { int stackArray [100];
	int stackPtr;
	int maxLen;
	int topSub; }
	-(void) push: (int) number; -(void) pop;
	-(int) top;
	-(int) empty;
	@end
	// Implementation section
	@implementation Stack
	-(Stack *) initWith {
		maxLen = 100;
		topSub = -1;
		stackPtr = stackArray; return self;
	}
-(void) push: (int) number { if (topSub == maxLen)
	NSLog(@"Error in push--stack is full");
	else
		stackPtr[++topSub] = number;
}
-(void) pop {
	if (topSub == -1)
		NSLog(@"Error in pop--stack is empty");
	else
		topSub--; }
		-(int) top {
			if (topSub >= 0)
				return stackPtr[topSub]); else
					NSLog(@"Error in top--stack is empty");
		}
-(int) empty {
	return topSub == -1);
}
int main (int argc, char *argv[]) {
	int temp;
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc]
		init];
	Stack *myStack = [[Stack alloc]initWith]; [myStack push: 5];
	[myStack push: 3];
	temp = [myStack top];
	NSLog(@"Top element is:%i", temp); [myStack pop];
	temp = [myStack top];
	NSLog(@"Top element is:%i", temp);
	temp = [myStack top];
	[myStack pop];
	[myStack release];
	[pool drain];
	return 0;
} @end

```
---
**Abstract Data Types (ADTs)**
***

Java supports ADTs using the class construct.  In Java all objects are declared on the heap and accessed (implicitly) through references.  As noted in lecture, the syntactic unit for a Java class is a single file.
---
```Java
class StackClass {
        private int [] stackRef; private int maxLen,
                topIndex;
        public StackClass() { // A constructor
                stackRef = new int [100]; maxLen = 99;
                topIndex = -1;
        }
        public void push(int number) {
                if (topIndex == maxLen)
                        System.out.println("Error in push—stack is full");
                else stackRef[++topIndex] = number;
        }

        public void pop() {
                if (empty())
                        System.out.println("Error in pop—stack is empty");
                else --topIndex;
        }
        public int top() {
                if (empty()) {
                        System.out.println("Error in top—stack is empty");
                        return 9999; }
                else
                        return (stackRef[topIndex]);
        }
        public boolean empty() {return (topIndex == -1);}
}
```
---
Client:
```Java
public class TstStack {
  public static void main(String[] args) {
    StackClass myStack = new StackClass(); myStack.push(42);
    myStack.push(29);
    System.out.println("29 is: " + myStack.top()); myStack.pop();
    System.out.println("42 is: " + myStack.top());
    myStack.pop();
    myStack.pop();  // Produces an error message
  }
}
```
---
**Abstract Data Types (ADTs)**
***

C# is similar to both Java and C++, but adds new features.

Like Java, C# keeps objects ojn the heap, and provides both classes and structs.  The difference in both is that the default access modifier for a class is private, whereas for a struct it is public.  Additionally, structs do not support inheritance, and are value types instead of reference types (put on the stack!).
---
**Abstract Data Types (ADTs)**
***

C# provides properties (similar to Objective-C) that allow getters and setters to be generated.

C# also has no requirement that a class must reside in a single file; you can create a ```partial``` class.

As with C++, you may provide more than one class definition per file (though this is not good practice).
---
```C#
class TimePeriod
{
    private double seconds;

    public double Hours
    {
        get { return seconds / 3600; }
        set { seconds = value * 3600; }
    }
}


class Program
{
    static void Main()
    {
        TimePeriod t = new TimePeriod();

        // Assigning the Hours property causes the 'set' accessor to be called.
        t.Hours = 24;

        // Evaluating the Hours property causes the 'get' accessor to be called.
        System.Console.WriteLine("Time in hours: " + t.Hours);
    }
}
// Output: Time in hours: 24
```
---
**Abstract Data Types (ADTs)**
***

Ruby also provides ADTs, defined between a ```class``` keyword and the ```end``` keyword.

Instance variables are prefaced with the ```@``` sign, and instance methods begin with ```def``` and end with ```end```.

Class variables are denoted with ```@@```.  There are multiple ways to create a class method, such as
---
```Ruby
class Blah
  def self.myMethod
    ...
  end
end

class Blah
  class << self
    def myMethod
      ...
    end
  end
end

class Blah; end
def Blah.myMethod
  ...
end
```
---
**Abstract Data Types (ADTs)**
***

Constructors are named ```initialize``` in Ruby and cannot be overloaded.

Class members may be added to the class at any time, and class methods may be removed.

These abilities greatly harm the readability of the language.
---
**Abstract Data Types (ADTs)**
***

Access controls are also dynamic, meaning that violations cannot be caught before runtime.

The default access is public for methods, but Ruby provides for protected and private as well.

For instance data access is private, and this cannot be changed.  We access instance data through the use of accessor methods called attributes.
