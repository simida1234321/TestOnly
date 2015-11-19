// Lab 6a, The "Write A Linked Array Class Template" Program
// Programmer: Licong Wang
// on 09/23/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef LinkedArray_h
#define LinkedArray_h

#include <vector>
using namespace std;

template <class T>
class LinkedArray
{
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };

  Node* start;
  Node* end;
  mutable Node* lastP;
  mutable int lastCount;
  int cap;
  int siz;
  static const int INIT_CAP = 0;
  T dummy;

public:
  LinkedArray(int = INIT_CAP);
  ~LinkedArray();
  LinkedArray(const LinkedArray<T>&);
  LinkedArray<T>& operator=(const LinkedArray<T>&);
  T& operator[](int); // lookup key is an index 
  T operator[](int) const;
  int size() const; // #of keys "in use", initially zero 
  int capacity() const;
  bool containsKey(int) const;
  void deleteKey(int); // set "in use" to false 
  vector<int> keys() const; // all "in use" keys 
  void clear();
};

// constructor
template <class T>
LinkedArray<T>::LinkedArray(int init_cap)
{
  start = end = NULL;
  cap = init_cap;
  siz = 0;
  lastP = NULL;
  lastCount = -1;

  for (int i = 0; i < cap; i++)
  {
    Node* node = new Node;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    node->inUse = false;
  }
}

// destructor
template <class T>
LinkedArray<T>::~LinkedArray()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
}

// copy constructor
template <class T>
LinkedArray<T>::LinkedArray(const LinkedArray<T>& a)
{
  cap = a.cap;
  siz = a.siz;
  lastP = NULL;
  lastCount = -1;

  const Node* p = a.start;

  for (; p; p = p->next)
  {
    Node* node = new Node;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    node->value = p->value;
    node->inUse = p->inUse;
  }
}

// operator =
template <class T>
LinkedArray<T>& LinkedArray<T>::operator=(const LinkedArray<T>& a)
{
  if (this == &a) return *this;

  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;

  cap = a.cap;
  siz = a.siz;

  const Node* p = a.start;

  for (; p; p = p->next)
  {
    Node* node = new Node;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    node->value = p->value;
    node->inUse = p->inUse;
  }

  return *this;
}

// setter
template <class T>
T& LinkedArray<T>::operator[](int key)
{
  if (key < 0)
    return dummy;
  else if (key >= cap)
  {
    int n = key + 1 - cap;
    cap = key + 1;
    for (int i = 0; i < n; i++)
    {
      Node* node = new Node;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      node->inUse = false;
    }
  }

  Node* p = start;
  int count = 0;

  if (lastCount != -1 && lastCount <= key)
  {
    p = lastP;
    count = lastCount;
  }

  for (; p; p = p->next, count++)
    if (count == key) break;

  if (p->inUse == false)
  {
    siz += 1;
    p->inUse = true;
  }

  lastP = p;
  lastCount = key;

  return p->value;
}

//getter
template <class T>
T LinkedArray<T>::operator[](int key) const
{
  if (key < 0 || key >= cap)
    return dummy;

  const Node* p = start;
  int count = 0;

  if (lastCount != -1 && lastCount <= key)
  {
    p = lastP;
    count = lastCount;
  }

  for (; p; p = p->next, count++)
    if (count == key) break;

  if (p->inUse == false)
    return dummy;

  lastP = (Node*)p;
  lastCount = key;

  return p->value;
}

template <class T>
int LinkedArray<T>::capacity() const
{
  return cap;
}

template <class T>
int LinkedArray<T>::size() const
{
  return siz;
}

template <class T>
bool LinkedArray<T>::containsKey(int key) const
{
  if (key < 0 || key >= cap)
    return false;

  const Node* p = start;
  int count = 0;

  for (; p; p = p->next, count++)
    if (count == key) break;

  return p->inUse;
}

template <class T>
void LinkedArray<T>::deleteKey(int key)
{
  if (!(key < 0 || key >= cap))
  {
    Node* p = start;
    int count = 0;

    if (lastCount != -1 && lastCount <= key)
    {
      p = lastP;
      count = lastCount;
    }

    for (; p; p = p->next, count++)
      if (count == key) break;

    if (p->inUse == true)
    {
      siz -= 1;
      p->inUse = false;
    }
  }
}

template <class T>
vector<int> LinkedArray<T>::keys() const
{
  vector<int> result;
  Node* p = start;
  int count = 0;

  for (; p; p = p->next, count++)
  {
    if (p->inUse == true)
      result.push_back(count);
  }

  return result;
}

template <class T>
void LinkedArray<T>::clear()
{
  for (Node* p = start; p; p = p->next)
    p->inUse = false;

  siz = 0;
}

#endif