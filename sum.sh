# Sum of All Arguments
#!/bin/bash

sum=0

for num in "$@"
do
sum=$(($sum + $num))
done

echo "Total Sum = $sum"

# run
./sum.sh 10 20 30

# output
Total Sum = 60
