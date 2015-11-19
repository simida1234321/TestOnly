// Lab 3a, The "Write A Static Array Class Template" Program
// Programmer: Licong Wang
// on 09/04/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef StaticArray_h
#define StaticArray_h

#include <vector>

template <class T, int CAPACITY>
class StaticArray
{
  T values[CAPACITY];
  bool inUse[CAPACITY];
  T dummy;
  int sizeUsed = 0;

public:
  StaticArray();
  T& operator[](int); // lookup key is an index 
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero 
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

template <class T, int CAPACITY>
StaticArray<T, CAPACITY>::StaticArray()
{
  for (int i = 0; i < CAPACITY; i++)
    inUse[i] = false;
}

template <class T, int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](int key)
{
  if (key < 0 || key >= CAPACITY)
    return dummy;

  if (inUse[key] == false)
    sizeUsed += 1;

  inUse[key] = true;

  return values[key];
}

template <class T, int CAPACITY>
T StaticArray<T, CAPACITY>::operator[](int key) const
{
  if (key < 0 || key >= CAPACITY || inUse[key] == false)
    return dummy;

  return values[key];
}

template <class T, int CAPACITY>
int StaticArray<T, CAPACITY>::capacity() const
{
  return CAPACITY;
}

template <class T, int CAPACITY>
int StaticArray<T, CAPACITY>::size() const
{
  return sizeUsed;
}

template <class T, int CAPACITY>
bool StaticArray<T, CAPACITY>::containsKey(int key) const
{
  if (key < 0 || key >= CAPACITY)
    return false;
  else
    return inUse[key];
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::deleteKey(int key)
{
  if (!(key < 0 || key >= CAPACITY))
  {
    if (inUse[key] == true)
      sizeUsed -= 1;

    inUse[key] = false;
  }
}

template <class T, int CAPACITY>
vector<int> StaticArray<T, CAPACITY>::keys() const
{
  vector<int> result;
  for (int i = 0; i < CAPACITY; i++)
  {
    if (inUse[i] == true)
      result.push_back(i);
  }

  return result;
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::clear()
{
  for (int i = 0; i < CAPACITY; i++)
    inUse[i] = false;

  sizeUsed = 0;
}

#endif  