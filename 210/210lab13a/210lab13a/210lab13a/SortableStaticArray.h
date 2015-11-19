// Lab 13a, The "Write A Sortable Array Class Template" Program
// Programmer: Licong Wang
// on 11/16/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef SortableStaticArray_h
#define SortableStaticArray_h

#include <vector>

template <class T, int CAPACITY>
class SortableStaticArray
{
  T values[CAPACITY];
  bool inUse[CAPACITY];
  T dummy;
  int sizeUsed = 0;

public:
  SortableStaticArray();
  T& operator[](int); // lookup key is an index 
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero 
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
  void sort();
};

template <class T, int CAPACITY>
SortableStaticArray<T, CAPACITY>::SortableStaticArray()
{
  for (int i = 0; i < CAPACITY; i++)
    inUse[i] = false;
}

template <class T, int CAPACITY>
T& SortableStaticArray<T, CAPACITY>::operator[](int key)
{
  if (key < 0 || key >= CAPACITY)
    return dummy;

  if (inUse[key] == false)
    sizeUsed += 1;

  inUse[key] = true;

  return values[key];
}

template <class T, int CAPACITY>
T SortableStaticArray<T, CAPACITY>::operator[](int key) const
{
  if (key < 0 || key >= CAPACITY || inUse[key] == false)
    return dummy;

  return values[key];
}

template <class T, int CAPACITY>
int SortableStaticArray<T, CAPACITY>::capacity() const
{
  return CAPACITY;
}

template <class T, int CAPACITY>
int SortableStaticArray<T, CAPACITY>::size() const
{
  return sizeUsed;
}

template <class T, int CAPACITY>
bool SortableStaticArray<T, CAPACITY>::containsKey(int key) const
{
  if (key < 0 || key >= CAPACITY)
    return false;
  else
    return inUse[key];
}

template <class T, int CAPACITY>
void SortableStaticArray<T, CAPACITY>::deleteKey(int key)
{
  if (!(key < 0 || key >= CAPACITY))
  {
    if (inUse[key] == true)
      sizeUsed -= 1;

    inUse[key] = false;
  }
}

template <class T, int CAPACITY>
vector<int> SortableStaticArray<T, CAPACITY>::keys() const
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
void SortableStaticArray<T, CAPACITY>::clear()
{
  for (int i = 0; i < CAPACITY; i++)
    inUse[i] = false;

  sizeUsed = 0;
}

template <class T, int CAPACITY>
void SortableStaticArray<T, CAPACITY>::sort()
{
  int counter1, counter2;

  for (int i = 1; i < CAPACITY; i++)
  {
    if (!inUse[i]) continue;

    counter1 = i - 1;
    while (!inUse[counter1] && counter1 >= 0)
      counter1--;

    cout << "i: " << i << " " << "counter1: " << counter1 << endl;
    if (counter1 == -1) continue;

    if (values[i] < values[counter1])
    {
      T temp = values[i];
      int j = i;
      counter2 = counter1 - 1;

      while (!inUse[counter2] && counter2 >= 0)
        counter2--;

      cout << "i: " << i << " " << "counter2: " << counter2 << endl;
      if (counter2 == -1) break;

      //cout << "i: " << i << " "<< "counter2: " << counter2 << endl;
      do
      {
        while (!inUse[counter2] && counter2 >= 0)
          counter2--;

        if (counter2 == -1) break;

        values[j] = values[counter2];
      
        j = counter2;
        counter2 = j - 1;

      } while (j > 0 && temp < values[counter2]);

      values[j] = temp;
    } // if
  }
}



#endif  