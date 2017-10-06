---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Lexical and Syntax Analysis

(Follows the Sebesta Text Chapter 4)
---
*Lexical and Syntax Analysis*
***

Languages can be compiled, interpreted, or both (hybrid systems - convert to some intermediate form).

Samples are C, Python, and Java (respectively).
---
*Lexical and Syntax Analysis*
***

All of these languages (and all of those types of languages) need lexical and syntax analyzers.
---
*Lexical Analysis*
***

A **Lexical Analyzer** is basically just a pattern matcher.

Given some arbitrarily large string, it attempts to find substrings matching certain patterns.

The output from the lexer is tokens.
---
*Lexical Analysis*
***

Recall that a token is one or more lexemes.

For instance, we may have the following tokens defined:

```
' ', '\t', 'n'         WHITESPACE
+                      ADD_OP
0-9                    DIGIT
```
---
*Lexical Analysis*
***

So, if you had a sentence in the language such as

```
3 + 9
```

The lexer would output

```
DIGIT WHITESPACE ADD_OP WHITESPACE DIGIT
```
(Though we would probably ignore the WHITESPACE).
---
*Lexical Analysis*
***
