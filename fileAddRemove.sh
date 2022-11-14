#!/bin/bash
input="../files.txt"
while IFS= read -r line
do 
  echo $line
  echo "git rm $line"
  git rm $line
done <"$input"
