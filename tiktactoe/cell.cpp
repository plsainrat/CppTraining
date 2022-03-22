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

