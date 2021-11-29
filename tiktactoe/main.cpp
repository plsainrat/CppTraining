#include <iostream>
#include <string>

#include "board.h"



int main(int argc, char *argv[]){
    Board board1;
    Board board2{4,4};
    board1.PrintBoardInfo();
    board2.PrintBoardInfo();
    CellPos pos{2,2};
    board1.FillCell(pos,'x');
    board1.DisplayBoard();
    board2.DisplayBoard();
}
