#!/bin/sh


n=0
touch assi1a		#creates file
while [ $n -lt 5 ]
do
	echo "Enter name (4)"  #print message
	read name               #stores value
	echo $name >> assi1a    #inserts (> overwrite, >> appends)
	n=`expr $n + 1`
done
cat assi1a		#Displays file content
echo ""
echo "List of files inside currenr directory : `ls`"		#lists all files in directory
echo "Enter name to search :  "
read sname
grep -c "$sname" assi1a

echo "Do you want to delete assi1a file (1/0) ? "
read a
if [ $a -gt 0 ]
then
	unlink assi1a
	echo "File deleted successfully"
else
	echo "Bye"
fi

