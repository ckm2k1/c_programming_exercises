rlec: rlec.o util.o
	gcc -g -o rlec rlec.o util.o

rlex: rlex.o util.o
	gcc -o rlex rlex.c util.o

rlec.o: rlec.c ../util.h
	gcc -g -c rlec.c

util.o: ../util.c ../util.h
	gcc -g -c ../util.c