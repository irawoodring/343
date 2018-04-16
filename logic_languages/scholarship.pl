% ####################################################################
% Logic puzzle solver.
%
% Read definition to prolog:
%   ['puzzle.pl'].
%
% 2) Ask for solutions:
%   solve(Carrie,Erma,Ora,Tracy).
%
% Rainhard Findling
% 10/2015
% ####################################################################
 
all_members([H],L2) :- member(H,L2).
all_members([H|T],L2) :- member(H,L2), all_members(T, L2).
 
or([H]) :- H,!.
or([H|_]) :- H,!.
or([_|T]) :- or(T).
 
solve(Carrie,Erma,Ora,Tracy) :-
% all students
Carrie = [Carrie_scholarship, Carrie_major],
Erma = [Erma_scholarship, Erma_major],
Ora = [Ora_scholarship, Ora_major],
Tracy = [Tracy_scholarship, Tracy_major],
% grouping
All = [Carrie,Erma,Ora,Tracy],
% ensure all values exist once
all_members([25, 30, 35, 40], [Carrie_scholarship, Erma_scholarship, Ora_scholarship, Tracy_scholarship]),
all_members([astronomy, english, philosophy, physics], [Carrie_major, Erma_major, Ora_major, Tracy_major]),
% clue 1
member([C1_scholarship,astronomy], All),
Ora_scholarship > C1_scholarship,
% clue 2
or([Ora_major = english, Ora_major = philosophy]),
% clue 3
member([C3_scholarship, physics], All),
C3_scholarship - Carrie_scholarship =:= 5,
% clue 4
Erma_scholarship - Carrie_scholarship =:= 10,
% clue 5
member([C5_scholarship, english], All),
Tracy_scholarship > C5_scholarship.

