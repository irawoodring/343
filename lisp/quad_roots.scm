(define (quadratic_roots a b c)
  (let (
    (root_part_over_2a
		(/ (sqrt (- (* b b) (* 4 a c))) (* 2 a)))
    (minus_b_over_2a (/ (- 0 b) (* 2 a)))
  )
  (list (+ minus_b_over_2a root_part_over_2a)
	(- minus_b_over_2a root_part_over_2a))
  )
)
