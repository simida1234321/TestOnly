// Lab 11a, The "Write And Test A Priority Queue Template" Program
// Programmer: Licong Wang
// on 11/02/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 11a, The \"Write And Test A Priority Queue Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  PriorityQueue<int> pq;

  cout << "\nTest size and empty" << endl;
  cout << "The expected size is 0, the acutal size is " << pq.size() << endl;
  assert(pq.size() == 0);
  cout << "Expect it to be empty: ";
  if (pq.empty())
    cout << "Empty" << endl;
  else
    cout << "Not Empty" << endl;
  assert(pq.empty());

  cout << "\nEnqueue values 1 to 5" << endl;
  for (int i = 1; i < 6; i++)
  {
    pq.enqueue(i);
  }

  cout << "\nTest size and empty again" << endl;
  cout << "The expected size is 5, the acutal size is " << pq.size() << endl;
  assert(pq.size() == 5);
  cout << "Expect it to be not empty: ";
  if (pq.empty())
    cout << "Empty" << endl;
  else
    cout << "Not Empty" << endl;
  assert(!(pq.empty()));

  cout << "\nCheck its front and back, expecting 5 and 3, accroding to the rule of binary tree" << endl;
  cout << "Front: " << pq.front() << endl;
  cout << "back: " << pq.back() << endl;
  assert(pq.front() == 5);
  assert(pq.back() == 3);

  cout << "\nCheck the heap array using copy pop, expecting values from 5-1, "
    << "since the highest value is popped each time" << endl;
  for (PriorityQueue<int> copy = pq; copy.size(); )
    cout << copy.dequeue() << " ";

  cout << "\n\nNow dequeue once" << endl;
  pq.dequeue();

  cout << "\nTest size again" << endl;
  cout << "The expected size is 4, the acutal size is " << pq.size() << endl;
  assert(pq.size() == 4);

  cout << "\nCheck its front and back, expecting 4 and 1" << endl;
  cout << "Front: " << pq.front() << endl;
  cout << "back: " << pq.back() << endl;
  assert(pq.front() == 4);
  assert(pq.back() == 1);

  cout << "\ncheck the heap array using copy pop, expecting values from 4-1, "
    << "since 5 is already dequeued" << endl;
  for (PriorityQueue<int> copy = pq; copy.size(); )
    cout << copy.dequeue() << " ";
  cout << endl;

  {
    cout << "\nObject Copy Testing" << endl;
    const PriorityQueue<int> copy = pq;

    cout << "\nTest size and empty" << endl;
    cout << "The expected size is 4, the acutal size is " << pq.size() << endl;
    assert(pq.size() == 4);
    cout << "Expect it to be not empty: ";
    if (pq.empty())
      cout << "Empty" << endl;
    else
      cout << "Not Empty" << endl;
    assert(!(pq.empty()));

    cout << "\ncheck the heap array using copy pop, expecting values from 4-1" << endl;
    for (PriorityQueue<int> copy2 = copy; copy2.size(); )
      cout << copy2.dequeue() << " ";
    cout << endl;
  }

  {
    cout << "\nObject Assignment Testing" << endl;
    PriorityQueue<int> copy; copy = pq;

    cout << "\nTest size and empty" << endl;
    cout << "The expected size is 4, the acutal size is " << pq.size() << endl;
    assert(pq.size() == 4);
    cout << "Expect it to be not empty: ";
    if (pq.empty())
      cout << "Empty" << endl;
    else
      cout << "Not Empty" << endl;
    assert(!(pq.empty()));

    cout << "\ncheck the heap array using copy pop, expecting values from 4-1" << endl;
    for (PriorityQueue<int> copy2 = copy; copy2.size();)
      cout << copy2.dequeue() << " ";
    cout << endl;
  }

  cout << "\nBack to original object, test clear" << endl;
  pq.clear();

  cout << "\nTest size and empty" << endl;
  cout << "The expected size is 0, the acutal size is " << pq.size() << endl;
  assert(pq.size() == 0);
  cout << "Expect it to be empty: ";
  if (pq.empty())
    cout << "Empty" << endl;
  else
    cout << "Not Empty" << endl;
  assert(pq.empty());

  cout << "\nCheck its front and back, expecting 0 and 0, dummy got returned" << endl;
  cout << "Front: " << pq.front() << endl;
  cout << "back: " << pq.back() << endl;
  assert(pq.front() == 0);
  assert(pq.back() == 0);

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}