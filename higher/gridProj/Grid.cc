//Grid.cpp Grid类的方法定义 
//template <typename T>是限定符，用在所有方法的定义之前 

template <typename T>
Grid<T>::Grid(int inWidth,int inHeight) : mWidth(inWidth),mHeight(inHeight)
{
  mCells=new T* [mWidth];
  for(int i=0;i<mWidth;i++)
  {
    mCells[i]=new T[mHeight];
  }
}

//Grid类中静态成员的定义 
template <typename T>
const int Grid<T>::kDefaultWidth;

template <typename T>
const int Grid<T>::kDefaultHeight;
template <typename T>
Grid<T>::Grid(const Grid<T>& src)
{
  copyFrom(src);
}

template <typename T>
Grid<T>::~Grid()
{
  //Free the old memory.
  for(int i=0;i<mWidth;i++)
  {
    delete [] mCells[i];
  }
  delete [] mCells;
}

template <typename T>
void Grid<T>::copyFrom(const Grid<T>& src)
{
  int i,j;
  mWidth=src.mWidth;
  mHeight=src.mHeight;

  mCells=new T* [mWidth];
  for(i=0;i<mWidth;i++)
  {
    mCells[i]=new T[mHeight];
  }

  for(i=0;i<mWidth;i++)
  {
    for(j=0;j<mHeight;j++)
    {
      mCells[i][j]=src.mCells[i][j];
    }
  }
}

template <typename T>
Grid<T>& Grid<T>::operator=(const Grid<T>& rhs)
{
  //Check for self-assignment.
  if(this==&rhs)
  {
    return (*this);
  }
  for(int i=0;i<mWidth;i++)
  {
    delete [] mCells[i];
  }
  delete [] mCells;
  copyFrom(rhs);
  return (*this);
}

template <typename T>
void Grid<T>::setElementAt(int x,int y,const T& inElem)
{
  mCells[x][y]=inElem;
}

template<typename T>
T& Grid<T>::getElementAt(int x,int y)
{
  return (mCells[x][y]);
}

template <typename T>
const T& Grid<T>::getElementAt(int x,int y) const 
{
  return (mCells[x][y]);
}

//使用Grid模板 
void processIntGrid(Grid<int>& inGrid)
{
  //Body omitted for brevity.
}

Grid<SpreadsheetCell> mySpreadsheet;
SpreadsheetCell myCell;
mySpreadsheet.setElementAt(3,4,myCell);

Grid<char*> myStringGrid;
myStringGrid.setElementAt(2,2,"hello");

Grid<vector<int> >gridOfVectors;//We must leave a space in ">"and another ">"
vector<int> myVector;
gridOfVectors.setElementsAt(5,6,myVector);
Grid<int>* myGridp=new Grid<int>();
myGrid->setElementAt(0,0,10);
int x=myGridp->getElementAt(0,0);

delete myGridp;


