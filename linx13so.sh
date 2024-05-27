#!/bin/bash

cart1=$1
cart2=$2

#for file in $cart1/*
#sarebbe figo se potessimo fare questo
#ma bash non riconosce il formato file da solo
# -> if -f -> find $1 (cerco MA DOVE?) -type f (CHE COSA?)

for f in $( find $1 -type f )
do
   folder=$2/$( echo $f | cut -d . -f 2)
   mkdir -p $folder
   cp $f $folder
done

#codice un po strano forte
# andiamo a creare con folder la cartella composta, da una parte della cart2, poi ci mettiamo un po di guanciale e pecorino, no scherzo
# ci mettiamo il nome del file diviso (sarà del tipo nome.tipo)
# vogliamo suddivedere anche in sottocartelle in base all'estensione quindi andiamo ad utilizzare il comando il comando mkdir -p (con -p andiamo a creare anche le sottocartelle)
