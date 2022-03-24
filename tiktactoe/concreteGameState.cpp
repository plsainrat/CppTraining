#include "concreteGameState.h"

void GameState::exit(GameManager* gameManager)
{
   gameManager->getBoard()->DisplayBoard();
   std::cout<<"\n";
}

void Init::process(GameManager* gameManager)
{
    int boardSize;

    std::cout << "Welcome, Choose a Board size :";
    std::cin >> boardSize;
    //Test si bien un entier

    gameManager->InitBoard(boardSize);
    gameManager->setState(Player1Turn::getInstance());
}

GameState& Init::getInstance()
{
    static Init singleton;
    return singleton;
}

void Player1Turn::process(GameManager* gameManager)
{
    CellPos cellPos{};
    std::cout << "Player 1 turn, Choose a spot";
    std::cin >> cellPos.x;
    std::cin >> cellPos.y;

    if(gameManager->getBoard()->FillCross(cellPos)==CODE_SUCESS)
    {
        if(gameManager->getBoard()->CheckVictory()){
            gameManager->setState(Victory::getInstance());
        }
        else{
        gameManager->setState(Player2Turn::getInstance());
        }
    }
    else {
        std::cout << "Not an available spot";
        gameManager->setState(Player1Turn::getInstance());
    }
}

GameState& Player1Turn::getInstance()
{
    static Player1Turn singleton;
    return singleton;
}

void Player2Turn::process(GameManager* gameManager)
{
    CellPos cellPos{};
    std::cout << "Player 2 turn, Choose a spot";
    std::cin >> cellPos.x;
    std::cin >> cellPos.y;

    if(gameManager->getBoard()->FillCircle(cellPos)==CODE_SUCESS)
    {
        if(gameManager->getBoard()->CheckVictory()){
            gameManager->setState(Victory::getInstance());
        }else{
        gameManager->setState(Player1Turn::getInstance());
        }
    }
    else {
        std::cout << "Not an available spot";
        gameManager->setState(Player2Turn::getInstance());
    }
}

GameState& Player2Turn::getInstance()
{
    static Player2Turn singleton;
    return singleton;
}

void Victory::process(GameManager* gameManager)
{
    char res;
    std::cout<<"Victory, Want to play again ?" << std::endl;
    std::cin >> res;
    if(res=='y') gameManager->setState(Init::getInstance());
}

GameState& Victory::getInstance()
{
    static Victory singleton;
    return singleton;
}

void Victory::exit(GameManager* gameManager){
    std::cout << "\n\n\n\n\n\n\n\n\n";
}
