//MilesEstimator.h
class MilesEstimator
{
  public:
    virtual int getMilesLeft() {
            return (getMilesPerGallon()*getGallonsLeft());
  }

  virtual void setGallonsLeft(int inValue) {mGallonsLeft=inValue;}
  virtual int getGallonsLeft() {return mGallonsLeft;}

  private:
    int mGallonsLeft;
    virtual int getMilesPerGallon() {return 20;}
};

MilesEstimator myMilesEstimator;

myMilesEstimator.setGallonsLeft(2);
cout<<"I can go "<<myMilesEstimator.getMilesLeft()<<" more miles. "<<endl;

class EfficientCarMilesEstimator : public MilesEstimator
{
  private:
    virtual int getMilesPerGallon() {return 35;}
};

EfficientCarMilesEstimator myEstimator;
myEstimator.setGallonsLeft(2);
cout<<"I can go "<<myEstimator.getMilesLeft()<<" more miles. "<<endl;


