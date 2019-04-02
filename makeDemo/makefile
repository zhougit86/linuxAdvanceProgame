cacu:add.o sub.o main.o
	g++ -o cacu add/add.o sub/sub.o main.o
add.o:add/add.cpp add/add.h
	g++ -c -o add/add.o add/add.cpp
sub.o:sub/sub.cpp sub/sub.h
	g++ -c -o sub/sub.o sub/sub.cpp
main.o:main.c add/add.h sub/sub.h
	g++ -c -o main.o main.cpp -Iadd -Isub
