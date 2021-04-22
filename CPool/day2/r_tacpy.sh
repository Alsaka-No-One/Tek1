#!/bin/bash
cut -d: -f 1 | sed -n 2~2p | rev | sort -r | head -n $MY_LINE1 | tail -n $MY_LINE2 | tr "\n" "," | sed -e "s/,/, /g" | sed "s/, $/.\n/g"
