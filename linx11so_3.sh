#!/bin/bash

#sincero volevo fare un for, mi salvo la città e poi itero su tutte le righe del file aggiungendo tramite una variabile di appoggio il numero di occorrenze
# ma bash è stronzo e non funzione come python

#ricorda che uniq -c prende il numero di occorrenze strunz
#mi prendo il contenuto dei vini, prendo il nome, ordino e conto le occorrenze con uniq -c

cat vini.txt | cut -d " " -f 3 | sort | uniq -c



#per il valore maggiore e minore uso sort con -n e -r
min=$( cat vini.txt | sort -k 2 -n | cut -d " " -f2)
max=$( cat vini.txt | sort -k 2 -r | cut -d " " -f2)
val=$max - $val
echo $val
#il prof ha usato solo una sort, cioè dal piu basso al piu alto
#poi ha preso il valore usando head (prima riga) e tail (ultima riga)
#io invece sono un figo e uso due sort diversi di ordinazione
