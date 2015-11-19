// Lab 1a, The "Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#include "Road.h"

void Road::setWidth(double newWidth)
{
  Width = newWidth;
}

void Road::setLength(double newLength)
{
  Length = newLength;
}

double Road::getWidth() const
{
  return Width;
}

double Road::getLength() const
{
  return Length;
}

double Road::asphalt(double Thickness) const
{
  double result;
  result = Thickness * Width * Length * 5280 / 12;
  return result;
}