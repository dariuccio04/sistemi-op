#!/bin/bash

#verifica condizioni su file

path=$1
echo $path

#verifico che esista
if [[ -a $path ]] then
   echo "il path esiste"
   #verifico che sia un file
   if [[ -f $path ]] then
      echo "è un file"
      #verifico se sia vuoto
      if [[ ! -s $path ]] then
      echo "vuoto"
      else
         echo "non vuoto"
      fi
      if [[ -r $path ]] && [[ -w $path ]] && [[ -x $path ]] 
      then
         echo "posso scrivere, leggere ed eseguirlo"
      fi
   fi
   #verifico che sia una cartella/dir
   if [[ -c $path ]] then
      echo "è una cartella"
      if [[ -r $path ]] && [[ -w $path ]] && [[ -x $path ]] 
      then
         echo "posso scrivere, leggere ed eseguirlo"
      fi
   fi
else
echo "no"
fi
