male(bill).
male(jake).
female(shelley).
female(mary).
father(bill, jake).
father(bill, shelley).
mother(mary, jake).
mother(mary, shelley).
mother(jean, mary).
parent(X, Y) :- mother(X, Y).
parent(X, Y) :- father(X, Y).
grandparent(X, Z) :- parent(X, Y), parent(Y, Z).
