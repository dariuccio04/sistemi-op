#!/bin/bash

#esercizio 1 programmazione bash



#controllo arg
if [[ "$#" != "2" ]] then 
   echo "ne servono due strunz"
fi

arg1=$1
arg2=$2

if [[ -f $arg1 ]] && [[ -f $arg2 ]] then
   cat $arg1
   cat $arg2
else
   echo "non sono file bucchin"
fi
