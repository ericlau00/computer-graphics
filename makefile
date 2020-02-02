all:
	gcc -o program picmaker.c
	./program

clean:
	rm program
	rm pic.*