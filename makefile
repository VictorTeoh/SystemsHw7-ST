all: rand.o main.o
	gcc -o runo rand.o main.o

main.o: main.c
	gcc -c main.c

rand.o: rand.c
	gcc -c rand.c

run: all
	./runo

clean:
	rm -rf *.o *~ runo debugo numbers

debug: rand.c main.c
	gcc -o debugo -g rand.c main.c

valgrind: debug
	valgrind --leak-check=yes ./debugo

gdb: debug
	gdb ./debugo
