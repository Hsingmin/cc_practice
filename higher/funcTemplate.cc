//Gameboard.h
#include"Grid.h"

template <typename T>
class Gameboard : public Grid<T>
{
  public:
    Gameboard(int inWidth=Grid<T>::kDefaultWidth,int inHeight=Grid<T>::kDefaultHeight);
    void move(int xSrc,int ySrc,int xDest,int yDest);
} ;

template <typename T>
Gameboard<T>::Gameboard(int inWidth,int inHeight):Grid<T>(inWidth,inHeight)
{
}

template <typename T>
void Gameboard<T>::move(int xSrc,int ySrc,int xDest,int yDest)
{
  this->mCells[xDest][yDest]=this->mCells[xSrc][ySrc];
  this->mCells[xSrc][ySrc]=T();//zero-initialize the source cell.
}

Gameboard<ChessPiece> chessBoard;
ChessPiece pawn;
chessBoard.setElementAt(0,0,pawn);
chessBoard.move(0,0,0,1);
