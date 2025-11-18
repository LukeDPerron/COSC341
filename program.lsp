;check if L has an atom in it
(defun f1 (L)
    (cond
    ((null L) nil) ;if list is empty, return nil
    ((atom (car L)) t) ;if the first item of list is an atom, return true
    (t (f1 (cdr L))) ;else check the next list item
    )
)

(defun f2 (L)
    (cond
        ((null L) 0) ;if list is null, return 0
        ((and (listp (car L)) (equal(length(car L)) 1))(+ 1 (f2 (cdr L)))) ;if first element is a list and is length 1, add 1 and do next
        (t (f2 (cdr L))) ;else, check rest of list
    )
)

(defun f3 (L)
    (cond
        ((null L) nil) ;if list is null, return nil
        ((oddp (car L)) (cons (car L) (f3 (cdr L)))) ;if first element of L is odd, use cons to insert it into next run of function
        (t (f3 (cdr L))) ;else, go to next element in L
    )
)

(defun f4 (L)
    (cond
    ((null L) nil) ;if L is null, return nil
    ((null (cdr L)) (car L)) ;if the rest of L is null, return L
    ((< (car L) (f4 (cdr L))) (car L)) ;if first element of L is greater than next element, return that element
    (t (f4 (cdr L))) ;else go to next element
    )
)

(defun f5 (L)
    (cond 
    ((null L) L) ;if list is null, return it
    (t (append (f5 (cdr L)) (list (car L)))) ;else return the end of list appended to beginning of list
    )
)

(defun f6 (L)
    (cond
    ((null L) nil) ;if list is null, return nil
    (t (cons (car L) (f6 (cdr (cdr L))))) ;else return the first element cons to the beginning of every other element
    )
)

(defun f7 (L x)
    (cond
    ((null L ) nil) ;if list is null, return nil
    ( (equal x 1) (car L)) ;if x equals 1, return the beginning of the list
    (t (f7 (cdr L) (- x 1))) ;else if x doesn't equal 1, get the rest of the list and subtract 1 from x
    )
)

(defun f8 (L)
    (cond
    ((null L) 0) ;if list is null, return 0
    ((atom (car L)) (+ (*(car L) (car L)) (f8 (cdr L)))); if list is an atom, add squared to total then go to next element
    (t (+ (f8 (car L)) (f8 (cdr L)))); if list item is another list, add together beginning with rest
    )
)

;decides whether x is member of L
(defun my_member (x L)
(cond ((null L) nil) ;if L is empty then x is not in L
((equal x (car L)) T) ;if x is first element of L then x is in L
(T (my_member x (cdr L))) ;else check x is in cdr of L
)
)

(defun f9 (L)
    (cond
    ((null L) nil) ;if list is null, return nil
    ((my_member (car L) (cdr L)) (f9(cdr L))) ;if first element is member of the rest of list, go to next element
    (t(cons (car L) (f9(cdr L)))) ;else, add the first element to the beginning of the list
    )
)

(defun f10 (L M)
    (cond 
    ((null L) nil) ;if either list is null, return nil
    ((null M) nil)
    ( (my_member (car L) M) 
        (cons (car L) (f10 (cdr L) M))) ;if the first element in L is in M, then add it to list
    (t(f10 (cdr L) M)) ;else, go to next element of L
    )
)


(print (f1'((a b)(c d))))
(print (f2 '(a (a b) (e) c ((b c)) ((d) c b))))
(print (f3 '(13 4 7 18 21)))
(print (f4 '(6 9 3 7 10 5)))
(print (f5 '(a (b c) (x) d)))
(print (f6 '(c (a b) d (x y)(a) b)))
(print (f7 '(c (a b) (c d) c (b)) 3))
(print (f8 '(2 (5 4) 3 (2 (1 7)) 5)))
(print (f9 '(c (a b) c d (a b))))
(print (f10 '(a (a b) c d) '(b(a b) d)))
