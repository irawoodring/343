kid(keenan).
kid(cas).
kid(ollie).
kid(hatter).
kid(bri).
kid(wes).
kid(zac).
kid(emma).
kid(ally).
mother(sarah, keenan).
mother(sarah, cas).
mother(sarah, ollie).
mother(sarah, hatter).
mother(koti, bri).
mother(koti, wes).
mother(koti, zac).
mother(deb, sarah).
mother(deb, koti).
mother(deb, greg).
sibling(Y, Z) :- mother(X, Y), mother(X, Z), not(Y == Z).
parent(X, Y) :- mother(X, Y).
grandparent(X, Z) :- mother(X, Y), mother(Y, Z).
cousin(Y, Z) :- parent(W, Y), parent(X, Z), sibling(W,X).
descendent(X, Y) :- mother(X, Y).
descendent(X, Y) :- mother(X, Z), descendent(Z,Y).
