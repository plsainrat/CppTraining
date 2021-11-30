#ifndef __CLASS_CELL__
#define __CLASS_CELL__

#include <iostream>
#include <string>
#include <array>
#include <vector>



class CellPos{
    private:
    public:
        int x;
        int y;
        CellPos operator-(const CellPos& obj);
        bool operator==(const CellPos& obj);
        bool isAlign(std::vector<CellPos> cellVect);
};
#endif//__CLASS_CELL__
