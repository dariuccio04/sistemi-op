#!/bin/bash

#esercizio 2 programmazione bash


read n

if (( $n < 10 ))
then
   for ((i = 0 ; i < $n; i++))
   do
      touch $i.txt
   done
fi
