// Lab 2a, The "Writing Overloading Operators" Program
// Programmer: Licong Wang
// on 08/27/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#include "Time.h"

void Time::setHours(int newHours)
{
  hours = newHours;
}

void Time::setMinutes(int newMinutes)
{
  minutes = newMinutes;
}

void Time::setSeconds(int newSeconds)
{
  seconds = newSeconds;
}

double Time::timeInHours() const
{
  return hours + double(minutes) / 60 + double(seconds) / 3600;
}

double Time::timeInMinutes() const
{
  return hours * 60 + minutes + double(seconds) / 60;
}

int Time::timeInSeconds() const
{
  return hours * 3600 + minutes * 60 + seconds;
}

bool Time::operator<(const Time& b) const
{
  if (timeInSeconds() < b.timeInSeconds())
    return true;
  else
    return false;
}

bool Time::operator==(const Time& b) const
{
  if (seconds + minutes * 60 + hours * 3600 == b.seconds + b.minutes * 60 + b.hours * 3600)
    return true;
  else
    return false;
}