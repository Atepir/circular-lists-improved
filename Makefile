main: liste_circulaire.o
	gcc -o main liste_circulaire.o

liste_circulaire.o: liste_circulaire.c liste_circulaire.h sorte.h
	gcc -o liste_circulaire.o -c liste_circulaire.c

clean:
	rm -rf *.o main