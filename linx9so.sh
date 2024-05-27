#!/bin/bash

#file1=$1
#file=$2

#for file in $1/*
#do
#   if [[ $file = $1 ]]
#   then
#      $file > $2
#   fi
#done
#semplicemente tutto sto codice su non funziona per vari motivi
# 1: ovviamente non ci sono controlli di validità di input
# 2: improbabile che se devo passare una cartella quindi con indirizzo assoluto, ci sia un file che abbia stesso nome di path tranne la cartella stessa
# 3: è un codice da polli
# codice corretto:

if (( "$#" != "2" ))
then
   echo "servono due argomenti"
else
   if [[ -f $2 ]]
   then
      find . -name $1 > $2
# spiegazione di sta riga bastarda: find, il comando find vuole trovare qualcosa
# ma dove ?  -> . è la directory corrente (.. è la dir padre)
# cosa vuole cercare -> un nome
# ma di chi? -> di $1 (primo file)
   fi
fi
#ho notato che il comando find potrebbe andare in parti non autorizzate
# 1 se si hanno i permessi si può usare il comando sudo
# ignorare lo stderr, aggiungere a find "  2>/dev/null
# 2 indica lo stderr che andrà a mettersi in /dev/null, un file che ignora quello che viene passato
# si può aggiunere -readable per dare accesso a find solo ai file autorizzati 
