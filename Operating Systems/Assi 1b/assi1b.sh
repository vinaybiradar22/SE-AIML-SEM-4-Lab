#!/bin/sh

create()
{
	echo "Enter name of database."
	read dn
	res=`ls | grep $dn | wc -w` 
	if [ "$res" -gt "0" ]
	then
		echo "Database already exists."
	else
		touch $dn
		echo "Database created successfully."
	fi
		
}

display()
{
	echo `ls`
	echo "Enter name of database."
	read dn
	res=`ls | grep $dn | wc -w`
	if [ "$res" -gt "0" ] 
	then
		cat $dn
	else
		echo "Databse not found."
	fi
		
}

insert()
{
	echo "Enter name of database."
	read dn
	res=`ls | grep $dn | wc -w`
	if [ "$res" -gt "0" ]
	then
		echo "Enter Mobile No."
		read mob
		res1=`cat $dn | grep $mob | wc -w`
		if [ "$res1" -gt "0" ]
		then 
			echo "Phone No. already exists." 
		else
			echo "Enter first name, last name"
			read fname lname
			record=`echo $mob $fname $lname`
			echo $record >> $dn 
			echo "Record inserted successfully"
		fi
	
	else
		echo "Databse not found."
	fi
		
}

update()
{
	echo "Enter name of database."
	read dn
	res=`ls | grep $dn | wc -w`
	if [ "$res" -gt "0" ]
	then
		echo "Enter Mobile No."
		read mob
		res1=`cat $dn | grep $mob | wc -w`
		if [ "$res1" -gt "0" ]
		then 
			echo "Enter new details first name, last name, phone no."
			read fname lname mob
			newr=`echo $mob $fname $lname`
			oldr=`cat $dn | grep $mob`
			sed -i s/"$oldr"/"$newr"/g $dn
			echo "Record updated successfully"
		else
			echo "Phone no. not found."
		fi
	
	else
		echo "Databse not found."
	fi
		
}

delete()
{
	echo "Enter name of database."
	read dn
	res=`ls | grep $dn | wc -w`
	if [ "$res" -gt "0" ]
	then
		echo "Enter Mobile No."
		read mob
		res1=`cat $dn | grep $mob | wc -w`
		if [ "$res1" -gt "0" ]
		then 
			oldr=`cat $dn | grep $mob`
			sed -i s/"$oldr"//g $dn
			echo "Record deleted successfully"
		else
			echo "Phone no. not found."
		fi
	
	else
		echo "Databse not found."
	fi
		
}


while [ true ]
do
	echo "*********Menu********"
	echo "1) Create Database"
	echo "2) Display Database"
	echo "3) Insert a record"
	echo "4) Update a record"
	echo "5) Delete a record"
	echo "6) Exit"
	
	echo "Enter your choice : "
	read choice
	
	case $choice in 
		1) create;;
		2) display;;
		3) insert;;
		4) update;;
		5) delete;;
		6) exit;;
		*) echo "Enter  correct choice."
	esac
done
