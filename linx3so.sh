#!/bin/bash

read n_s1
read n_s2

if [[ $n_s1 = $n_s2 ]]
then
    echo "ok_s"
else
    echo "no"
fi

if (( $n_s1 == $n_s2 ))
then 
    echo "ok_n"
else
    echo "ok"
fi
#mi sembra davvero strano che se do come input due stringhe o due numeri, l'output è lo stesso
#non c'è differenza tra numeri e stringhe negli if "(())" e "[[]]" ma bash è strano quindi romperà le palle in altre strutture

