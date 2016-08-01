#!/bin/bash

: ${1?"Usage: $0 ARGUMENT"}
for file in /{,usr/}bin/*calc
do
        if [ -x "$file" ]
        then
          echo $file
        fi
done
