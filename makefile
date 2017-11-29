all:
	gcc -o shell util.c shell.c -g

run: all
	./shell

clean:
	rm *.o
	rm *~
	clear
