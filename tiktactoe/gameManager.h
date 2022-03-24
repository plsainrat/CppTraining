#ifndef __CLASS_GAME_MANAGER___
#define __CLASS_GAME_MANAGER___

#include "concreteGameState.h"
#include "board.h"

class GameState;
//interface abstraite, jamais besoin de l'implémenter

class GameManager{
    public:
        //TODO : Il va falloir gerer l' etat initiale
        GameManager();
        
        //TODO : Il fut faire une fonction qui va invoquer les fonction de transistion
        //de l'etat courant
        void setState(GameState& newState);
        void ProcessState();

        GameState* getCurrentGameState() const { return currGameState;}

        Board* getBoard() const { return board;}

        void InitBoard(int boardSize);
        void InitBoard();
        void FreeBoard();
        
    private:
        GameState* currGameState;
        Board* board;
};


#endif//__CLASS_GAME_MANAGER___
