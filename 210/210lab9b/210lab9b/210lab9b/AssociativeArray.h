// Lab 9a, The "Write A Linked Array Class Template" Program
// Programmer: Licong Wang
// on 10/12/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <vector>
using namespace std;

template <class T, class U>
class AssociativeArray
{
  struct Node
  {
    T value;
    U key;
    bool inUse;
    Node* next;
  };

  Node* start;
  Node* end;
  int cap;
  int siz;
  static const int INIT_CAP = 0;
  T dummy;

public:
  AssociativeArray(int = INIT_CAP);
  ~AssociativeArray();
  AssociativeArray(const AssociativeArray<T, U>&);
  AssociativeArray<T, U>& operator=(const AssociativeArray<T, U>&);
  T& operator[](const U&); // lookup key is an index 
  T operator[](const U&) const;
  int size() const; // #of keys "in use", initially zero 
  int capacity() const;
  bool containsKey(const U&) const;
  void deleteKey(const U&); // set "in use" to false 
  vector<U> keys() const; // all "in use" keys 
  void clear();
};

// constructor
template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(int init_cap)
{
  start = end = NULL;
  cap = init_cap;
  siz = 0;

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
template <class T, class U>
AssociativeArray<T, U>::~AssociativeArray()
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
template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(const AssociativeArray<T, U>& a)
{
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
    node->key = p->key;
  }
}

// operator =
template <class T, class U>
AssociativeArray<T, U>& AssociativeArray<T, U>::operator=(const AssociativeArray<T, U>& a)
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
    node->key = p->key;
  }

  return *this;
}

// setter
template <class T, class U>
T& AssociativeArray<T, U>::operator[](const U& parameter)
{
  Node* p = start;
  for (; p; p = p->next)
  {
    if (p->inUse == true && p->key == parameter)
    {
      return p->value;
    }
  }

  p = start;
  for (; p; p = p->next)
  {
    if (p->inUse == false)
    {
      p->key = parameter;
      p->inUse = true;
      siz++;
      return p->value;
    }
  }

  Node* node = new Node;
  node->inUse = false;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;

  end->key = parameter;
  end->inUse = true;
  siz++;
  cap++;
  return end->value;
}

//getter
template <class T, class U>
T AssociativeArray<T, U>::operator[](const U& parameter) const
{
  const Node* p = start;

  for (; p; p = p->next)
    if (p->inUse == true && p->key == parameter)
      return p->value;

  return dummy;
}

template <class T, class U>
int AssociativeArray<T, U>::capacity() const
{
  return cap;
}

template <class T, class U>
int AssociativeArray<T, U>::size() const
{
  return siz;
}

template <class T, class U>
bool AssociativeArray<T, U>::containsKey(const U& parameter) const
{
  const Node* p = start;

  for (; p; p = p->next)
    if (p->key == parameter) break;

  if (!p)
    return false;

  return p->inUse;
}

template <class T, class U>
void AssociativeArray<T, U>::deleteKey(const U& parameter)
{
  Node* p = start;

  for (; p; p = p->next)
    if (p->key == parameter) break;

  if (p->inUse == true)
  {
    siz--;
    p->inUse = false;
  }
}

template <class T, class U>
vector<U> AssociativeArray<T, U>::keys() const
{
  vector<U> result;
  const Node* p = start;

  for (; p; p = p->next)
  {
    if (p->inUse == true)
      result.push_back(p->key);
  }

  return result;
}

template <class T, class U>
void AssociativeArray<T, U>::clear()
{
  for (Node* p = start; p; p = p->next)
    p->inUse = false;

  siz = 0;
  cap = 0;
}

#endif