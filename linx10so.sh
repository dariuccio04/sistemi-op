#!/bin/bash

fi (( "$# != "2" ))
then
   echo "servono due argomenti"
else
   cat $1/*.c $1/*.h | grep $2 > /tmp/output.txt
fi
#utilizziamo cat quando lo stdout lavora con i file, utilizziamo echo quando lavoriamo con le stringhe
# stiamo passando come output a grep, il contenuto dei file c e bash, a prima vista sembra che
#sembra che stiamo passando il file $1.c e $1.h ma con /* in realtà stiamo cercando dentro tutta (/*) la cartella ($1) i file con terminazione .c e .sh
# questi file sono dati come output a grep $2 che cercherà il patter $2 e lo inserirà nel file output.txt
# possiamo leggerla come un equazione:
# ( cat //////// | grep // ) > ////// -> prima risolviamo quello che c'è dentro le parentesi e poi il resto 
