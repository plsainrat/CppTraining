#include <iostream>
#include <algorithm>
#include <string>

#include "board.h"
#include "cell.h" 

bool myFunction(CellPos a, CellPos b){ return a<b;}

int main(int argc, char *argv[]){
    Board board1{3,3};
    CellPos pos{0,0};
    std::vector<CellPos> cellVect;
    board1.FillCross(CellPos{0,0});
    board1.FillCross(CellPos{1,1});
    board1.FillCross(CellPos{2,1});
    board1.DisplayBoard();
    board1.FindNeighbour(pos,cellVect);
    for(std::vector<CellPos>::iterator it=cellVect.begin(); it!=cellVect.end(); it++){
        std::cout << *it;
    }
}
