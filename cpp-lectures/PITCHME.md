---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

**The C++ Programming Language**
---
**History**
***

Created by Bjarne Stroustrup.  He started working on it in 1979 calling it "C with Classes".  He found a need for this when programming for his Ph.D. thesis.  Basically, he had found that Simula provided great programming facilities but was too slow, and BCPL was fast but not advanced enough.

In 1983 the name was changed to C++.
---
**Paradigm**
***

C++ allows us to program using the Object Oriented paradigm, but it doesn't impose a restriction that says we *must* use OO.  We could just create imperative procedural code.

This is primarily because C++ is a superset of C; anything legal in C is legal in C++.
---
**Warning!**
***

There are C ways of doing things and C++ ways of doing things.  These conventions, even if they are not expressly stated, are usually assumed by other programmers.

For instance, it is perfectly valid for us to use the <stdio.h> library in C++.  However, this library does not solve problems "the C++ way".  It doesn't use streams for input and output, doesn't have objects, etc.  Using it may compile ok but could add confusion for other programmers (or even for you later on!).
---
**Program Structure**
***

We are going to concentrate on Object Oriented C++.  Therefore we will structure our programs much like Java code we have written in the past.

The difference between Java is that the **Syntactic Unit** for an object's definition (the class) is contained in a single file.  In C++ it *can* be in a single file, but we usually split the class into an interface (\*.h file), and the implementation (\*.cpp file).
---
**Program Structure**
***

For instance, if we were going to create a car object we might have two files:

```Car.h``` which holds the function signatures (the declarations), and ```Car.cpp``` that holds the code (or definitions).
---
**Car.h**

```C++
#include <string>

class Car {

  public:
    // Constructor with no parameters.
    Car();

    // Constructor with parameters.
    Car(std::string make, std::string model, int year, double mileage);

    // Accessors
    std::string getMake();
    std::string getModel();
    int getYear();
    double getMileage();

    // Setters
    void setMake(std::string make);
    void setModel(std::string model);
    int setYear(int year);
    double setMileage(double mileage);

  private:
    std::string make;
    std::string model;
    int year;
    double mileage;

    // Fake function just to illustrate we can have functions
    // that are private too.
    void doNothing();

};    // Notice the semicolon at the end of the declaration!
```
---
**The Namespace Operator**
***

Looking at the previous code you may have noticed the "::" operator between std and string.  This is called the Namespace Operator (or Scope Resolution Operator); it signifies where a function is defined.
---
**The Namespace Operator**
***

In C++ we are allowed to separate code into namespaces.  If we declare a function of data type inside of a namespace it becomes part of that namespace.  That allows us to separate our code into logical groupings.  The "::" operator tells us from which namespace a function is being called.
---
**The Namespace Operator**
***

This also allows us to have functions with the same names, but in different namespaces.  In fact, it is not uncommon for programmers to wish to use the same names for data types of functions.

Notice how we define our functions from the Car.h file in a Car.cpp file.  We have to provide a namespace so the compiler knows specifically which functions we are trying to define:
---
**Car.cpp**

```C++
#include <string>

Car::Car(){
  make = "None";
  model = "None";
  year = 1900;
  mileage = 0.0;
}

Car::Car(std::string make, std::string model, int year, double mileage){
  this->make = make;
  this->model = model;
  this->year = year;
  this->mileage = mileage;
}

std::string getMake(){
  return make;
}

std::string getModel(){
  return model;
}

int getYear(){
  return year;
}

double getMileage(){
  return mileage;
}

void setMake(std::string make){
  this->make = make;
}

void setModel(std::string model){
  this->model = model;
}

void setYear(int year){
  this->year = year;
}

void setMileage(double mileage){
  this->mileage = mileage;
}

void doNothing(){

}
```
---
**Using Objects**
***

C++ uses a similar syntax to Java when creating objects:

```C++
Car a;      // Note that this actually creates the object!
            // Unlike Java in that respect.
Car b("Porsche", "911", 1972, 37228.3);
```
---
**Using Objects**
***

Once we have an object, we call its functions or access its public members just as we do in Java:

```C++
int mile = a.getMileage();
```

---
**Memory Management**
***

Just like in C, C++ manages memory for static (compile time, on the stack) objects only.  Dynamically created memory (run-time, on the heap) must be managed by the programmer.

When dynamically creating an object, we use the ```new``` keyword.

Take note!  The ```new``` keyword always returns a pointer.
---
```C++
Student a;      // Creates an object.
                // Static.  Cared for by
                // the system.

Student* b = new Student();   // Creates an object.
                              // On the Heap.  Cared
                              // for by you!
```

Advantages of the second method are that the scope is not limited to the block the object was created in, the size can change, and the object can "live" as long as we want it to.
---
## CAVEAT EXAMPLE!

```C++
Student getStudent(){
  Student a;
  return a;
}

int main(int argc, char** argv){
  Student b = getStudent();
}
```

**What does this do?**
---
The object was created statically in the block of a function.

The object is passed back by value (meaning it is copied!).

This is ok for small objects, but for large ones look out!
---
## Better:

```C++
Student* getStudent(){
  return new Student();
}

int main(int argc, char** argv){
  Student* b;
  b = getStudent();
}
```

This will work; the object is created dynamically (at run-time!).  It will exist on the heap, so not inside a function's memory.  It will exist after the return.  There is no need for this object to be copied; instead the pointer variable will be copied (pointers are always small, so no biggie).
---
**References**
***

Often though, in C++ we are going to be using references.

References are what you are (likely) used to using if you come from a Java background.  They can make it seem as if we are passing around an object (though we really aren't!).
---
**References**
***

Unfortunately, the designers of C++ decided to use the ```&``` operator to signify a reference - further lowering the readability of an already hard to read language.

This means in C++ we have to examine the context of the use of ```&```.  Is it a reference, is it the memory address of an object, etc.
---
**References**
***

**Warning!** We have to remember the memory model we are constrained to use.  This means we cannot return a reference to an object created inside of a function.

The memory that the reference points to does not exist after the function call returns.

The big problem is that it will *sometimes* work.  It depends on whether the stack space was overwritten since the object was created or not.
---
```C++
       │ File: ReferenceFromFunction.cpp
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ /*
   2   │  * This may work sometimes, but not other times.
   3   │  * You should NEVER do this.
   4   │  */
   5   │
   6   │ #include <string>
   7   │ #include <iostream>
   8   │
   9   │ class Student {
  10   │        public:
  11   │                static Student& getNew(){
  12   │                        Student tmp;
  13   │                        Student& two = tmp;
  14   │                        return two;
  15   │                }
  16   │                std::string name;
  17   │                int number;
  18   │ };
  19   │
  20   │ int main(int argc, char** argv){
  21   │        Student ira = Student::getNew();
  22   │        ira.name = "Ira";
  23   │        ira.number = 9;
  24   │
  25   │        std::cout << ira.name << std::endl;
  26   │ }
```
---
**The Big Five**
***

When an object is created in C++, it is given some functions.  These functions are the:

  - copy constructor
  - move constructor
  - copy operator=
  - move operator=
  - destructor
---
The move operator and move operator= are new as of C++11 so they aren't pertinent to older code.
---
**The Big Five**
***

The copy constructor is called whenever we pass an object as the parameter to the constructor of the same type.

It allows us to create a new object that is a copy of a prior one.

```C++
Student a;
a.gpa = 2.34;
a.number = 9293;
Student b(a);           // Student b is now a copy of a
```
---
**The Big Five**
***

But... what happens if we have an object like this:

```C++
Student {
  int number;
  float gpa;
  float* grades;
};

Student a;
Student b(a);
```
---
```C++
───────┬──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
       │ File: ShallowCopy.cpp
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ #include <iostream>
   2   │
   3   │ class Student {
   4   │        public:
   5   │                int number;
   6   │                float gpa;
   7   │                float* grades;
   8   │ };
   9   │
  10   │ int main(int argc, char** argv){
  11   │        Student a;
  12   │        a.grades = new float[50];
  13   │        a.grades[0] = 100;
  14   │        Student b(a);
  15   │        b.grades[0] = 46;
  16   │        std::cout << "Student a got a " << a.grades[0] << std::endl;
  17   │ }
```
---
We have a problem... During the copy we copied the pointer.  The pointer holds the memory location of a's grades.  Anytime we change a, it will change b's grades as well.  They will both be forced to have the same grades!
---
**The Big Five**
***

This is called a **shallow copy**.  We don't want just the values to be copied.

They both need memory areas for their own grades.  This is what we call a **deep copy**.
---
**The Big Five**
***

Since our object uses dynamic memory allocation we are going to have to rewrite (at least some of) The Big Five.  The default ones won't work for us because our object needs some custom behavior.

---
```C++
       │ File: DeepCopy.cpp
───────┼──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────
   1   │ #include <iostream>
   2   │
   3   │ class Student {
   4   │        public:
   5   │
   6   │                // Because we are overriding the constructor,
   7   │                // we need to provide a new default one as well.
   8   │                Student(){
   9   │
  10   │                }
  11   │		// Copy constructor
  12   │                Student(const Student& other){
  13   │                        // The first two fields we copy by copy
  14   │                        this->number = other.number;
  15   │                        this->gpa = other.gpa;
  16   │
  17   │                        // This is a pointer though... if we
  18   │                        // copy by copy we get the address.  We
  19   │                        // need a new memory area for it.
  20   │                        this->grades = new float[50];
  21   │
  22   │                        // Now copy the old values in.
  23   │                        for(int i=0; i<50; i++){
  24   │                                this->grades[i] = other.grades[i];
  25   │                        }
  26   │                }
  27   │
  28   │                int number;
  29   │                float gpa;
  30   │                float* grades;
  31   │ };
  32   │
  33   │ int main(int argc, char** argv){
  34   │        Student a;
  35   │        a.grades = new float[50];
  36   │        a.grades[0] = 100;
  37   │        Student b(a);
  38   │        b.grades[0] = 46;
  39   │        std::cout << "Student a got a " << a.grades[0] << std::endl;
  40   │ }
```
---
We use the copy constructor to create a new object that is a copy of a previous one.

Sometimes, we wish to set an existing object equal to another existing object.  For this, we use the copy operator=.
---
There are multiple ways of writing a copy operator=.  The generally accepted "best" way is to use the Copy-and-Swap method.  This method works by passing a copy of the original object in as a parameter to the function, instead of passing a reference.

Then, we steal the copy's data.
---
```C++
  28   │                /*
  29   │                 * Copy Operator=
  30   │                 * Pass copy of object in (will call
  31   │                 * the copy constructor!).  Then
  32   │                 * steal its data.
  33   │                 */
  34   │                Student& operator=(Student other){
  35   │                        // Swap our old data for the
  36   │                        // good new data.
  37   │                        std::swap(this->number, other.number);
  38   │                        std::swap(this->gpa, other.gpa);
  39   │                        std::swap(this->grades, other.grades);
  40   │
  41   │                        // Return ourself!
  42   │                        return *this;
  43   │                }
```
---
Why in the world don't we just copy the same way we did for the copy constructor?
---
Code duplication is bad.

This way, we leverage the copy code from the constructor.  If we ever need to change the copy code, we only change it in one place.
---
Additionally, here we are only swapping small data types (ints, etc.).  We could have just copied them.  But, if they were large data types (collections, etc.) swapping is much faster than copying.
---
C++ 2011 introduced Move Semantics.

This is based on the idea that it is much quicker for the computer to move an object than to create a new one.
---
Makes a lot of sense; if we create a new object in a function, and then try to pass that object back as a return value, it gets copied (via its copy constructor).

If it is a complicated object to create this is very, very slow.

If we are already creating it in the function, then let's just move the one we created instead.
---

