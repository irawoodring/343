% Taken from http://www.dorkly.com/post/8577/flowchart-what-gaming-platform-is-right-for-you
system(Person, xbox_knect) :- flailing(Person, no), gamer(Person, no).
system(Person, wii) :- flailing(Person, yes), gamer(Person, no).
system(Person, nintendo) :- written_fan_fict(Person, no), genre(Person, adventure), masochist(Person, no), gamer(Person, yes).
system(Person, genesis) :- written_fan_fict(Person, yes), genre(Person, adventure), masochist(Person, no), gamer(Person, yes).
system(Person, snes) :- like_spiky_hair(Person, no), genre(Person, rpg), masochist(Person, no), gamer(Person, yes).
system(Person, playstation) :- like_spiky_hair(Person, yes), genre(Person, rpg), masochist(Person, no), gamer(Person, yes).
system(Person, pc) :- rich(Person, no), genre(Person, fps), masochist(Person, no), gamer(Person, yes).
system(Person, xbox360) :- rich(Person, yes), genre(Person, fps), masochist(Person, no), gamer(Person, yes).
system(Person, virtual-boy) :- masochist(Person, yes), gamer(Person, yes).
