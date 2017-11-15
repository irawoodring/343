---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Data Types
(Follows the Sebesta Text Chapter 6)
---
Much (but not all) of this chapter concerns topics you are familiar with, such as arrays, numeric types, etc.  In the interest of time we will not cover these in class.

You will likely see these topics again before the end of the semester.

As always, you are expected to have read the chapter.
---
That was a (not so veiled) hint that there will be questions on the final concerning topics in the chapter.

Please read the chapter.
---
**Type Checking**
***

We will skip toward the end of the chapter and start with **Type Checking**.

Type checking is the process of making sure that the operands of an operator are compatible types.
---
**Type Checking**
***

Compatible means it is either allowed by the operator or the language provides mechanisms to **coerce** it into a compatible type.

An example of coercion is when we assign an **int** to a **float** in C.  The system is able to safely coerce the int to a float type.
---
**Type Checking**
***

**Static type checking** happens at compile time; it aids greatly in readability and reliability, as type errors are discovered before the program runs.

**Dynamic type checking** happens at run time; this usually means enhanced flexibility for programmers, at the expense of less safe code.
---
**Type Checking**
***

Note that even in statically typed languages that all type errors cannot be caught at compile time.  For instance, consider the ```union``` types in C and C++; they can hold different values at different times which means that type checking may happen at run time, or may not happen.
---
In this code the value held in the union will be the address of v, a pointer.  We should not be able to add two pointers - the operation is not defined in C (try it, it won't compile!).  However, this code compiles ok:

```C
#include <stdio.h>

int main(int argc, char** argv){
        char* v = "some string.\0";
        union data {
                int x;
                char* y;
        } d;

        d.y = v;
        d.x = d.x + d.x;
        printf("%d\n", d.x);

}
```
---
**Type Checking**
***

**Strong typing** means that type errors are always detected in a language.

In general we want strong typing; it greatly helps readability and reliability.

C and C++ and not strongly typed due to the fact that unions are not type checked.

Java and C+ are *nearly* strongly typed - they allow explicit casts which can result in a type error:
---
```Java
import java.util.ArrayList;

public class Test {

        public static void main(String[] args){
                Object o = new ArrayList<String>();
                String s = (String) o;
                System.out.println(s);
        }

}

javac Test.javac
java Test
Exception in thread "main" java.lang.ClassCastException: java.util.ArrayList cannot be cast to java.lang.String
        at Test.main(Test.java:7)
```
---
**Type Checking**
***

Coercion greatly affects type checking, as it can remove benefits we can gain from strong typing.

For instance, the book notes that in Java, it we had the following:

```Java
int a = 42;
int b = 1701;
float d = 0;
```

If we mean to type ```a + b``` but instead type ```a + d``` the compiler cannot warn us of a potential error, as the values will be coerced into working (by being changed to floats).
