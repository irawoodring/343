---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Expressions and Assignment Statements
(Follows the Sebesta Text Chapter 7)
---
**Overview**
***

Expressions are the way we specify computations in a programming language.

Issues that affect expressions (and therefore need to be addressed by language creators) are associativity and precedence, type mismatches, coercions, and short-circuit evaluations.
---
**Functional Languages**
***

It is important to note that functional languages are similar but not the same as imperative languages when it comes to expressions and assignments.

An "assignment" in a functional language is really a **declaration** that binds a value to a name (functional languages don't have variables; once a value is assigned it stays).

Additionally, the evaluation of an expression in a functional language can not have side effects.
---
**Arithmetic Expressions**
***

One of the original reasons computers were created was for the automatic evaluation of statements.  We wanted to be able to solve math, science, and other types of problems without the slow human element.

To that extent, many expressions in Computer Science mirror expressions from Mathematics:

  - operators
  - operands
  - parentheses
  - functions
---
**Operators**
***

Operators are labeled based on the number of operands they function on.

**Unary** operators have only one operand.

**Binary** operators have two.

**Ternary** operators have three.
---
**Operators**
***

Some Unary Operators:

```C
int x = 41;
x++;

x--;

y = &x;
```
---
**Operators**
***

Binary are more what we are used to:

```C
int x = 21;
int y = 21;

int z = x + y;

z << 1;
```
---
**Operators**
***

Ternary:

```C
value = a.height < b.height ? x : y
```

Which is a substitute for:

```C
if(a.height < b.height){
  value = x;
} else {
  value = y;
}
---
**Operators**
***
