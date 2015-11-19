// Lab 2a, The "Writing Overloading Operators" Program
// Programmer: Licong Wang
// on 08/27/2015
// Editor(s) used: Visual Studio 2013
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
	return Hours + double(Minutes) / 60 + double(Seconds) / 3600;
}

double Time::timeInMinutes() const
{
	return Hours * 60 + Minutes + double(Seconds) / 60;
}

int Time::timeInSeconds() const
{
	return Hours * 3600 + Minutes * 60 + Seconds;
}

bool operator<(const Time& a, const Time& b)
{
  if (a.timeInSeconds() < b.timeInSeconds()) 
    return true;
  else 
    return false;
}

bool operator==(const Time& a, const Time& b)
{
  if (a.timeInSeconds() == b.timeInSeconds()) 
    return true;
  else 
    return false;
}