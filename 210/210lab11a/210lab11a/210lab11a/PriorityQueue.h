// Lab 11a, The "Write A Dynamic Array Class Template" Program
// Programmer: Licong Wang
// on 11/02/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <algorithm>

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class T>
class PriorityQueue
{
  static const int INIT_CAP = 100;
  int cap;
  int siz = 0;
  T* values;
  T dummy;
  void doubleCap();

public:
  PriorityQueue(int = 2);
  ~PriorityQueue();
  PriorityQueue(const PriorityQueue<T>&);
  PriorityQueue<T>& operator=(const PriorityQueue<T>&);
  
  void enqueue(const T&);
  T& front();
  T& back();
  T dequeue();
  bool empty() const;
  void clear();
  int size() const;
};

template <class T>
void PriorityQueue<T>::doubleCap()
{
  int newCap = cap * 2;
  T* newValues = new T[newCap];
  for (int i = 0; i < cap; i++)
    newValues[i] = values[i];
  delete [] values;
  values = newValues;
  cap *= 2;
}

template <class T>
PriorityQueue<T>::PriorityQueue(int init_cap)
{
  cap = init_cap;
  values = new T[cap];
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
  delete[] values;
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& a)
{
  cap = a.cap;
  values = new T[cap];
  siz = a.siz;

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
  }
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& a)
{
  if (this == &a) return *this;

  delete[] values;

  cap = a.cap;
  values = new T[cap];
  siz = a.siz;

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
  }

  return *this;
}

template <class T>
void PriorityQueue<T>::enqueue(const T& a)
{
  int index = siz;
  if (index >= cap)
    doubleCap();
  values[index] = a;

  while (true)
  {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0)
      break;
    if (values[parentIndex] >= values[index])
      break;
    swap(values[parentIndex], values[index]);
    index = parentIndex;
  }
  siz++;
}

template <class T>
T& PriorityQueue<T>::front()
{
  if (siz == 0)
    return dummy;
  else
    return values[0];
}

template <class T>
T& PriorityQueue<T>::back()
{
  if (siz == 0)
    return dummy;
  else
    return values[siz - 1];
}

template <class T>
T PriorityQueue<T>::dequeue()
{
  int returned = values[0];
  int index = 0;
  while (true)
  {
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    if (leftIndex >= siz)
      break;
    if (leftIndex == siz - 1 || values[leftIndex] >= values[rightIndex])
    {
      values[index] = values[leftIndex];
      index = leftIndex;
    }
    else
    {
      values[index] = values[rightIndex];
      index = rightIndex;
    }
  }
  siz--;
  values[index] = values[siz];

  while (true)
  {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0)
      break;
    if (values[parentIndex] >= values[index])
      break;
    swap(values[parentIndex], values[index]);
    index = parentIndex;
  }

  return returned;
}

template <class T>
bool PriorityQueue<T>::empty() const
{
  return siz == 0;
}

template <class T>
int PriorityQueue<T>::size() const
{
  return siz;
}

template <class T>
void PriorityQueue<T>::clear()
{
  siz = 0;
}

#endif