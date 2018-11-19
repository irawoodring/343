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

The child has copies of all the parent information.
---
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
---
It is important to understand that an object does not hold a property it gets from a prototype.  Note the following:

```Javascript
> var first = { name: 'first' }
undefined
> first
{ name: 'first' }
> var second = { type: 'second' }
undefined
> second
{ type: 'second' }
> Object.setPrototypeOf(second, first)
{ type: 'second' }
> second
{ type: 'second' }
> second.name
'first'
>
```
---
This isn't like classical inheritance; second doesn't now have an instance variable 'name'.  It simple inherits the properties of first.

If we want second to have 'name' set to 'two' we can do that; but that is going to override the property we got from the prototype.
---
```Javascript
> second.name
'first'
> second.name='two'
'two'
> second
{ type: 'second', name: 'two' }
>
```

Notice that second now has a name property?  We have overriden (basically hidden) the prototype property because our object now holds its own with the same name.
---
If we ever wish to add to the prototype, all objects that use the prototype gain access to the new properties as well:

```Javascript
> var Computer = { ram:'16G', cores:4}
undefined
> var Laptop = { portable:'yes' }
undefined
> Object.setPrototypeOf(Laptop, Computer)
{ portable: 'yes' }
> Laptop.cpu_speed
undefined
> Computer.cpu_speed = '3.7G'
'3.7G'
> Laptop.cpu_speed
'3.7G'
>
```
---
---
Before we get into how to create objects in Javascript, let us discuss the difference between two keywords:

```let``` and ```var```
---
These two operators both allow us to create new objects.  The difference is a difference in scope.  ```let``` creates an object in the local block's scope, while ```var``` creates an object in the global scope.  Consider an example of a for loop:

```Javascript
> for(let i=0; i<5; ++i){
... console.log(i)
... }
0
1
2
3
4
undefined
> console.log(i)
ReferenceError: i is not defined
>
```
---
```Javascript
> for(var i=0; i<5; ++i){
... console.log(i)
... }
0
1
2
3
4
undefined
> console.log(i)
5
---
In Javascript objects are hash maps (key-value pairs).  The keys are strings and the values are objects (functions are objects too).

Since Javascript is dynamic we can add to the hash map at any time:
---
```Javascript
var myComputer = new Object();
myComputer.ram = '16G'
myComputer.cores = 4
```
 Or

```Javascript
var myComputer = new Object();
myComputer['ram'] = '16G'
myComputer['cores'] = 4
```
---
We can also use the following syntax:

```Javascript
var myComputer = { ram: '16G', cores: 4 };
```

Or, we could use the Object.create() function:
---
```Javascript
var Computer = { ram: '16G', cores: 4 };

var myComputer = Object.create(Computer);
```

We can even simulate classical inheritance:
---
```Javascript
function Computer(ram, cores) {
	this.ram = ram;
	this.cores = cores;
}
undefined
>
> var myComputer = new Computer('16G', 4);
undefined
> myComputer
Computer { ram: '16G', cores: 4 }
```
---
**Note!**

This doesn't change anything; it is just syntactic sugar.  We are merely creating an object in a way that looks like the classical way.  Also, this does not mean that ```Computer``` is the prototype of ```myComputer```.  We have simply created multiple Car functions (which are objects).
---
I will likely use each of these versions in class; if I know that I'm not going to need multiple similar objects I usually don't worry with the overhead of simulating the classical method.
---
Functions, just like any other object, can be a property of an object.  We define functions with the ```function``` keyword:

```Javascript
myComputer.startup = function(message){ console.log(message); }
[Function]
myComputer.startup("Booting now!")
Booting now!
```
---
Of note is that a property that has not been created is ```undefined```, not ```null```.  We can set a property equal to ```null``` to indicate it has no value, but if we are checking to see if a property exists we would use ```undefined```:

```Javascript
> var one = { name: 'CIS 343' };
undefined
> one.description
undefined
> one.description === undefined
true
```
---
Javascript syntax is very similar to Java.  We define blocks with curly braces ("{}").  Conditionals make use of parenthesis.

```Javascript
var i = 0;
for(let x=0; x<100; ++x){
	i = i + x
}

if(i>100){
	console.log(i);
}
```
---
We are going to concentrate on server-side Javascript for our project.  Out Javascript engine will be NodeJS.

NodeJS runs on any platform and is used by the biggest names in computing, such as Microsoft and IBM, and many other large organizations such as Netflix and Walmart.
---
Closely related to NodeJS is npm, a Javascript package manager.  By creating package files that specify the required software and versions for a project, npm allows programmers to easily share code.  To setup a system to run another programmer's code, a user need only type ```npm install``` and the needed libraries from the package file will be installed.
---
For our sample program we are going to create a server that responds to GET requests.  This project will require us to understand a little bit about HTTP.
---
HTTP is the protocol of the web (the language the machines on the web use to talk to one another).  It is based on two fundamental concepts:  Requests and URLs.
---
Requests are verbs that a client sends to a server. Valid requests are:

- GET - Asks for a resource.  Should be idempotent.

- HEAD - Asks for metadata for a resource.  Just like GET but doesn't return the request body.

- POST - asks server to accept a resource.

- PUT, DELETE, TRACE, OPTIONS, CONNECT, PATCH as well.  We won't be using these.
---
We will be using a web framework called ExpressJS.  This framework allows us to VERY quickly create "routes", or responders for requests.  The following is a minimal Express app:
---
```Javascript
const express = require('express')
const app = express()
const port = 3000

app.get('/', (req, res) => res.send('Hello World!'))

app.listen(port, () => console.log(`Example app listening on port ${port}!`))
```
---
This application is incredible simple; we import the express library, create a new application object from the library, and set a route for the "GET /" request.  Let's try it out!

```Javascript
node server.js
```
---
[http://localhost:3000](http://localhost:3000 "GET / request")

or via telnet:
---
```
Iras-MacBook-Pro:~ woodriir$ telnet localhost 3000
Trying ::1...
Connected to localhost.
Escape character is '^]'.
GET /

HTTP/1.1 200 OK
X-Powered-By: Express
Content-Type: text/html; charset=utf-8
Content-Length: 12
ETag: W/"c-Lve95gjOVATpfV8EL5X4nxwjKHE"
Date: Mon, 19 Nov 2018 15:06:35 GMT
Connection: close

Hello World!Connection closed by foreign host.
```
---
