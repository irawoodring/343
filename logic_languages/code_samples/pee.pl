where(X, side_of_road) :- location(X, car), traffic(X, yes), hold_it(X, no).
where(X, cup) :- location(X, car), traffic(X, no), hold_it(X, no).
