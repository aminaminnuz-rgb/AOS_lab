# Display File Information
#!/bin/bash

if [ -f $1 ]
then
echo "File exists"
ls -l $1
else
echo "File does not exist"
fi

# run
./filecheck.sh test.txt
