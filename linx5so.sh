#!/bin/bash

#path da tastiera, se sono uguali allora vediamo se esso corrisponde ad una cartella


read path1
read path2

if [[ $path1 = $path2 ]] then
   if [[ -d $path1 ]] then
      echo $path1
   else
      echo "non è una cartella"
   fi
else
   echo "non sono uguali strunz"
fi
