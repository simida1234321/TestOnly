// Lab 7b, The "Write And Test A Queue Template" Program
// Programmer: Licong Wang
// on 10/02/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 7b, The \"Write And Test A Queue Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Object a Testing" << endl;
  Queue<int> a;
  int x, y;

  cout << "\nChecking size, the expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nChecking empty, expecting the queue to be empty" << endl;
  if (a.empty())
    cout << "It is empty" << endl;
  else
    cout << "It is not empty" << endl;
  assert(a.empty());

  cout << "\nNow push 10 values to the queue, square of the indexes" << endl;
  for (int i = 0; i < 10; i++)
  {
    cout << "Assign index " << i << " to " << i * i << endl;
    a.push(i * i);
  }

  cout << "\nCreate a copy to check the values, expecting 0, 1, 4..., 81" << endl;
  Queue<int> copy = a;
  while (!copy.empty())
  {
    copy.pop(x);
    cout << x << ' ';
  }
  cout << endl;

  cout << "\nCheck its peak, expecting the oldest value, 0" << endl;
  a.peek(x);
  cout << "The peak is: " << x << endl;
  assert(x == 0);

  cout << "\nCheck size again, the expected size is 10, the acutal size is " << a.size() << endl;
  assert(a.size() == 10);
  cout << "\nChecking empty again, expecting the queue to be not empty" << endl;
  if (a.empty())
    cout << "It is empty" << endl;
  else
    cout << "It is not empty" << endl;
  assert(!(a.empty()));

  cout << "\nNow pop 5 values from the queue, use the parameter to record the value" << endl;
  cout << "Expecting the oldest, 0, 1, 4, 9, 16 to be popped" << endl;

  for (int i = 0; i < 5; i++)  // make assertion easier 
  {
    a.pop(x);
    cout << "The value being popped is " << x << " at index " << i << endl;
    assert(x == i * i);
  }

  {
    cout << "\nObject Copy Testing" << endl;
    const Queue<int> copy = a;

    cout << "\nCheck if their sizes match, expect them to be matched" << endl;
    if (a.size() == copy.size())
      cout << "Their sizes match" << endl;
    else
      cout << "Their sizes do not match" << endl;
    assert(a.size() == copy.size());

    cout << "\nCheck if their peaks match, expect them to be matched" << endl;
    a.peek(x);
    copy.peek(y);
    if (x == y)
      cout << "Their peaks match" << endl;
    else
      cout << "Their peaks do not match" << endl;
    assert(x == y);

    cout << "\nCreating a copy of the copy, then use pop to check each element" << endl;
    cout << "expecting 5 values being popped, 25, 36, 49, 64, 81" << endl;
    Queue<int> copy2 = copy;

    while (!copy2.empty())
    {
      copy2.pop(x);
      cout << x << ' ';
    }
    cout << endl;
  }

  {
    cout << "\nObject Copy Testing" << endl;
    Queue<int> copy; copy = a;

    cout << "\nCheck if their sizes match, expect them to be matched" << endl;
    if (a.size() == copy.size())
      cout << "Their sizes match" << endl;
    else
      cout << "Their sizes do not match" << endl;
    assert(a.size() == copy.size());

    cout << "\nCheck if their peaks match, expect them to be matched" << endl;
    a.peek(x);
    copy.peek(y);
    if (x == y)
      cout << "Their peaks match" << endl;
    else
      cout << "Their peaks do not match" << endl;
    assert(x == y);

    cout << "\nCreating a copy of the copy, then use pop to check each element" << endl;
    cout << "expecting 5 values being popped, 25, 36, 49, 64, 81" << endl;
    Queue<int> copy2 = copy;

    while (!copy2.empty())
    {
      copy2.pop(x);
      cout << x << ' ';
    }
    cout << endl;
  }

  cout << "\nBack to object a" << endl;
  cout << "\nTesting clear" << endl;
  a.clear();

  cout << "\nCheck size again, the expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nCheck peak again, expect it to return false, since size is 0" << endl;
  bool result;
  result = a.peek(x);

  if (result)
    cout << "peak returned true" << endl;
  else
    cout << "peak returned false" << endl;
  assert(!(result));

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}
