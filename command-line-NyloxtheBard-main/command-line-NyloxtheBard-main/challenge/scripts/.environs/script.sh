#!/bin/bash

$PWD

export MYVARIABLEONE="This is my first variable"

export MYVARIABLETWO=420

touch var_out_1.txt
touch var_out_2.txt
touch var_tot_out.txt

echo $MYVARIABLEONE > var_out_1.txt
echo $MYVARIABLETWO > var_out_2.txt

cat var_out_1.txt var_out_2.txt > var_tot_out.txt
cat var_tot_out.txt 
