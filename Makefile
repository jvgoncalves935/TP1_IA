fileH = headers/
fileC = cfiles/

objetos = Tad.o Arvore.o Main.o 

tp4:	$(objetos)
	gcc $(objetos) -o tp1

Main.o:	$(fileC)Main.c
	gcc -c -g -Wall -O3 $(fileC)Main.c

Arvore.o:	$(fileH)Arvore.h	$(fileC)Arvore.c
	gcc -c -g -Wall -O3 $(fileC)Arvore.c

Tad.o:	$(fileH)Tad.h	$(fileC)Tad.c
	gcc -c -g -Wall -O3 $(fileC)Tad.c

clean:
	rm -rf *.o
