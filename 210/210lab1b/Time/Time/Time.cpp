// Lab 1b, The "More Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include "Time.h"

void Time::setHours(int newHours)
{
  Hours = newHours;
}

void Time::setMinutes(int newMinutes)
{
  Minutes = newMinutes;
}

void Time::setSeconds(int newSeconds)
{
  Seconds = newSeconds;
}

double Time::timeInHours() const
{
  double result;
  result = double(Hours) + double(Minutes) / 60 + double(Seconds) / 3600;
  return result;
}

double Time::timeInMinutes() const
{
  double result;
  result = double(Hours) * 60 + double(Minutes) + double(Seconds) / 60;
  return result;
}

int Time::timeInSeconds() const  // using int since no devision is involved.
{
  int result;
  result = Hours * 3600 + Minutes * 60 + Seconds;
  return result;
}