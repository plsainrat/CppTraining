#include "board.h" 

using namespace std;

Board::Board(int x, int y):
sizeX(x), sizeY(y), lineLength(3){
    this->InitializeBoard();
}

Board::Board(int x, int y, int z):
sizeX(x), sizeY(y), lineLength(z){
    this->InitializeBoard();
}

Board::Board():
sizeX(3), sizeY(3), lineLength(3){
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
    if(cellPos.x < this->sizeX && cellPos.y < this->sizeY) {
        return *((this->boardArray)+(cellPos.x + cellPos.y*this->sizeX));
    }
    return '\0';
}

char Board::GetCellContent(int i, int j){
    if(i < sizeX && j < sizeY){
        return *((this->boardArray)+(i + j*this->sizeX));
    }
    return '\0';
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

int Board::FillCircle(CellPos cellPos){
    return FillCell(cellPos, 'O');
}

int Board::FillCross(CellPos cellPos){
    return FillCell(cellPos, 'X');
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

bool Board::CheckVictory(){
    int numLine = this->sizeX;
    int numCol = this->sizeY;
    
    int comboCpt = 0;
    char currSymb = '\0';
    //Check is victory horizontal
    for(int i = 0; i < numLine; i++){
        comboCpt = 0;
        char currSymb = '\0';
        for(int j = 0; j < numCol ; j++)
        {
           if(this->GetCellContent(i,j) == currSymb && this->GetCellContent(i,j)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(i,j);
            }
           if(comboCpt == (lineLength-1)){
               return true;
           }
        }
    }
    //Check is victory Vert
    for(int j = 0; j < numCol; j++){
        comboCpt = 0;
        char currSymb = '\0';
        for(int i = 0; i < numLine ; i++)
        {
           if(this->GetCellContent(i,j) == currSymb && this->GetCellContent(i,j)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(i,j);
            }
           if(comboCpt == (lineLength-1)){
               return true;
           }
        }
    }
    //Check Diagonal ligne+
    for(int i = 0; i < sizeX - (lineLength -1); i++){
        int ioffset = i;
        int joffset = 0;
        comboCpt = 0;
        char currSymb = '\0';
        while( ioffset <  sizeX){
           if(this->GetCellContent(ioffset,joffset) == currSymb && this->GetCellContent(ioffset,joffset)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(ioffset,joffset);
            }
           if(comboCpt == lineLength-1){
               return true;
           }
            ioffset++;
            joffset++;
        }
    }
//Check victory Diqgonal column+
    for(int j = 1; j < sizeX - (lineLength -1); j++){
        int ioffset = 0;
        int joffset = j;
        comboCpt = 0;
        char currSymb = '\0';
        while( joffset <  sizeX){
           if(this->GetCellContent(ioffset,joffset) == currSymb && this->GetCellContent(ioffset,joffset)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(ioffset,joffset);
            }
           if(comboCpt == lineLength-1){
               return true;
           }
            ioffset++;
            joffset++;
        }
    }
//Check Diagonal ligne-
    for(int i = sizeX-1; i >= (lineLength -1); i--){
        int ioffset = i;
        int joffset = 0;
        comboCpt = 0;
        char currSymb = '\0';
        while( ioffset >= 0){
           if(this->GetCellContent(ioffset,joffset) == currSymb && this->GetCellContent(ioffset,joffset)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(ioffset,joffset);
            }
           if(comboCpt == lineLength-1){
               return true;
           }
            ioffset--;
            joffset++;
        }
    }
//Check Diagonal column-
    for(int j = sizeY-1; j >= (lineLength -1); j--){
        int ioffset = 0;
        int joffset = j;
        comboCpt = 0;
        char currSymb = '\0';
        while( joffset < sizeY){
           if(this->GetCellContent(ioffset,joffset) == currSymb && this->GetCellContent(ioffset,joffset)!='?'){
               comboCpt ++;
            }else{
               comboCpt = 0;
               currSymb = GetCellContent(ioffset,joffset);
            }
           if(comboCpt == lineLength-1){
               return true;
           }
            ioffset--;
            joffset++;
        }
    }
    return false;
}




