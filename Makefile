runtree : main.o BST.o
	g++ -std=c++11 -o runtree main.o BST.o 

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

BST.o : BST.h BST.cpp
	g++ -std=c++11 -c BST.cpp
	
clean : 
	rm runtree main.o BST.o