// Lab 2b, The "Writing Templates And Overloading Operators" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Road_h
#define Road_h

template <class T>
class Road
{
  T width;
  T length;

public:
  void setWidth(T newWidth) { width = newWidth; }
  void setLength(T newLength) { length = newLength; }
  T getWidth() const { return width; }
  T getLength() const { return length; }
  T asphalt(T) const;
};

template <class T>
T Road<T>::asphalt(T thickness) const
{
  T result;

  result = thickness * width * length * 5280 / 12;
  return result; //in feet
}


template <class T>
bool operator<(const T& a, const T& b)
{
  if (a.getLength() < b.getLength()) 
    return true;
  else 
    return false;
}

template <class T>

bool operator==(const T& a, const T& b)
{
  if (a.getLength() == b.getLength() && a.getWidth() == b.getWidth()) 
    return true;
  else 
    return false;
}

#endif