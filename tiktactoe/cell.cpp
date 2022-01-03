#include "cell.h"

using namespace std;

CellPos CellPos::operator-(const CellPos& obj){
    return CellPos{x-obj.x, y-obj.y};
}

CellPos CellPos::operator+(const CellPos& obj){
    return CellPos{x+obj.x, y+obj.y};
}

bool CellPos::operator<(const CellPos& obj){
    if(y==obj.y){
           return x < obj.x;
        }
    else{
        return y < obj.y;
    }
}

bool CellPos::operator>(const CellPos& obj){
    if(y==obj.y){
           return x > obj.x;
        }
    else{
        return y > obj.y;
    }
}

bool CellPos::operator<=(const CellPos& obj){
    if(y==obj.y){
           return x <= obj.x;
        }
    else{
        return y <= obj.y;
    }
}

bool CellPos::operator>=(const CellPos& obj){
    if(y==obj.y){
           return x >= obj.x;
        }
    else{
        return y >= obj.y;
    }
}

bool CellPos::operator==(const CellPos& obj){
    return x==obj.x && y==obj.y;
}

bool CellPos::operator!=(const CellPos& obj){
    return x!=obj.x || y!=obj.y;
}

std::ostream& operator<<(std::ostream& os, const CellPos& cellPos){
    os << "[" << cellPos.x << "," << cellPos.y << "]";
    return os;
}

int CellPos::CellDist(const CellPos& cellB) const{
    return floor(sqrt(pow((x-cellB.x),2) + pow((y-cellB.y),2)));
}

bool isAlign(const std::vector<CellPos> cellVect, CellPos cellA){
    std::vector<CellPos> cellVectcpy{cellVect}; 
    cellVectcpy.push_back(cellA);
    CellPos direction, tmpDirection;

    std::sort(cellVectcpy.begin(), cellVectcpy.end());
    direction = *cellVectcpy.begin() - *(cellVectcpy.begin()+1);
    if(abs(direction.x) >=2 || abs(direction.y) >= 2) return false;
    for(std::vector<CellPos>::iterator it=(std::begin(cellVectcpy)+1) ; it!=std::end(cellVectcpy); ++it){
       tmpDirection = *(it-1) - *it; 
       if(tmpDirection != direction || abs(tmpDirection.x) >=2 || abs(tmpDirection.y) >= 2) return false;
       direction = tmpDirection;
    }
    return true;
}
