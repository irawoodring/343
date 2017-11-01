# RPG with Objects

It seemed like a normal Halloween Eve.  You bought a lot of candy, ate a lot of candy, and went to bed early.  You had a lot trick-or-treating to do the next day.

Unfortunately, when you woke up you discovered that the world was not how you left it.  Batches of bad candy had transformed your friends and neighbors into all sorts of crazy monsters.  Somehow you missed the tainted candy; it is therefore up to you to save your neighborhood and turn everyone back to normal.

Before you can do that though, you need to work out your plan of attack.  To do that, you will create a computer program to model your neighborhood.  After playing it a few times you should have a good idea of how to save everyone.  You've been studying object-oriented programming; this seems like a great time to test out what you've learned.

## Objects

Your program should model your neighborhood, the monsters in it, you, and the interactions between objects.

**Home**

Homes are full of 0-10 monsters.  These do not need to be the same type of monster, in fact, some homes may have all types of monsters living within.  The population of the homes is randomly generated when the home is created.  The home should *observe* the monsters living within, and change the population if notified of some event.

**Neighborhood**

The neighborhood is made up of homes laid out in a grid.  When created, the neighborhood should automatically build houses and attach them to one another in a grid.  The size of the grid is set when the neighborhood is created.

**Monster**

A monster is either a Person, a Zombie, a Vampire, a Ghoul, or a Werewolf.  All of these are Monsters, so they share some basic properties such as health points and attack strength.  However, each has very different possible values.  The values of attack strength and health are set when the Monster is created.

  - Persons help you by giving you candy.  Each piece of candy increases your health by 1 point.  A person can give you 1 piece of candy per turn.  We could see this "helping" from the person as an attack with a negative attack value.  Persons have 100 health and are not harmed by your attacks.

  - Zombies attack you at a rate of 0-10 HP per turn.  Zombies are harmed by any weapon, but if attacked with SourStraws lose twice the number of points from an attack.  Start with between 50 and 100 HP.

  - Vampires attack at a rate of 10-20 HP per turn.  They are not harmed by ChocolateBars.  Start with 100-200 HP.

  - Ghouls attack at a rate of 15-30 HP per turn.  They are harmed by all weapons, but receive 5X the attackers attack if attacked with NerdBombs.  Start with 40-80 HP.

  - Werewolves attack at a rate of 0-40 HP per turn.  They are not harmed by ChocolateBars or SourStraws.  Start with 200 HP.

  When a monster loses all its HP it becomes a person.  This is accomplished by the monster notifying the Home it lives in.  This causes the Home to remove the Monster and replace it with a new Person.

**Weapon**

All weapons have a name and an attack modifier.  The attack modifier multiplies the player's attack by a floating point value between 1 and 5.

  - HersheyKisses are the basic weapon.  No one ever runs out of HersheyKisses.  Unfortunately they have an attack modifier of 1.
  - SourStraws provide an attack modifier between 1 - 1.75.  They can be used twice.
  - ChocolateBars modify the players attack by between 2 - 2.4.  They are usable 4 times.
  - NerdBombs are the best weapon in the game, modifying a player's attack by between 3.5 and 5.  Unfortunately, they are single use.

Weapons attack all monsters in a house at once.

**Player**

This is you.  You have a certain amount of HP, randomly generated between 100 - 125.  You also have an attack value, between 10-20.  You are able to hold 10 weapons; these are randomly generated and added to your inventory when you are created.

**Game**

The game holds an instance of a Neighborhood and a Player.  The player must navigate the neighborhood attacking monsters until she either dies or all monsters are turned to people.  The game should observe the houses.  When a house population changes, the game will be notified and should reduce the number of monsters in the neighborhood.  The Game will be created by the program's main method.

## Hints!

- Read up on the Observer pattern.  We will talk about this in class.

- Plan out your program *before* you begin programming.  This will save you a GREAT deal of time in the long run.

- Use either Ruby or Python, but BE CAREFUL.  You MUST adhere to Object-Oriented programming techniques (polymorphism and encapsulation!).

## Grading

Rubric:

| Criteria | 5 Points | 3 Points | 0 Points |
|----------|----------|----------|----------|
| Proper O-O | Adheres to concepts of encapsulation and polymorphism | Did at least one of those things correctly | Completely forgot what OO is. |
| Style Guide | Perfectly adheres to style guide | Minor style guide mistakes | Fails to adhere to style guide |
| Follows Project Specifications | No requirements omitted | 1 - 2 requirements omitted | More than 2 requirements omitted |
| Error handling | Gracefully handles input errors | Handles at least one type of error gracefully | Does not include error handling |
| On time | Submitted before due date and time | Submitted up to 1 day late | Submitted more than 1 day late |

## Submission Process and Deadline

This assignment is due on Friday, November 17 at midnight. Submit as follows:

>Upload to Blackboard, either by zipping your files or by commenting with a Github URL (Preferred!).

If you have questions about this process, see me immediately.
