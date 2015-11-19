// Lab 7b, The "Write And Test A Queue Template" Program
// Programmer: Licong Wang
// on 10/02/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Queue_h
#define Queue_h

template <class T>
class Queue
{
  struct Node
  {
    T value;
    Node* next;
  };

  Node* start;
  Node* end; // for efficiency 
  int siz; // track size

public:
  Queue();
  bool empty() const { return 0 == start; } // inline
  int size() const { return siz; } // inline
  void push(const T&);
  bool peek(T&) const;
  bool pop(T&);
  void clear();
  Queue(const Queue<T>&);
  Queue<T>& operator=(const Queue<T>&);
    ~Queue();
};

template <class T>
Queue<T>::Queue()
{
  start = 0;
  end = 0;
  siz = 0;
}

template <class T>
void Queue<T>::push(const T& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  ++siz;
}

template <class T>
bool Queue<T>::peek(T& parameter) const
{
  if (0 == start) return false; // failed
  parameter = start->value;
  return true; // success
}

template <class T>
bool Queue<T>::pop(T& parameter)
{
  if (0 == start) return false; // failed
  parameter = start->value;
  Node* p = start->next;
  delete start;
  start = p;
  if (start == 0) end = 0;
  --siz;
  return true; // success
}

template <class T>
void Queue<T>::clear()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
  siz = 0;
}

template <class T>
Queue<T>::Queue(const Queue<T>& a)
{
  start = 0;
  end = 0;
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
Queue<T>& Queue<T>::operator=(const Queue<T>& a)
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
  end = 0; // data member end pointer
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
Queue<T>::~Queue()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

#endif

