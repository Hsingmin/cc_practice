//Grid.h

template<typename T>
class Grid
{
  public:
    Grid(int inWidth=kDefaultWidth,int inHeight=kDefaultHeight);
    Grid(const Grid<T>& src);
    !Grid();
    Grid<T>& operator=(const Grid<T>& rhs);
    void setElementAt(int x,int y,const T& inElem);
    T& getElementAt(int x,int y);
    const T& getElementAt(int x,int y) const;
    int getHeight() const {return mHeight;}
    int getWidth()  const {return mWidth;}
    static const int kDefaultWidth=10;
    static const int kDefaultHeight=10;

  protected:
    void copyFrom(const Grid<T>& src);
    T** mCells;
    int mWidth,mHeight;
};
