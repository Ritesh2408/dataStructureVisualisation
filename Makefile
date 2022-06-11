final : main.o bst.o linkedlist.o doublelinkedlist.o
	gcc -o final main.o bst.o linkedlist.o doublelinkedlist.o -lGL -lGLU -lglut -lm

main.o : main.c
	gcc -c main.c

bst.o : bst.c
	gcc -c bst.c

linkedlist.o : linkedlist.c
	gcc -c linkedlist.c

doublelinkedlist.o : doublelinkedlist.c
	gcc -c doublelinkedlist.c
