---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

**<span style="text-decoration: line-through;">Mocha, LiveScript, ECMAScript, Javascript</span>**

Forget it.  Call it what you want.
---
The language formerly known as LiveScript, standardized by ECMA, and commonly referred to as Javascript began life under the development name Mocha.
---
It was developed by and for Netscape, to be part of its Netscape Navigator web browser (may it rest in peace).  At the last minute the name was changed to "Javascript" as a marketing ploy; Java was 'in' during that time and they wanted to take advantage of the popularity.

It has NOTHING to do with Java.  It is about as different from Java as a language can be.
---
The first version was written in 10 days, by Brendan Eich in 1995.

Many programmers believe that Javascript has only recently began to be a server-side technology as well as a browser technology, but this is not strictly true.  Netscape created a server-side version shortly after releasing the original browser based version.

Microsoft has also had server-side with JScript for many years.
---
It is a dynamic, weakly typed, prototype-based language.

The thing that trows many people off is the **Prototype-based** part.
---
Let's remember our definitions here:

- **Class** - a blueprint for an object.  Not instantiated.

- **Object** - an instance of a class.  Instantiated (hence it is an "instance").
---
Typicaly object-oriented programming provides code re-use via an object inheriting from a parent *class*.

In Javascript there is no "class" (yes, there is syntactic sugar that makes it seem Javascript has classes, but it really doesn't).  There are only objects.

One object may be a prototype of another object.
---
Consider:

```Javascript
> var person = { name: 'ira', height: '6 ft 0 in' }
undefined
> var occupation = { title: 'Professor', skill: 'Wizardry' }
undefined
> Object.setPrototypeOf(person, occupation)
{ name: 'ira', height: '6 ft 0 in' }
> person.title
'Professor'
>
```
---
Here we created a new object called person, and set the prototype of that person object (not class) to occupation.  An object can be a prototype of only one object at a time, but by being a prototype it gains the properties of the prototype.

However, prototypes can be chained:
---
```Javascript
> var ira = {}
undefined
> Object.setPrototypeOf(ira, person)
{}
> ira.name
'ira'
> ira.title
'Professor'
>
```
---
Here, the object "ira" was set to the prototype of "person".  Person though, was a prototype of occupation, so "ira" has the properties of all the prior objects in the chain.
---?image=./javascript/prototyp_chain.png?size=auto
