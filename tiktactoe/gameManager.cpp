#include "gameManager.h" 


GameManager::GameManager()
{
        currGameState = &Init::getInstance();
}

void GameManager::ProcessState()
{
        currGameState->process(this);
}

void GameManager::setState(GameState& newState)
{
    currGameState->enter(this);
    this->currGameState = &newState;
    currGameState->exit(this);
}

void GameManager::InitBoard(int boardSize)
{
    board = new Board(boardSize,boardSize);
}

void GameManager::InitBoard()
{
    board = new Board;
}

void GameManager::FreeBoard()
{
    free(board);
}
