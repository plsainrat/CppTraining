
CC = g++
CFLAGS = -g -Wall

main: main.o board.o cell.o gameManager.o concreteGameState.o
	$(CC) $(CFLAGS) -o main main.o board.o cell.o gameManager.o concreteGameState.o

main.o: main.cpp board.h cell.h gameManager.h concreteGameState.h 
	$(CC) $(CFLAGS) -c main.cpp

	
concreteGameState.o: concreteGameState.h  gameManager.h

board.o: board.h cell.h

cell.o: cell.h

gameManager.o: gameManager.h board.h concreteGameState.h  

clean:
	rm -f prog *.o 
