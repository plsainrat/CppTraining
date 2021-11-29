#ifndef __CLASS_BOARD__
#define __CLASS_BOARD__

#include <iostream>
#include <string>
#include <array>

#define CODE_FAILURE 0
#define CODE_SUCESS 1

#define GAME_STATUS_IN_PROGRESS 0 
#define GAME_STATUS_VICTORY 1
#define GAME_STATUS_DRAW 2

struct CellPos{
    int x;
    int y;
};

//template <int ARRAY_LEN> 
class Board{
    private:
        int sizeX;
        int sizeY;
        //array<char, ARRAY_LEN> boardArray; 
        char* boardArray;
    public:
        //Constructors Destructor
       Board(int x, int y); 
       Board();
       ~Board();
       //Functions to manipulate the board
       char GetCellContent(CellPos cellPos);
       int FillCell(CellPos cellPos, char charFill);
       void FillCross(CellPos cellPos);
       void FillCircle(CellPos cellPos);
       bool IsCellAvailable(CellPos cellPos);
       void InitializeBoard();
       //Game status related functions
       int CheckMatchStatus(void);
       //Print functions, display the owl board, or just the infos
       void DisplayBoard(void);
       void PrintLine(void);
       void PrintBoardInfo(void);
};

#endif /* __CLASS_BOARD__ */
