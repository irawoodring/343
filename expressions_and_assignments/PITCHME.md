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

In most programming languages binary operators are **infix**, meaning the operator falls between its operands:

```C
a + b
```

However, some languages use **prefix** notation (Lisp for instance):

```Lisp
(+ a b)
```
---
**Evaluation Order**
***

Evaluation order affects the value an expression evaluates to.

```C
a + b * c
```

Can mean

```C
(a + b) * c

a + (b * c)
```
---
**Evaluation Order**
***

There is no rule that says we must follow mathematical rules - though languages that do not will likely not be adopted as quickly.

Mathematicians developed the hierarchies of operands long ago and people are used to them.  We should mimic them as much as we can.
---
**Operators**
***

Therefore, every language designer must develop operator precedence rules for their language.  We can view these in the language documentation:

https://docs.python.org/2/reference/expressions.html#operator-precedence
https://docs.oracle.com/javase/tutorial/java/nutsandbolts/operators.html

You'll notice they are largely the same.
---
**Operators**
***

In some programming languages (such as Ruby), operators are implemented as methods.  This means that:

```Ruby
a + b
```

Is really this:

```Ruby
a.add(b)
```
---
**Operators**
***

This also means we can do this:

```Ruby
class Fixnum
  def +(other)
    self - other
  end
end

3 + 4
=> -1
```
---
**Operators**
***

Many functional languages define operators as functions as well.

```Lisp
(+ a (* b c))
```

Is two function calls.
---
**Operators**
***

**Side effects** are when a function changes either one of its parameters or a global variable.

If a function does not have side effects, then the order of evaluation of an expressions operands does not matter.  Consider (book example; imagine ```fun(10) = 20```):

```
a = 10;
b = a + fun(a)  // Here fun(a) does not change a
```
---
**Operators**
***

In the previous example it didn't matter if ```a``` or ```fun(a)``` was evaluated first. Either way we'd get 30 if fun(a) returns 20 for an input of 10.

However, if ```fun(a)`` has side effects we could have a problem:

```
def fun(a):
  ...
  a = a + a
  ...

// Once again, fun(10) = 20

a = 10
b = a + fun(a)  // Evaluate fun(a) first
print b;
40
```
---
**Operators**
***

To address these issues, language designers must decide to either not allow functional side effects, or provide a strict order of operations.

In general, imperative languages don't block functional side effects as it is hard to accomplish and it harms writability.
---
