# Check Largest of Three Numbers
#!/bin/bash

if [ $1 -gt $2 ] && [ $1 -gt $3 ]
then
echo "$1 is largest"
elif [ $2 -gt $3 ]
then
echo "$2 is largest"
else
echo "$3 is largest"
fi
