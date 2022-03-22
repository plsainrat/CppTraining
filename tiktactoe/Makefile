
CC = g++
CFLAGS = -g -Wall

main: main.o board.o cell.o gameManager.o concreteGameState.o
	$(CC) $(CFLAGS) -o main main.o board.o cell.o gameManager.o

main.o: main.cpp board.h cell.h gameManager.h concreteGameState.h gameState.h
	$(CC) $(CFLAGS) -c main.cpp

gameManager.o: gameManager.h board.h gameState.h concreteGameState.h
	
concreteGameState.o: concreteGameState.h gameState.h 

board.o: board.h cell.h

cell.o: cell.h


