#include "board.h" 

using namespace std;

Board::Board(int x, int y):
sizeX(x), sizeY(y){
    this->InitializeBoard();
}

Board::Board():
sizeX(3), sizeY(3){
    this->InitializeBoard();
}

Board::~Board(){
    free(this->boardArray);
}

void Board::InitializeBoard(){
    this->boardArray = (char*)calloc((this->sizeX * this->sizeY),sizeof(char));
    for(int i=0; i<this->sizeY; i++){
       for(int j=0; j<this->sizeX; j++){
            CellPos pos{j,i};
            this->FillCell(pos,'?');
       } 
    }
}

char Board::GetCellContent(CellPos cellPos){
    return *((this->boardArray)+(cellPos.x + cellPos.y*this->sizeX));
}

bool Board::IsCellAvailable(CellPos cellPos){
    return !(this->GetCellContent(cellPos) == 'X' || this->GetCellContent(cellPos) == 'O');
}

int Board::FillCell(CellPos cellPos, char charFill){
    if(IsCellAvailable(cellPos)){
        int arrayIt = cellPos.x + cellPos.y*this->sizeX;
        *((this->boardArray)+arrayIt)=charFill;
        return CODE_SUCESS;
    }
    else
    {
        return CODE_FAILURE;
    }
}

void Board::FillCircle(CellPos cellPos){
    FillCell(cellPos, 'O');
}

void Board::FillCross(CellPos cellPos){
    FillCell(cellPos, 'X');
}

void Board::FindNeighbour(CellPos cellPos, std::vector<CellPos>& cellVect){
    CellPos currCell = cellPos;
    CellPos nextCell;

   for(int i=-1; i<=1; i++){
       for(int j=-1; j<=1; j++){
           nextCell = currCell + CellPos{i,j}; 
           if(this->GetCellContent(currCell)==this->GetCellContent(nextCell) &&
              nextCell != currCell                                           &&
              nextCell.x >= 0 && nextCell.y >= 0)
           {
               cellVect.push_back(nextCell);
           }
       }
    } 
}

void  Board::FindLine(std::vector<CellPos> cellVect, int length){
}

int Board::CheckMatchStatus(void){
    //trouver une cellule avec un symbole a l'interieur
    //chercher les cellules voisines avec le meme symbole
    //regarder si la nouvelle cellules est alligné avec celle qu'on a trouvé
    //precedament
    //regarder si on a atteint la longueur de ligne voulu => retourner vrai
}

void Board::DisplayBoard(void){
    int numCol = this->sizeX;
    int numLin = this->sizeY;
    this->PrintLine();
    cout<<'\n';
    for(int i = 0;i<numLin; i++){
       for(int j = 0; j<numCol; j++){
        cout << '|' << *(this->boardArray+i+(j*numCol));
       }
       cout << '|';
       cout << '\n';
       this->PrintLine();
       cout << '\n';
    } 
}

void Board::PrintLine(){
    for(int i=0; i<this->sizeX; i++){
        cout << " -";
    }
}

void Board::PrintBoardInfo(){
    cout << this->sizeX << " " << this->sizeY << '\n';
}





