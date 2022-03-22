#ifndef __CLASS__GAMESTATE__
#define __CLASS__GAMESTATE__

#include "gameManager.h"

//interface abstraite, jamais besoin de l'implémenter
class GameState{
    public:
    virtual void enter(GameManager* gamemanager) = 0;
    virtual void process(GameManager* gamemanager) = 0;
    virtual void exit(GameManager* gamemanager) = 0;
    virtual ~GameState(){};
};

#endif//__CLASS__GAMESTATE__
