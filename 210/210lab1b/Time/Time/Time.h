// Lab 1b, The "Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Time_h
#define Time_h

class Time
{
public:
  void setHours(int);  // setters
  void setMinutes(int);
  void setSeconds(int);
  double timeInHours() const;  // getters
  double timeInMinutes() const;
  int timeInSeconds() const;

private:
  int Hours;
  int Minutes;
  int Seconds;
};

#endif