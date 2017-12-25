//通用模板Grid.h

template<typename T> //T代表调用该模板的类指向的数据类型 
class Grid
{
  public:
    Grid(int inWidth=kDefaultWidth,int inHeight=kDefaultHeight);
    Grid(const Grid<T>& src);  //复制构造函数 
    !Grid();
    Grid<T>& operator=(const Grid<T>& rhs);
    void setElementAt(int x,int y,const T& inElem);
    T& getElementAt(int x,int y);  //T在这里代表用户指定的任意类型的占位符 
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
