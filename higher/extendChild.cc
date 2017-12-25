//
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
