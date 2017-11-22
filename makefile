all: shell.o
	gcc -o shell shell.o

run: all
	./shell

clean:
	rm *.o
rm *~
