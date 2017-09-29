# Basic C++ Class Writing

In this assignment you will show that you understand the basics of writing a class in C++ (we will be using C++11).

In class we have talked about the basics of C++, the syntactic units that makeup a class, object creation, and memory management.  This assignment will assess your grasp of these concepts.

## Assignment

Write a class that holds concert information.  It should hold the following information:

```C++
// Who will be performing?
std::string concertName;

// A list of the people you want
// to take with you.  May be empty
// or arbitrarily full.
std::vector<std::string> friends;

// A value from 1-10 concerning how
// badly you want to see this show.
int desire;

// The date of the show
// See http://en.cppreference.com/w/cpp/chrono/c/tm
std::tm date;
```

1. In addition to these instance variables, you will need a default constructor, and a constructor that allows you to pass in all these values.

2. You also need to overload the < operator so that you can use std::sort to sort the concerts.  We will compare a concert by first determining its date, and then its desire.  So a concert with an earlier date will come before one that comes later - even if the desire is lower for the earlier one.  If the dates are at the same time then the one with the highest desire should come first.  The signature for overloading the < operator is

```C++
bool Concert::operator<(const Concert& other) const;
```

(providing your class is called "Concert").

4. A main function that creates at least 10 concert objects, puts them into a std::vector<Concert> data structure, sorts them using std::sort, and prints them.

Extra Credit (10 Points): Figure out how to overload the << operator so you can print the Concerts with the std::cout << syntax.  This is the C++ equivalent to writing a toString();
.

## Notes

1.  You are on the hook for learning some of these concepts.  It will take a little reading. We don't have time to learn all of the ins and outs of C++ (it is huge!).

2.  This is a homework and not a project.  Therefore I am allowing you to work in groups and allowing you to talk to other groups about how they are accomplishing tasks.  Everyone should understand the content though; there will be C++ questions on the midterm.

## Submission

Everyone (not every group, but everyone!) Should submit either a GitHub URL or their source files (all \*.h and \*.cpp) on Blackboard.  I greatly prefer a GitHub URL, though your grade will not be affected either way.

Due October 9 at midnight.
