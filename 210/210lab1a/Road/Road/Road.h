// Lab 1a, The "Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Road_h
#define Road_h

class Road
{
public:
  void setWidth(double);  // setters
  void setLength(double);
  double getWidth() const; // getters
  double getLength() const;
  double asphalt(double) const;

private:
  double Width;
  double Length;
};

#endif