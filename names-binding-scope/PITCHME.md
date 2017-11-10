---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Names, Binding, and scope
(Follows the Sebesta Text Chapter 5)
---
**Overview**
***

At their heart, imperative languages are abstractions of the hardware.

Variables, for instance, are merely representations of memory locations.

Sometimes the representations are very similar to what is in the hardware; other times software provides some translation.
---
**Overview**
***

Programming languages assign names to variables and functions.

As simple as it may seem to us, when designing a language there are complex issues involved with choosing a naming scheme.
---
**Names**
***

A name is not required for a member; they really just exist for our benefit.  Computers are perfectly happy just using addresses.

Some issues with names are the characters allowed to be used for the name, case sensitivity, the number of characters the name is made up of, are reserved words usable and if any "decorators" are used.
---
**Names**
***

There are vastly different rules for naming depending on the language.  For instance:

- Fortran allows only up to 31 characters
- C has no limit, but only the first 63 are significant
- Java, C#, and Ada have no limit and all are significant
- C++ provides no limit, though certain implementations do.
---
**Names**
***

So we need to be very careful when using a language; this could create a problem then:

```C
#include <stdio.h>

int main(int argc, char** argv){
  int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa = 42;
  int aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab = 24;

  printf("%d\n", aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa);
  printf("%d\n", aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab);
}
```

Though most (newer) implementations seem to handle this just fine.
---
**Names**
***

Some of these issues may seem trivial, but we need to remember that these rules are going to either help or hinder areas such as readability and writability.

For instance, Java's insistence on case sensitivity allows us to have the following:

```Java
student1.toString()
student1.ToString()
student1.tostring()
student1.TOSTRING()
student1.tOsTrInG()
etc...
```
---
**Names**
***

As all of those permutations *could* be valid, it is both harder to tell what the original programmer's intent was (readability), and harder to keep track of all the possible functions we may wish to call (writability).
---
**Names**
***

Many languages reserve certain words and do not allow us to use them as variable names.  These are called **reserved words**.

Other languages may have **keywords**.  These may be context sensitive.  For instance, in Fortran the word **Integer** is a keyword.  It can be used to denote a variable type, or it can be used as a variable:
---
```Fortran
Integer Num_cars
Integer = 42
```

Note that context matters here; the first example was the keyword before a variable name; it is then a type specifier.  In the second example the keyword is followed by an assignment operator meaning it is to be interpreted as a variable.
---
**Variables**
***

Variables can be seen as a collection of six attributes:

- name
- address
- value
- type
- lifetime
- scope
---
**Address**
***

We already discussed names so we'll next examine address.

As you can probably guess, the address is the machine address where the variable's value is stored.
---
**Address**
***

We call the address of a variable its **l-value**.  This is due to the fact that in most languages assignment statements put name on the left side.

A single address may be referred to by multiple variables.  When this happens we say that a variable has an **alias**.
---
```C++
// An alias in C++ created by using
// a reference.
int y = 42;
int & x = y;

std::cout << x << std::endl;
std::cout << y << std::endl;

y = 1701;
std::cout << x << std::endl;

42
42
1701
```
---
**Address**
***

Notice that changing y changed x as well.

Aliases are a huge hit on readability, as they make programs much harder for a reader to understand.
---
**Type**
***

Types determine both the range of values a variable can hold, and the operations that may be performed.

We talked about types in our ADT lectures and will not discuss it further here.
---
**Value**
***

What we store in the memory locations the variable is comprised of are the value.

We call the value the **r-value** as it is usually on the right side of an assignment statement.
---
**Value**
***

Although it seems fairly straightforward, determining the value for an r-value can be complicated due to scoping rules.
---
An understanding of scope and lifetime requires us to first talk about binding.

As the book does, we will pause talking about variable attributes here and focus on binding.
---
**Binding**
***

A binding occurs when we associate an attribute and an entity.

This does not refer strictly to a variable; we can associate a function with an attribute as well.
---
**Binding**
***

Binding can occur at

- **language design time** (think of an operator)
- **language implementation time** (imagine a data type in C; it must be implemented on multiple hardwares so will have different ranges)
- **compile time** (imagine associating a variable with a type)
- **load time** (an address is given to a variable when the program is loaded into memory)
- **link time** (associating a function with an address in library)
- **run time** (giving a variable a value)
---
**Binding**
***

A static binding occurs before runtime and does not change while the program is running.

A binding that occurs during runtime and can change while the program is running is dynamic.
---
**Binding**
***

Type bindings may be implicit or explicit.  Explicit type bindings may harm writability but aid readability.

Implicit type bindings do the opposite.  In addition, they can harm reliability as they remove the ability of a compiler to detect errors before runtime.
---
**Binding**
***

Please note that implicit/explicit bindings are a separate topic from static/dynamic bindings, though I've found that students' tend to confuse the two.  

This is likely due to the fact that many dynamic languages they are used to using have implicit type systems (Python, etc.) though there are those that are static and implicit (Go).
---
**Binding**
***

**Allocation** refers to the process of assigning a variable from a pool of memory.

**Deallocation** is the returning of the memory to the pool.
---
**Binding**
***

The **lifetime** of a variable is the time during which it is bound to a particular memory location.
---
**Binding**
***

**Static variables** are bound to memory cells before programs are executed, and stay bound until the program ends.

```C
int main(int argc, char** argv){
  static int num_threads;
}
```
---
**Binding**
***

Static variables are very fast, as compilers typically substitute the address for the variable, allowing for direct access (no lookup).

Additionally, there is no overhead for allocating a static variable; it is given a memory location at compile time.
---
**Binding**
***

**Elaboration** is the process that happens at run-time of allocating and binding a variable.

**Stack-dynamic** variables are variables that are statically bound but created when they are elaborated.
---
**Binding**
***

They are useful because they allow recursion (a subprogram must have local dynamic local storage for recursion).

The disadvantage is run-time overhead, as allocating and deallocating variables can be high.
---
**Binding**
***

**Explicit Heap-Dynamic Variables** are allocated and deallocated at run-time by the programmer.

They are useful because they can be used for dynamically sized structures, but they are difficult for programmers to use correctly.
---
**Binding**
***

**Implicit Heap-Dynamic Variables** are bound to heap storage only when they are assigned a value.

These are very flexible, but run-time overhead is high, and they don't have the ability to be error checked by the compiler.
---
**Scope**
***
