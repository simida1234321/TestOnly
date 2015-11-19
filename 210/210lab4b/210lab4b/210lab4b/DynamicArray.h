// Lab 4a, The "Write A Dynamic Array Class Template" Program
// Programmer: Licong Wang
// on 09/07/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef DynamicArray_h
#define DynamicArray_h

#include <vector>

template <class T>
class DynamicArray
{
  static const int INIT_CAP = 100;
  int cap;
  T* values;
  bool* inUse;
  T dummy;
  int sizeUsed = 0;

public:
  DynamicArray(int = INIT_CAP);
  ~DynamicArray();
  DynamicArray(const DynamicArray<T>&);
  DynamicArray<T>& operator=(const DynamicArray<T>&);
  T& operator[](int); // lookup key is an index 
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero 
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

template <class T>
DynamicArray<T>::DynamicArray(int init_cap)
{
  cap = init_cap;
  values = new T[cap];
  inUse = new bool[cap];

  for (int i = 0; i < cap; i++)
    inUse[i] = false;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
  delete[] values;
  delete[] inUse;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& a)
{
  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];
  sizeUsed = a.sizeUsed;

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
  if (this == &a) return *this;

  delete[] values;
  delete[] inUse;

  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];
  sizeUsed = a.sizeUsed;

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }

  return *this;
}

template <class T>
T& DynamicArray<T>::operator[](int key)
{
  if (key < 0)
    return dummy;
  else if (key >= cap)
  {
    T* tempValues = new T[key + 1];
    for (int i = 0; i < cap; i++) tempValues[i] = values[i];
    delete[] values;
    values = tempValues;

    bool* tempInUse = new bool[key + 1];
    for (int i = 0; i < cap; i++) tempInUse[i] = inUse[i];
    for (int i = cap; i <= key; i++) tempInUse[i] = false;
    delete[] inUse;
    inUse = tempInUse;

    cap = key + 1;
  }

  if (inUse[key] == false)
    sizeUsed += 1;

  inUse[key] = true;

  return values[key];
}

template <class T>
T DynamicArray<T>::operator[](int key) const
{
  if (key < 0 || key >= cap || inUse[key] == false)
    return dummy;

  return values[key];
}

template <class T>
int DynamicArray<T>::capacity() const
{
  return cap;
}

template <class T>
int DynamicArray<T>::size() const
{
  return sizeUsed;
}

template <class T>
bool DynamicArray<T>::containsKey(int key) const
{
  if (key < 0 || key >= cap)
    return false;
  else
    return inUse[key];
}

template <class T>
void DynamicArray<T>::deleteKey(int key)
{
  if (!(key < 0 || key >= cap))
  {
    if (inUse[key] == true)
      sizeUsed -= 1;

    inUse[key] = false;
  }
}

template <class T>
vector<int> DynamicArray<T>::keys() const
{
  vector<int> result;
  for (int i = 0; i < cap; i++)
  {
    if (inUse[i] == true)
      result.push_back(i);
  }

  return result;
}

template <class T>
void DynamicArray<T>::clear()
{
  for (int i = 0; i < cap; i++)
    inUse[i] = false;

  sizeUsed = 0;
}

#endif