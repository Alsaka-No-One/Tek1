#!/bin/bash  
echo $1
blih -u alain1.nguyen@epitech.eu repository create $1
blih -u alain1.nguyen@epitech.eu repository setacl $1 ramassage-tek r
blih -u alain1.nguyen@epitech.eu repository getacl $1
exit
