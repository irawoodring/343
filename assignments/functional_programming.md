# Functional Programming

In this assignment you will show that you understand the basics of functional programming.  We will be using the language Scheme.

You may need to refer to the notes, [here](https://gitpitch.com/irawoodring/343/master?p=functional_languages "Functional Programming").

## Assignment

Write a simple cash register program.  It should do nothing more than keep a running tally of amounts.  For instance, it might look like this:

```Scheme
Scheme Point-of-Sale
Start transaction (exit with 0):

Enter value: $1.99
$1.99

Enter value: $2.99
$4.98

Enter value: $0

Subtotal: $4.98
Tax: $.3237
Total: $5.3037
```

## Notes

- Define any constants that you may want to use, such as ```tax_rate```.

- The tax rate should be 0.065

- An extra 5 points if you can round to 2 decimal places.

- Remember... there is NO STATE in a functional program.  You can't loop like we would in an imperative language.  You must call the function recursively with the new value on each iteration.

- Feel free to work in pairs since we only have a week.

## Submission

This is a 25 point HOMEWORK, not a project.  It will therefore count for less than the projects which are larger in scope.

Submit on Blackboard your source code file (cash_register.scm) by midnight, 12/8.  I don't want to make this due on the Monday of exam week; you should be studying for finals at that point.
