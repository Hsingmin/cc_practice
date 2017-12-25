//�µ�ģ�廯���ƹ��캯�� 

template <typename T>
class Grid
{
  public:
    Grid(int inWidth=kDefaultWidth,int inHeight=kDefaultHeight);
    Grid(const Grid<T>& src);
    template <typename E>
    Grid(const Grid<E>& src);
    ~Grid();

    Grid<T>& operator=(const Grid<T>& rhs);
    template <typename E>
    Grid<T>& operator=(const Grid<E>& rhs);

    void setElementAt(int x,int y,const T& inElem);
    T& getElementAt(int x,int y);
    const T& getElementAt(int x,int y) const;

    int getHeight() const {return mHeight;}
    int getWidth() const {return mWidth;}

    static const int kDefaultWidth=10;
    static const int kDefaultHeight=10;

  protected:
    void copyFrom(const Grid<T>& src);
    template <typename E>
    void copyFrom(const Grid<E>& src);
  
    T** mCells;
    int mWidth,mHeight;
} ;


//ģ�廯copyFrom���� 
template <typename T>
template <typename E>
void Grid<T>::copyFrom(const Grid<E>& src)
{
  int i,j;
  mWidth=src.getWidth();
  mHeight=src.hetHeight();

  mCells=new T* [mWidth];
  for (i=0;i<mWidth;i++)
  {
    mCells[i]=new T[mHeight];
  }

  for (i=0;i<mWidth;i++)
  {
    for (j=0;j<mHeight;j++)
    {
      mCells[i][j]=src.getElementAt(i,j);
    }
  }
} 

//ȡһ��const Grid<E>& ,����һ��const Grid<T>& 
template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
  //Free the old memory.
  for(int i=0;i<mWidth;i++)
  {
    delete [] mCells[i];
  }
  delete [] mCells;
  //Copy the old memory.
  copyFrom(rhs);

  return (*this); 
}

//��ͬ����֮�临�ƺ͸�ֵ 
template <typename T,int WIDTH=10,int HEIGHT=10>
class Grid
{
  public:
    Grid() {}
    
    template <typename E,int WIDTH2,int HEIGHT2>
    Grid(const Grid<E,WIDTH2,HEIGHT2>& src);

    template <typename E,int EIDTH2,int HEIGHT2>
    Grid<T,WIDTH,HEIGHT>& operator=(const Grid<E,WIDTH2,HEIGHT2>& rhs);
    void setElementAt(int x,int y,const T& inElem);
    T& getElementAt(int x,int y);
    const T& getElementAt(int x,int y) const;
    int getHeight() const {return HEIGHT;}
    int getWidth() const {return WIDTH;}

  protected:
    template <typename E,int WIDTH2,int HEIGHT2>
    void copyFrom(const Grid<E,WIDTH2,HEIGHT2>& src);

    T mCells[WIDTH][HEIGHT];
};

//ģ�廯���ƹ��캯�� copyFrom()
template Grid<typename T,int WIDTH,int HEIGHT>
template Grid<typename E,int WIDTH2,int HEIGHT2>
Grid<T,WIDTH,HEIGHT>::Grid(const Grid<E,WIDTH2,HEIGHT2>& src)
{
  copyFrom(src);                                 
}

//���������Grid��char*���⻯���������Ȼ��ģ��
//ֻ�е��û�����char*���͵�Gridʱ���������� 
template <>
class Grid<char *>
