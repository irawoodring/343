;; Euclidean Method of GCD
(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (modulo a b))))

;; Recaman's Sequence
;; Not checking if number already exists.
;; Breaks down after 5 numbers.
(define (recaman n)
  (if
    (= n 1) 1
    (if (> (- (recaman (- n 1)) n) 0)
      (- (recaman (- n 1)) n)
      (+ (recaman (- n 1)) n))))
