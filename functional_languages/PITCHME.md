---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Functional Programming Languages
(Follows the Sebesta Text Chapter 15)
---
**Overview**
***

Imperative languages are all based on the von Neumann architecture.  These are by far the most used languages.

Instead of the von Neumann architecture, functional languages are based on a mathematical model of computing.
---
**Overview**
***

There have been many important computer scientists that have suggested functional programming might be a better alternative to imperative programming.  John Backus, for instance, was a proponent of these languages.

In 1977 he won the ACM Turing Award for his work on Fortran.  With this award is given an opportunity to present a lecture to the community.  He lectured on the merits of functional programming.  He noted that this paradigm:
---
**Overview**
***

- lacks side effects

- isn't affected by context

- (due to the above mentioned reasons) is easier to understand during and after development
---
**Overview**
***

Imperative languages involve the idea of state.  As commands are executed state changes.

The solution to a problem is the memory's final state.

This is extremely hard to read, as we need to keep track of variables' state as we peruse the code.

This is not a problem in functional programs, as they have no state.
---
**Overview**
***

Remember that a mathematical function maps members from a domain to a range.

Some mappings are as follows:

```
y = x^2 x∃ℤ

z^2 = x^2 + y^2 for x∃ℝ, y∃ℝ
```

Or
---
**Overview**
***

z = B[x][y]

|   | y |    |    |    |    |
|---|---|----|----|----|----|
| **x** | 1 | 2  | 3  | 4  | 5  |
|   | 2 | 4  | 6  | 8  | 10 |
|   | 3 | 6  | 9  | 12 | 15 |
|   | 4 | 8  | 12 | 16 | 20 |
|   | 5 | 10 | 15 | 20 | 25 |
---
**Overview**
***

Note that whether we are dealing with a function described as an expression or one described as a table, pass one or multiple parameters from the domain.  A value from the range is returned.
---
**Overview**
***

The big thing we need to remember when talking about functional languages is that there are no variables (as there is no state).  Therefore every time we pass a value from a domain we get the same element from the range that we get every other time we pass this value from the domain.

The range value that is returned is **not** dependent on any other program state.
---
**Overview**
***

So, in functional languages we are mapping parameters to values, **not** producing a value through some sequence of operations.
---
**Overview**
***

To mirror our book as closely as possible we are going to use the following syntax when defining functions:

  - function name first
  - list of parameters in parentheses
  - a mapping Expression

For instance (from the book):

```
cube(x) ≡ x * x * x
```
---
**Overview**
***

Notice that I'm not saying that ```cube(x)``` is equal to a value.  I'm using the '≡' character.

This character should be read (in this context) as "defined as".
---
In imperative languages we would see an expression such as ```cube(x) ≡ x * x * x``` and imagine ```x``` to be a variable - that is we imagine ```x``` to be a value currently stored in some memory location.
---
We SHOULD NOT view ```x``` this way in functional languages.  In a functional language ```x``` stands for a value that is bound; whatever it stood for cannot change during evaluation (it is a constant).  We then view

```
cube(x) ≡ x * x * x
```

as

```
cube(2.0) ≡ 2.0 * 2.0 * 2.0
```

(if the parameter passed was 2.0).
---
**Overview**
***

What we are talking about here is a different mental model of computation that clears away some of our preconceptions of what programming has to be.  We may think that we already view the expression as ```cube(2.0) ≡ 2.0 * 2.0 * 2.0``` when ```cube(2.0)``` is called, but really we don't.  We have been "burned" so many times while debugging code that in the backs of our minds we know we can expect changes in state to occur.  Forget that now.
---
**Overview**
***

While studying functional languages you will come across the concept of the **lambda expression**.

(If you remember back to our study of Python you may have picked up on this!)

This is based on the work of Alonzo Church, who was working on a formal model of functions called **lambda calculus**.
---
**Overview**
***

Lambda expressions are nameless functions.  In lambda calculus our cube function would be

λ(x)x * x * x

In Python we expressed it as:

```Python
g = lambda x: x*x*x
```
---
**Overview**
***

To understand functional programming we must understand the concept of **higher-order** functions.  These are functions that can take other functions as parameters.

This allows us to solve problems via the **composition of functions**.

We've seen the composition of functions before in math, i.e. if we have f(x) and g(x) we may computer f(g(x))
---
**Overview**
***

As an example, let's try to write an absolute value function as the composition of two functions:

```
f(x) = x * x
g(x) = sqrt(x)
abs(x) = g(f(x)) = sqrt(x * x)
```
---
**Overview**
***

The first functional programming language was LISP, created at MIT in 1959.  LISP has changed a great deal over the years though, adding imperative features, static typing, and other features.  It is not a very pure functional language these days, though it is quite efficient and still in use.
---
**Overview**
***

In the beginning LISP only had two types, **atoms** and **lists** (LISP stood for **Lis** t **P** rocessor). The following is a list:

```LISP
(APPLE ORANGE BANANA GRAPE)
```

This list is made of 4 atoms.
---
**Overview**
***

A more complicated list might be

```LISP
((FUJI GRANNYSMITH MACINTOSH) (MANDARIN NAVEL) BANANA (RED WHITE BLUE))
```
