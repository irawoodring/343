---
CIS 343 - Structure of Programming Languages

Ira Woodring

***

Language Spotlight - Ruby
A Dynamically Typed Language
---
**Overview**
***

Ruby was created by Yukihiro "Matz" Matsumoto.  He goes by "Matz".

He created the language in 1995 to combine features he loved from Perl, Smalltalk, Eiffel, Ada, and Lisp.
---
**Overview**
***

As of the time of this writing (Fall 2017), it was \#10 on the Tiobe index, up from \#13 the year before.

[Tiobe Index](https://www.tiobe.com/tiobe-index/ "Tiobe Index")
---
**Overview**
***

Like Python, Ruby is an interpreted language.

Matz is quoted as saying he wanted "a scripting language that was more powerful than Perl, and more object-oriented than Python."
---
**Overview**
***

Unlike some other languages where numbers and primitives are not objects, in Ruby EVERYTHING is an object.

This is obvious from the fact that we can run this code (from the Ruby About pages):

```Ruby
5.times { print "We *love* Ruby -- it's outrageous!" }
```
---
**Overview**
***

Just like Python, Ruby allows you to add a member to a class or object at any time.

Unlike Python, Ruby also allows us to remove members at any time:

```Ruby
class Blah
  def say_hi(name)
    puts "Hi, #{name}!"
  end
end

b = Blah.new()
=> #<Blah:0x007fae7c854238>
b.say_hi("Ira")
Hi, Ira!
b.instance_eval('undef :say_hi')
b.say_hi("Ira")
NoMethodError: undefined method 'say_hi' for #<Blah:0x007fae7c854238>
        from (irb):56
        from /usr/bin/irb:11:in '<main>'
```
---
**Overview**
***

Ruby uses the following syntax for variables:

- **$var** is a global variable.  As always, we should avoid these.

- **@var** is an instance variable.

- **@@var** is a class variable.

- **var** or **_var** is a local variable.

- **VAR** is a constant.
---
**Overview**
***

Ruby arrays are created similar to Python's lists:

```Ruby
friends = [ "Ira", "Annie", "Jake", "Abby"]
```

Hashes are similar to Python as well:

```Ruby
calories = { "bigmac" => 1200, "salad" => 150, "fries" => 600}
```
---
**Overview**
***

We can iterate over the above collections as such:

```Ruby
friends.each do |f|
  puts i
end

calories.each do |key, value|
  puts "#{key}s have #{value} calories."
end
```
---
**Overview**
***

Notice that Ruby blocks are not delineated via whitespace (as in Python), but via a starting definition (such as ```class Animal```, ```def function()```, or ```do```), and an ```end``` statement.
---
**Overview**
***

Classes are created in Ruby as such:

```Ruby
##
# Creates an Animal object
class Animal
  @@num_animals = 0
  def initialize(name, num_legs)
    @name = name
    @num_legs = legs
  end
end

horse = Animal.new("horse", 4)
bird = Animal.new("bird", 2)
```
---
**Overview**
***

Just like Python, Ruby does not allow overloaded constructors (or methods).

Also like Python there are multiple ways to accomplish the same result; we will not discuss those ways here, as there are a great number of opposing views on the subject.

Good overviews (and arguments) on the subject abound online.
---
**Overview**
***

All instance variables in Ruby are private by default.

```Ruby
class Person
  def initialize(name)
    @name = name
  end
end

me = Person.new("Ira")
me.name
NoMethodError: undefined method 'name' for #<Person:0x007fae7c120d68 @name="Ira">
        from (irb):92
        from /usr/bin/irb:11:in '<main>'
```
---
**Overview**
***

We need to create an **attribute reader** to access the data:

```Ruby
class Person
  def initialize(name)
    @name = name
  end

  def name
    @name
  end
end

me = Person.new("Ira")
me.name
=> "Ira"
me.name()
=> "Ira"
```
---
**Overview**
***

We could also create an **attribute writer** to change the data:

```Ruby
class Person
  def initialize(name)
    @name = name
  end

  def name=(name)
    @name = name
  end
end

me = Person.new("Ira")
me.name = "Abe"
me.name
NoMethodError: undefined method 'name' for #<Person:0x007faad08a2000 @name="Abe">
Did you mean?  name=
        from (irb):15
        from /usr/bin/irb:11:in '<main>'
```
---
**Overview**
***

If we had both functions we would say we have created an **attribute accessor**:

```Ruby
class Person
  def initialize(name)
    @name = name
  end

  def name
    @name
  end

  def name=(name)
    @name = name
  end
end
```
---
**Overview**
***

However, Ruby doesn't require us to recreate these functions when they use default behavior.  Instead, we can use the following:

```Ruby
class Person
  attr_accessor :name
  def initialize(name)
    @name = name
  end
end
```
---
**Overview**
***

We could have also used ```attr_reader```, or ```attr_writer``` if we wanted to limit access to our data in some way.
---
**Overview**
***

Ruby allows inheritance, but unlike Python (which provides multiple inheritance), Ruby allows only single inheritance.

(Although Ruby does allow mixins which we will see later).

```Ruby
##
# Creates an Animal object


h = Horse.new("Trigger", 4, "Brown")
```
---
**Overview**
***

In addition to classes, Ruby also provides **Modules**.  Modules are used for group related functions that might not need to exist as an instance of a class.

For example, we may want to provide a set of functions for mathematical operations.  There is no need to have an instance of a Math object from which we could call a ```sin```, ```pow```, or ```abs``` function.

In addition to providing a "home" for these functions, modules also provide a namespace.  This is important as it helps us to avoid name collisions of members.
---
**Overview**
***

```Ruby
module MathyStuff
  def abs(num)
    ...
  end
  def sin(num)
    ...
  end
end

MathyStuff.abs(-42)
```
---
**Overview**
***

One of the greatest things about modules in Ruby is the ability to use them as **Mixins**.

By including a module in a class, instances of our class gain the members of the module.  This allows us to simulate multiple inheritance; we merely include any modules that provide the functionality we wish to use.
---
**Overview**
***

A Mixin example (from [RubyDocs](http://ruby-doc.com/docs/ProgrammingRuby/html/tut_modules.html "Modules and Mixins")):

```Ruby
module Debug
  def whoAmI?
    "#{self.type.name} (\##{self.id}): #{self.to_s}"
  end
end
class Phonograph
  include Debug
  # ...
end
class EightTrack
  include Debug
  # ...
end
ph = Phonograph.new("West End Blues")
et = EightTrack.new("Surrealistic Pillow")
ph.whoAmI?	»	"Phonograph (#537766170): West End Blues"
et.whoAmI?	»	"EightTrack (#537765860): Surrealistic Pillow"
```
---
**Sources**
***

- https://www.ruby-lang.org/en/about/
