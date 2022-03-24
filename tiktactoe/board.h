#ifndef __CLASS_BOARD__
#define __CLASS_BOARD__

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>

#include "cell.h" 

#define CODE_FAILURE 0
#define CODE_SUCESS 1

#define GAME_STATUS_IN_PROGRESS 0 
#define GAME_STATUS_VICTORY 1
#define GAME_STATUS_DRAW 2


//template <int ARRAY_LEN> 
class Board{
    private:
        int sizeX;
        int sizeY;
        //array<char, ARRAY_LEN> boardArray; 
        char* boardArray;
        int lineLength;
        Board& operator=(const Board& other);

    public:
        //Constructors Destructor
       Board(int x, int y); 
       Board(int x, int y, int z); 
       Board();
       ~Board();
       //Cells manipulation || a voir si on fait pas des fonction dans la class
       //Cell pour ajouter encore une couche de protection
       char GetCellContent(CellPos cellPos);
       char GetCellContent(int x, int y);
       int FillCell(CellPos cellPos, char charFill);
       int FillCross(CellPos cellPos);
       int FillCircle(CellPos cellPos);
       bool IsCellAvailable(CellPos cellPos);
       //Functions to manipulate the board
       void InitializeBoard();
       //Print functions, display the owl board, or just the infos
       void DisplayBoard(void);
       void PrintLine(void);
       void PrintBoardInfo(void);
       bool CheckVictory();
};

#endif /* __CLASS_BOARD__ */
