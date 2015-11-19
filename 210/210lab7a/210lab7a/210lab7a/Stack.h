// Lab 7a, The "Write And Apply A Stack Template" Program
// Programmer: Licong Wang
// on 09/28/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Stack_h
#define Stack_h

template <class T>
class Stack
{
  struct Node
  {
    T value;
    Node* next;
  };

  Node* start;
  int siz;

public:
  Stack();
  bool empty() const { return 0 == siz; } // inline
  int size() const { return siz; } // inline
  void push(const T&);
  bool peek(T&) const;
  bool pop(T&);
  void clear();
  Stack(const Stack<T>&);
  Stack<T>& operator=(const Stack<T>&);
  ~Stack();
};

template <class T>
Stack<T>::Stack()
{
  start = 0; // empty list
  siz = 0;
}

template <class T>
void Stack<T>::push(const T& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = start;
  start = node;
  ++siz;
}

template <class T>
bool Stack<T>::peek(T& parameter) const
{
  if (0 == siz) return false; // failed
  parameter = start->value;
  return true; // success
}

template <class T>
bool Stack<T>::pop(T& parameter)
{
  if (0 == siz) return false; // failed
  parameter = start->value;
  Node* p = start->next;
  delete start;
  start = p;
  --siz;
  return true; // success
}
  
template <class T>
void Stack<T>::clear()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  siz = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& a)
{
  start = 0;
  Node* end = 0; // temporary end pointer
  siz = a.siz;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& a)
{
  if (this == &a) return *this;

  // deallocate existing queue
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }

  // build new queue
  Node* end = 0; // temporary end pointer
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;

  return *this;
}

template <class T>
Stack<T>::~Stack()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

#endif