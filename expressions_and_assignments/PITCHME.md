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
---
**Arithmetic Expressions**
***

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
```
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

However, if ```fun(a)``` has side effects we could have a problem:
---
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
**Operators**
***

**Referential Transparency** is a property of expressions that exists in a program if any two expressions with the same value in the program may be swapped for one another anywhere in the program, without changing the programs output:
---
```
result1 = (fun(a) + b) / (fun(a) - c);
temp = fun(a);
result2 = (temp + b) / (temp - c);
```

If this code is referentially transparent then ```result1``` and ```result2``` will be the same.
---
**Operators**
***

Referential transparency is desirable as it makes programs more readable; this is largely due to the fact that it makes programs behave more like mathematical statements (which we are used to).

Functional languages are referentially transparent, as they lack variables and state.
---
**Operators**
***

**Operator Overloading** allows programmers to use arithmetic operators for multiple purposes.  For instance, instead of using the ```+``` operator solely on integer addition, the programmer may be able to use it to add ```floats```, ```strings```, or even instances of custom types.

Operator overloading is a bit of a mixed-bag; it aids in writability and can aid in readability, but can also harm readability, writability, and reliability.  We must be very careful how we use it.
---
**Operators**
***

Consider:

```Python
class Car:
    def __init__(self):
        self.name = ""
        self.gas_used = 0
    def __add__(self, other):
        return self.gas_used + other.gas_used

a = Student()
a.gas_used = 3.7

b = Student()
b.gas_used = 4.0

print a + b
```
---
This may or may not make sense...

- What does it mean to add two cars together?

- Would you expect adding two cars to return the total gas they had used?

- Is there another way we might want to combine two cars?

- Might some other programmer assume we are adding other fields?

- Can we guess what is happening without looking at the class code?
---
**Operators**
***

This makes more sense:

```Java
String one = "Hello";
String two = " World.";
System.out.println(one + two);
```

Most programmers would correctly guess (without looking at the String class code) that adding two Strings together is shortcut for concatenation.
---
**Operators**
***

Consider what it can do for writability though.  If we have a class that holds a matrix, we could write custom functionality for that class so it could add or multiply matrices.  This means that code that looks like this:

```
MatrixAdd(MatrixMult(A, B), MatrixMult(C,D))
```

Can become this:

```
A * B + C * D
```
---
**Operators**
***

Java does not allow operator overloading.  Of the languages we have discussed in here, Python, Ruby, C#, and C++ do (although the particular operators each language can overload vary).

In C++ you can overload the following operators:
---
<style type="text/css">
.tg  {border-collapse:collapse;border-spacing:0;}
.tg td{font-family:Arial, sans-serif;font-size:3em;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg th{font-family:Arial, sans-serif;font-size:3em;font-weight:normal;padding:10px 5px;border-style:solid;border-width:1px;overflow:hidden;word-break:normal;}
.tg .tg-yw4l{vertical-align:top}
</style>
<table class="tg">
  <tr>
    <td class="tg-yw4l">+</td>
    <td class="tg-yw4l">-</td>
    <td class="tg-yw4l">*</td>
    <td class="tg-yw4l">/</td>
    <td class="tg-yw4l">%</td>
    <td class="tg-yw4l">^</td>
    <td class="tg-yw4l">&amp;</td>
    <td class="tg-yw4l">|</td>
    <td class="tg-yw4l">~</td>
  </tr>
  <tr>
    <td class="tg-yw4l">!</td>
    <td class="tg-yw4l">=</td>
    <td class="tg-yw4l">&lt;</td>
    <td class="tg-yw4l">&gt;</td>
    <td class="tg-yw4l">+=</td>
    <td class="tg-yw4l">-=</td>
    <td class="tg-yw4l">*=</td>
    <td class="tg-yw4l">/=</td>
    <td class="tg-yw4l">%=</td>
  </tr>
  <tr>
    <td class="tg-yw4l">^=</td>
    <td class="tg-yw4l">&amp;=</td>
    <td class="tg-yw4l">!=</td>
    <td class="tg-yw4l">&lt;&lt;</td>
    <td class="tg-yw4l">&gt;&gt;</td>
    <td class="tg-yw4l">&lt;&lt;=</td>
    <td class="tg-yw4l">&gt;&gt;=</td>
    <td class="tg-yw4l">==</td>
    <td class="tg-yw4l">!=</td>
  </tr>
  <tr>
    <td class="tg-yw4l">&lt;=</td>
    <td class="tg-yw4l">&gt;=</td>
    <td class="tg-yw4l">&amp;&amp;</td>
    <td class="tg-yw4l">||</td>
    <td class="tg-yw4l">++</td>
    <td class="tg-yw4l">--</td>
    <td class="tg-yw4l">,</td>
    <td class="tg-yw4l">-&gt;*</td>
    <td class="tg-yw4l">-&gt;</td>
  </tr>
  <tr>
    <td class="tg-yw4l">()</td>
    <td class="tg-yw4l">[]</td>
    <td class="tg-yw4l">new</td>
    <td class="tg-yw4l">delete</td>
    <td class="tg-yw4l">new[]</td>
    <td class="tg-yw4l">delete[]</td>
    <td class="tg-yw4l"></td>
    <td class="tg-yw4l"></td>
    <td class="tg-yw4l"></td>
  </tr>
</table>
