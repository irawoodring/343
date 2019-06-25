% Based on menu code from https://cse.sc.edu/~ahein/330/example.html

call_option(1) :-
    write('Enter the query:'), nl,
    read(Query),
    print_query_true(Query),
    print_query_false(Query).

call_option(2) :-
    write('Quitter...'), nl, halt.

call_option(_) :-
    write('Not a valid option'), nl, halt.

print_query_true(Q) :-
    forall(Q, writeln(true:Q)).

print_query_false(Q) :-
    forall(\+ Q, writeln(false:Q)).

main :-
    nl,
    write('Choose one of the following options:'), nl,
    write('\t1. Query the system'), nl,
    write('\t2. Quit'), nl, nl, read(Option),
    call_option(Option), main.
