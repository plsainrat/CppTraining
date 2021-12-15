#ifndef __CLASS_CELL__
#define __CLASS_CELL__

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>



class CellPos{
    private:
    public:
        int x;
        int y;

        CellPos operator-(const CellPos& obj);
        CellPos operator+(const CellPos& obj);
        bool operator<(const CellPos& obj);
        bool operator>=(const CellPos& obj);
        bool operator==(const CellPos& obj);
        bool operator!=(const CellPos& obj);
        int CellDist(const CellPos& cellB) const;

        friend std::ostream& operator<<(std::ostream& os, const CellPos& cellPos);
};

bool isAlign(std::vector<CellPos> cellVect, CellPos cellA);

#endif//__CLASS_CELL__
