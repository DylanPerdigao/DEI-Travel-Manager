programa: main.o lists.o menu.o readFiles.o
	gcc -o programa main.o lists.o menu.o readFiles.o

main.o:
	gcc -c main.c
lists.o:
	gcc -c lists.c
menu.o:
	gcc -c menu.c
readFiles.o:
	gcc -c readFiles.c


