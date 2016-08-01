
#!/bin/bash

# Call this script with at least 10 parameters, for example
# ./scriptname 1 2 3 4 5 6 7 8 9 10
MINPARAMS=10

echo

echo "The name of this script is \"$0\"."
# Adds ./ for current directory
echo "The name of this script is \"`basename $0`\"."
# Strips out path name info (see 'basename')

echo

if [ -n "$1" ]              # Tested variable is quoted.
then
 echo "Parameter #1 is $1"  # Need quotes to escape #
fi 

if [ -n "$2" ]
then
 echo "Parameter #2 is $2"
fi 

if [ -n "$3" ]
then
 echo "Parameter #3 is $3"
fi 

if [ -n "$4" ]
then
 echo "Parameter #4 is $4"
fi

if [ -n "$5" ]
then
 echo "Parameter #5 is $5"
fi 

if [ -n "$6" ]
then
 echo "Parameter #6 is $6"
fi 

if [ -n "$7" ]
then
 echo "Parameter #7 is $7"
fi 

if [ -n "$8" ]
then
 echo "Parameter #8 is $8"
fi 

if [ -n "$9" ]
then
 echo "Parameter #9 is $9"
fi 

if [ -n "${10}" ]  # Parameters > $9 must be enclosed in {brackets}.
then
 echo "Parameter #10 is ${10}"
fi 

echo "-----------------------------------"
echo "All the command-line parameters are: "$*""

if [ $# -lt "$MINPARAMS" ]
then
  echo
  echo "This script needs at least $MINPARAMS command-line arguments!"
fi  

echo

args=$#
echo $args
lastargs=${!args}
echo $lastargs

exit 0
