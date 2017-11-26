;;;; Fibonacci Numbers
;;;; https://groups.csail.mit.edu/mac/users/gjs/6.945/dont-panic/#sec-2-2-2

(define (fib n)
  ;; Calculate the nth Fibonacci number recursively
  (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2)))))
