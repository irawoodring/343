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

Variables are merely representations of memory locations.

Sometimes the representations are very similar to what is in the hardware; other times software provides some translation.
---
**Overview**
***

We characterize variables with a collection of properties or attributes.

One such property is the variables name.  As simple as it may seem to us, when designing a language there are complex issues involved with choosing a variable naming scheme.
---
**Names**
***

A name is not required for a variable; they really just exist for our benefit.  Computers are perfectly happy just using addresses.

Some issues with names are the characters allowed to be used for the name, case sensitivity, the number of characters the name is made up of, are reserved words usable and if any "decorators" are used.
---
**Names**
***

There are vastly different rules for naming variables depending on the language.  For instance:

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
