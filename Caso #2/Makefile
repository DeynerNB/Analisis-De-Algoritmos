all: free insert quick clean

free: free.o
	g++ freeText.o -o FreeText

free.o:
	g++ -c freeText.cpp


insert: insert.o
	g++ insertionSort.o -o InsertionSort

insert.o:
	g++ -c insertionSort.cpp


quick: quick.o
	g++ quickSort.o -o QuickSort

quick.o:
	g++ -c quickSort.cpp


clean:
	rm *.o