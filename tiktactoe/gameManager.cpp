#include "gameManager.h" 


GameManager::GameManager()
{
        currGameState = &Init::getInstance();
}

void GameManager::setState(GameState& newState)
{
    currGameState->enter(this);
    this->currGameState = &newState;
    currGameState->exit(this);
}
