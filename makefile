all : evalSort.exe

evalSort.exe : utilSort.o advancedSort.o basicSort.o apo.o
	gcc *.o evalSort.c -o evalSort.exe

apo.o : apo.c
	gcc -c apo.c

utilSort.o : utilSort.c
	gcc -c utilSort.c

advancedSort.o : advancedSort.c
	gcc -c advancedSort.c

basicSort.o : basicSort.c
	gcc -c basicSort.c

clean : 
	rm -rf *.o *.exe
