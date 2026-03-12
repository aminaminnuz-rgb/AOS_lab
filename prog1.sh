# Program: Display Command Line Arguments
#!/bin/bash

echo "Script Name: $0"
echo "Number of Arguments: $#"
echo "Arguments are:"

for arg in "$@"
do
echo $arg
done
