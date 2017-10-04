---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

**Lexing and Regular Expressions**
---
**Lexing (Scanning)**
***

We've learned so far that lexing is the process of tokenizing a string.

As we progress into parsing we will see what we do with these tokens, but for now we are just going to focus on the problem of tokenizing the string.
---
**Lexing (Scanning)**
***

It is perfectly ok to create your own lexer, however there are lexer generators that (in most cases) work very well.  We will be using a generator called Flex.

Flex is a newer version of the generator Lex.  Lex has been around for decades.  While researching Flex and Lex you may see their names used interchangeably in some places.
---
**Lexing (Scanning)**
***

You may also see references to a program called Yacc or Bison.  These are the corresponding parser generators for Lex/Flex.  We will be talking about them later.
---
**Lexing (Scanning)**
***

Lex/Flex requires us to create a file of definitions for our tokens.  We provide those definitions via the use of Regular Expressions (regex).

A regex is a language that defines a pattern.

The language of the regex is characters, literals, and character classes.
---
**Lexing (Scanning)**
***

```
Some character:   matches that character.
.             :   matches any character except \n.
[abc]         :   matches the character a, b, or c.
[a-z]         :   matches any character a-z.
[^I-M]        :   matches any character except I, J, K, L, or M.
regex*        :   matches the regex preceeding the * zero or more times.
regex+        :   matches the regex preceeding the + 1 or more times.
regex?        :   matches the regex preceeding the ? 0 or 1 times.
regex{3,9}    :   matches the regex if it occurs 3-9 times.
regex{7,}     :   matches the regex 7 or more times.
\character    :   do not evaluate the character; match it literally.
                  (useful if we want to match a character that is
                  also a regex character.).
Many more.
```
---
**Lexing (Scanning)**
***

They may also use character classes:

```
[:digit:]    :    class for numbers 0-9.
[:lower:]    :    lower case letters.
[:upper:]    :    upper case letters.
[:space:]    :    white space.
[:alnum:]    :    alphanumeric characters.

Many more.
```
---
**Lexing (Scanning)**
***

So, if we wanted to match a variable name in a string, and our language dictates a variable is two characters, where the first character must be a ```$``` and the second character must be an alphabetical character, we might use the following regex:

```
\$[A-Za-z]
```
