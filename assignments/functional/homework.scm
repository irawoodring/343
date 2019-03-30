(define (print-command command)(display "You chose ")(display command)(newline))

(define (evaluate command)
   (cond 
         ((string=? command "forward") (display "Forward.")#t)
         ((string=? command "backward") (display "Backward.")#t)
         ((string=? command "quit")(exit))
         (else #f))
)

(define (next-command command)
  (print-command command)
  (display "You're move.")(newline)
  (read-line))

(define (game-loop command)
   (if (evaluate command)
      (game-loop (next-command command))
      ((display "Not a command.")(game-loop (next-command command))))
)
