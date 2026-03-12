# Factorial Using Command Line Argument
#!/bin/bash

fact=1
n=$1

for ((i=1;i<=n;i++))
do
fact=$((fact * i))
done

echo "Factorial of $n = $fact"
