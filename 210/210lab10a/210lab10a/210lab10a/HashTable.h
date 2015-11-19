// Lab 10a, The "Write, Test, and Apply The HashTable Class Template" Program
// Programmer: Licong Wang
// on 10/28/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#ifndef HashTable_h
#define HashTable_h

#include <vector>
#include <list>
#include <algorithm>
using namespace std;

template <class T, class U, int CAPACITY>
class HashTable
{
  struct Node
  {
    T value;
    U key;
    void operator=(const T& v){ value = v; }
    bool operator==(const Node& n) const { return key == n.key; }
  };

  list<Node> data[CAPACITY];
  int(*hashCode)(const U&);
  int getWrappedIndex(const U&) const;
  int siz;
  T dummy;

public:
  HashTable(int(*)(const U&));
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
template <class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::HashTable(int(*x)(const U&))
{
  siz = 0;
  hashCode = x;
}

template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::getWrappedIndex(const U& key) const
{
  int wi = hashCode(key) % CAPACITY;
  if (wi < 0) wi += CAPACITY;
  return wi;
}

// setter 
template <class T, class U, int CAPACITY>
T& HashTable<T, U, CAPACITY>::operator[](const U& key)
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end()) // no matching key 
  {
    siz++;
    data[wi].push_back(temp);
    return data[wi].back().value;
  }
  else
    return it->value;
}

//getter
template <class T, class U, int CAPACITY>
T HashTable<T, U, CAPACITY>::operator[](const U& key) const
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end()) // no matching key 
    return dummy;
  else
    return it->value;
}

template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::capacity() const
{
  return 0.8 * CAPACITY;
}

template <class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::size() const
{
  return siz;
}

template <class T, class U, int CAPACITY>
bool HashTable<T, U, CAPACITY>::containsKey(const U& key) const
{
  int wi = getWrappedIndex(key);
  typename list<Node>::const_iterator it;
  Node temp; temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it == data[wi].end()) // no matching key 
    return false;
  else
    return true;
}

template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::deleteKey(const U& key)
{
  int wi = getWrappedIndex(key);
  typename list<Node>::iterator it;
  Node temp; temp.key = key; // key is parameter 
  it = find(data[wi].begin(), data[wi].end(), temp);
  if (it != data[wi].end()) // no matching key 
  {
    siz--;
    data[wi].erase(it);
  }
}

template <class T, class U, int CAPACITY>
vector<U> HashTable<T, U, CAPACITY>::keys() const
{
  vector<U> result;
  typename list<Node>::const_iterator it;

  for (int wi = 0; wi < CAPACITY; wi++)
    for (it = data[wi].begin(); it != data[wi].end(); it++)
      result.push_back(it->key);

  return result;
}

template <class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::clear()
{
  for (int i = 0; i < CAPACITY; i++)
    data[i].clear();
}

#endif