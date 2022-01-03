#include <iostream>
#include <algorithm>
#include <string>

#include "board.h"
#include "cell.h" 

bool myFunction(CellPos a, CellPos b){ return a<b;}

int main(int argc, char *argv[]){
    Board board1{4,4};
    CellPos pos{0,0};
    std::vector<CellPos> cellVect;

    /*
    board1.FillCross(CellPos{0,0});
    board1.FillCross(CellPos{1,1});
    board1.FillCross(CellPos{2,2});
    board1.FillCross(CellPos{3,3});
    board1.DisplayBoard();
    */

    board1.FillCircle(CellPos{0,0});
    board1.FillCircle(CellPos{1,1});
    board1.FillCircle(CellPos{2,2});
    board1.FillCircle(CellPos{3,3});
    board1.DisplayBoard();
    std::cout << board1.CheckMatchStatus();

}
