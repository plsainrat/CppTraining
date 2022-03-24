#include <iostream>
#include <algorithm>
#include <string>

#include "board.h"
#include "cell.h" 
#include "gameManager.h" 
#include "concreteGameState.h"


int main(int argc, char *argv[]){
    GameManager gamemanager;
    while(1){
        gamemanager.ProcessState();
    }
}
