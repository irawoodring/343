---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Language Spotlight - Python
A Dynamically Typed Language
---
**Python**
***

[Python](https://www.python.org/ "Official Python Website") was created by Guido van Rossum, a Dutch programmer.  He retains the title "Benevolent Dictator for Life" (BDFL) of the Python language.

Currently Python maintains two versions - a 2.7 standard and a Python 3 version.  Many programmers prefer the 2.7 version, but it is due to be phased out in 2020 (was previously 2015 but extended).

The name gives a glance to *Monty Python's Flying  Circus*.
---
**Python**
***

The language is widely used - usually in the top 10 on the Tiobe index (\#5 as of the time of this writing).  It is used by companies such as

  - Youtube
  - Industrial Light & Magic (Lucasfilm!)
  - Google,
  - Firaxis Games (Civilization Series)
  - MANY others.

---
**Python**
***

Python allows programmers to program in multiple paradigms; imperative, procedural, and object-oriented paradigms are supported.  The language also provides some functional features.

Types in Python are dynamic, meaning variables are not bound before runtime.  This makes writability much easier for programming in Python, but affects readability and reliability (due to a lack of compile time type checking).
---
**Python**
***

van Rossum continues to oversee development of Python due to his status as BDFL, but the language is influenced by these general goals:

  - Beautiful is better than ugly
  - Explicit is better than implicit
  - Simple is better than complex
  - Complex is better than complicated
  - Readability counts

More generally, Guido believes "there should be one—and preferably only one—obvious way to do it" when it comes to programming.
---
**Python**
***

Many of those design decisions can be seen by the syntax that Python chooses to use.  Whitespace is important; therefore indentation is required.  English words are often used in place of symbols (i.e. ```not``` instead of ```!```).

Additionally, due to these design decisions Python is more orthogonal than many other languages like C.
---
**Python**
***

Python is an interpreted language, meaning programs do not need to be compiled before run.  This provides the added benefit of being able to interactively use Python (demo).
---
**Python**
***

Python has several built in variable types: Numeric, Iterator, Sequence, Text Sequence, Binary Sequence, Set, Mapping, Class, and a few other types.
---
**Python**
***

Variables are given a type implicitly and dynamically; this means that variables are not declared with a type modifier as in some languages, and that memory for the variable is not reserved until run-time.
---
**Python**
***

Numeric types may be

**int** - Integers (1, 2, 3, 42, 9192, etc.)

**float** - Floating Point (3.14, 42.424242)

**complex** - Complex (6+8j) (they have a real part i and an imaginary part j).  We don't need to put the i before the real part.
---
**Python**
***

Many functions are provided by Python for use on Numeric types.  Some include

```Python
abs(x)
int(x)
float(x)
pow(x)
-x
```

etc. (note some of these are not defined for complex numbers though).  We do not need to import any additional libraries to use these functions.
---
**Python**
***

Iterator types allow programmers to iterate over a collection.  We will talk about iterators later in the semester.
---
**Python**
***

Sequence types in Python come in three varieties,

**list**, **tuple**, and **range**.
---
**Python**
***

The list in Python is very similar to an array (reinforced by the fact that lookups on the list take O(1) time! [Documentation](https://docs.python.org/3/glossary.html#term-list "Python docs")).  They are used much like arrays, but have enhanced functionality over many of their peer languages more basic arrays.
---
**Python**
***

Some built-in functions that Python provides for lists are

- ```list.append(x)``` - add to the end of the list
- ```list.insert(i,x)``` - add the element to the list at position i.  This will move other elements in the list.
- ```list.clear()``` - Removes all items from the list.
- ```list.sort```, ```list.count```, and other built-ins are provided as well (demo).
---
**Python**
***

The built-in functionality of lists allows them to easily be used as stacks and queues.

Remember, a stack is a LIFO data structure, while a queue is a FIFO.
---
**Python**
***

Stack operations:

```Python
stack = []
stack.append[42]
stack.append[492727]
stack.pop()
```
---
**Python**
***

Queue Operations:

```Python
queue = []
queue.append(42)
queue.append(492727)
q.pop(0)
```

Or, with an additional import statement:
---
```Python
from collections import deque
queue = deque([42, 492727])
queue.append(1701)
queue.popleft()
```
---
**Python**
***

Python provides an interesting way to create lists as well, called **List Comprehensions**.  We can create these by applying a function to a list.

If we were normally going to create a list in a for loop like this:

```Python
nums = []
for i in range(100):
  nums.append(i*2)
```

We could instead use this (more concise) code:

```Python
nums = [x*2 for x in range(100)]
```
---
**Python**
***

Additionally, Python would also let us take a functional programming approach, and map a function:

```Python
nums = list(map(lambda x: x*2, range(10)))
```

Functional programming relies upon mapping functions to an input instead of the for-each syntax we are more accustomed to in imperative programming.
---
**Python**
***

Tuples are another sequence type in Python, but whereas list elements can change, tuple elements are immutable.

We create tuples with parentheses, separating each element in the tuple by a comma:

```Python
''' Technically the ( and ) are optional here... '''
tup = (42, 492727, 1701)
tup = ([42, 492727], 1702)
tup = (["Meaning", 42], 492727)
```
---
**Python**
***

We access data inside a tuple with our indexing operators, "[", and "]".

```Python
>>> tup
(['Meaning', 42], 492727)
>>> tup[0]
['Meaning', 42]
>>>
```
