CC=g++
CK=-c -std=c++11

Iter: driver.o VIteration.o
	$(CC) driver.o VIteration.o -o Iter

VIteration.o: VIteration.cpp VIteration.h
		$(CC)  VIteration.cpp $(CK)

driver.o: driver.cpp VIteration.h
	$(CC) driver.cpp $(CK)

run:
	./Iter data.txt output1.txt 6 0.8

clean:
	@rm -f *.o
	@rm Iter
