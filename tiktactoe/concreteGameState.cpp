#include "concreteGameState.h"

void GameState::exit(GameManager* gameManager)
{
   gameManager->getBoard()->DisplayBoard();
}

void Init::process(GameManager* gameManager)
{
    //traiter le prochaine etat en fonction du contexte actuel ...
}

GameState& Init::getInstance()
{
    static Init singleton;
    return singleton;
}

void Player1Turn::process(GameManager* gameManager)
{
    //traiter le prochaine etat en fonction du contexte actuel ...
}

GameState& Player1Turn::getInstance()
{
    static Player1Turn singleton;
    return singleton;
}

void Player2Turn::process(GameManager* gameManager)
{
    //traiter le prochaine etat en fonction du contexte actuel ...
}

GameState& Player2Turn::getInstance()
{
    static Player2Turn singleton;
    return singleton;
}

void Victory::process(GameManager* gameManager)
{
    //traiter le prochaine etat en fonction du contexte actuel ...
}

GameState& Victory::getInstance()
{
    static Victory singleton;
    return singleton;
}
