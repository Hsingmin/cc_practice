//MyWeatherPrediction.h

class MyWeatherPrediction : public WeatherPrediction
{
  public:
    virtual void setCurrentTempCelsius(int inTemp);
    virtual int getTomorrowTempCelsius();
    virtual void showResult();
  
  protected:
    static int convertCelsiusToFahrenheit(int inCelsius);
    static int convertFahrenheitToCelsius(int inFahrenheit);
};

//User adding.
void MyWeatherPrediction::showResult()
{
  cout<<"Tomorrow's temperature will be "<<
         getTomorrowTempCelsius()<<" degree Celsius ("<<
         getTomorrowTemFahrenheit()<<" degree Fahrenheit)"<<endl;
  cout<<"The chance of rain is "<<(getChanceOfRain()*100)<<"percent"
      <<endl;

  if(getChanceOfRain()>0.5)
  {
    cout<<"Bring an umbrella! "<<endl;
  }
}




















