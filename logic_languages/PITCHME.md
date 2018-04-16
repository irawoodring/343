---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Logic Languages

(Follows the Sebesta Text Chapter 16)
---
Logic languages (also called declarative languages) allow us to create programs via symbolic logic.  Logical inferences are used to find the answers we seek.

Programs written in logic languages will not look like "programs" at all - at least not what we're used to seeing.  They are more like databases of facts (sometimes called a Knowledge Base).
---
Logic programs are made up of declarations instead of procedures.  We then consult the declarations to find solutions to our problems.
---
Logic languages are based upon something called **Predicate Calculus**.

A predicate calculus (a.k.a. First Order Logic) uses **propositions**.  These are logical statements that may or may not be true.  Formal logic was made to allow us to check the validity of propositions.
---
**Symbolic logic** allows us to express propositions, express relationships between them, and to describe how new propositions can be inferred from other propositions that are true.
---
"Objects" in propositions are either constants or variables.  A constant represents an object, and a variable represents different objects at different times.
---
**Atomic propositions** are the simplest propositions.  They are **compound terms** made up of a **functor** and parameters passed to it.  For instance:

```prolog
man(jake)
like(bob, steak)
```

These should be read as "Jake is a man." and "Bob likes steak."
---
It should be noted that in the above example, ```man, jake, like, bob, steak``` are all constants.  Also note that there is no real meaning here implied by the computer; we assign meaning to ```man(jake)```.
---
A proposition can be either a **fact** or a **query**.  A fact is something we are adding to our knowledge base (or database), and a query is something we are trying to find out from it.
---
We will be using the language Prolog to study logical languages.  Prolog programs are collections of statements that are made from **terms**.
---
A term in Prolog is a constant, a variable, or a structure.  A constant is either an **atom** or an integer.  An atom is a symbolic value, and is composed of a string of letters, digits, and underscores, or a string made from any ASCII character surrounded by apostrophes.
---
A variable in Prolog is any string of letters, digits, and underscores that starts with an uppercase letter or underscore.

For instance, in the following, X and Y are variables.
```Prolog
parent(X, Y).
```
---
A structure represents atomic propositions from predicate calculus, meaning they have the form

```
functor(parameter list)
```
---
To construct a knowledge base, Prolog allows us to create **facts** and **rules**.

A fact is some proposition that is assumed to be true.  For instance:

```Prolog
female(shelley).
female(mary).
male(bill).
male(jake).
father(bill, jake).
father(bill, shelley).
mother(mary, jake).
mother(mary, shelley).
```
---
Rules are implications between propositions.  A sample rule might be

```prolog
ancestor(mary, shelley) :- mother(mary, shelley).
```

This should be read as "If mary is the mother of shelley, then mary is an ancestor of shelley."
---
Notice the general form here:

```Prolog
consequence :- antecedent_expression.
```

The antecedent_expression is required to be true to imply that the consequence is true.
---
We can use variables with rules to make them more useful.  For instance, we might have

```Prolog
parent(X, Y) :- mother(X, Y).
parent(X, Y) :- father(X, Y).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
```
---
Goal statements allow us to perform queries on our knowledge base.

For instance, we could query if some fact exists:

```Prolog
man(fred).
```

This will return **true** if this fact exists in the database.
---
If the fact does not exist in the database, or the goal cannot be proven true, **false** is returned.

We can have goals with variables in them as well.  For instance, we might have the following:

```Prolog
father(X, mike).
```
---
If there is a fact in the database concerning this, or some other rule that will allow this inference to be made, then the system will reply with something like

```C
X = joe.
```

Here assuming that joe is mike's father.
---
We can perform arithmetic with Prolog as well.  Prolog will evaluate an ```is``` expression.  We need to be careful; we can type

```Prolog
X = 3 + 2
```

But this will set X to ```3 + 2```; it will not be evaluated.
---
However, if we use the ```is``` functor the expression will be evaluated before assignment:

```Prolog
X is 3 + 2.
```

Now the system will respond with ```X = 5.```.
---
We can use these mechanisms in our rules.  For instance, if we have a knowledge base that keeps track of the average speeds on a racetrack for each car and the amount of time each car was on the track, we could determine the distance the any car covered.
---
```Prolog
speed(ford, 100).
speed(chevy, 105).
speed(dodge, 95).
speed(volvo, 80).
time(ford, 20).
time(chevy, 21).
time(dodge, 24).
time(volvo, 24).
distance(X, Y) :- speed(X, Speed), time(X, Time), Y is Speed * Time.
```
---
We can now query this system:

```Prolog
?- distance(ford, Ford_Distance).
Ford_Distance = 2000.
```
---
Should we wish, we could ask for the trace of resolution:

```Prolog
trace.
true.

[trace]  ?- distance(ford, Ford_Distance).
   Call: (8) distance(ford, _3660) ? creep
   Call: (9) speed(ford, _3882) ? creep
   Exit: (9) speed(ford, 100) ? creep
   Call: (9) time(ford, _3882) ? creep
   Exit: (9) time(ford, 20) ? creep
   Call: (9) _3660 is 100*20 ? creep
   Exit: (9) 2000 is 100*20 ? creep
   Exit: (8) distance(ford, 2000) ? creep
Ford_Distance = 2000.
```

Note: Internal variables are denoted with an underscore at their beginning.
---
Prolog also allows us to have lists.  We can create one as follows:

```Prolog

```
