grade(Grade, a) :- Grade >= 90, Grade <= 100.
grade(Grade, b) :- Grade >= 80, Grade < 90.
grade(Grade, c) :- Grade >= 70, Grade < 80.
grade(Grade, d) :- Grade >= 60, Grade < 70.
grade(Grade, f) :- Grade < 60.

