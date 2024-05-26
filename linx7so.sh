#!/bin/bash

dir=$1

if [[ ! -d $dir ]] then
   echo "metti na cartella strunz"
else
   for file in $dir/*
   do
      if [[ -f $file ]] then
         echo "è un file"
      fi
      if [[ -d $file ]] then
         echo "è una cartella"
      fi
   done
fi
