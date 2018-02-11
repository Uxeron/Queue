all: Queue.o main.o
	gcc  main.o Queue.o -o prog.exe
Queue.o: Queue.c
	gcc  -c Queue.c -o Queue.o
main.o: main.c
	gcc  -c main.c -o main.o
clean:
	rm *.o 
