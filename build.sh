#!/bin/bash

appRunning=1

while [ $appRunning == 1 ]; do
	echo Compile and run[1], Compile[2], Exit[3]
	read user

	if [[ $user == 1 ]]; then
		echo Compiling and then running
		g++ -c src/*.cpp -std=c++14 -Werror
		g++ *.o -o bin/Creche -l sqlite3
		./bin/Creche
	elif [[ $user == 2 ]]; then
		echo Compiling...
		g++ -c src/*.cpp -std=c++14 -Werror
		g++ *.o -o bin/Creche -l sqlite3
	elif [[ $user == 3 ]]; then
		exit
	fi
done