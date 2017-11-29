all:
	gcc -o shell util.c shell.c -g

run: all
	./shell < commands.txt > output
	./shell

clean:
	rm *.o
	rm *~
	clear
