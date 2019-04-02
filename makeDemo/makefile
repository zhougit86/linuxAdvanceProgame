CC = g++
OBJS = add/add.o sub/sub.o main.o
CFLAGS = -Iadd -Isub -O2

cacu: $(OBJS)
	$(CC) -o cacu $^ $(CFLAGS)
# add.o:add/add.cpp add/add.h
# 	$(CC) -c -o add/add.o add/add.cpp
# sub.o:sub/sub.cpp sub/sub.h
# 	$(CC) -c -o sub/sub.o sub/sub.cpp
# main.o:main.cpp add/add.h sub/sub.h
# 	$(CC) -c -o main.o main.cpp -Iadd -Isub
$(OBJS): %.o:%.cpp
	$(CC) $< -c $(CFLAGS) -o $@

clean: 
	rm -rf add/add.o sub/sub.o main.o cacu