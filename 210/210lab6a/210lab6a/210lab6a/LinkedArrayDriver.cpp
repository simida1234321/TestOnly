// Lab 6a, The "Write A Linked Array Class Template" Program
// Programmer: Licong Wang
// on 09/23/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <vector>
using namespace std;

#include <cassert>

#include "LinkedArray.h"
#include "LinkedArray.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 6a, The \"Write A Linked Array Class Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Object a Testing, using default initial capacity, 0" << endl;
  LinkedArray<int> a;

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 0, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 0);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nTest square bracket operator" << endl;
  cout << "assign values to first 10 elements, squared its index" << endl;
  for (int i = 0; i < 10; i++)
  {
    a[i] = i * i;
  }
  cout << "The values are" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << "expecting a[" << i << "] = " << i * i;
    cout << "  actual value: a[" << i << "] = " << a[i] << endl;
   // assert(a[i] == i * i);
  }

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 10, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 10);
  cout << "The expected size is 10, the acutal size is " << a.size() << endl;
  assert(a.size() == 10);

  cout << "\nTest delete" << endl;
  a.deleteKey(3);
  cout << "delete index 3, expect it to not be used" << endl;

  if (a.containsKey(3))
    cout << "Index 3 : used" << endl;
  else
    cout << "Index 3: not used" << endl;
  assert(!(a.containsKey(3)));

  cout << "\nTest the keys vector" << endl;
  cout << "expecting 0-2, 4-9 to be inused indexes, since 3 is already deleted" << endl;
  cout << "The acutal inused index and their values are:" << endl;
  vector<int> keys = a.keys();

  for (int i = 0; i < keys.size(); i++)
    cout << "a[" << keys[i] << "] = " << a[keys[i]] << endl;

  cout << "\nTest the size and capacity again" << endl;
  cout << "The expected capacity is 10, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 10);
  cout << "The expected size is 9, the acutal size is " << a.size() << endl;
  assert(a.size() == 9);

  {
    cout << "\nObject Copy Testing" << endl;
    const LinkedArray<int> copy = a;

    cout << "\ncheck if their inUse results match, by checking containsKey" << endl;
    for (int i = 0; i < copy.capacity(); i++)
      assert(a.containsKey(i) == copy.containsKey(i));
    cout << "Their inUse conditions match" << endl;

    cout << "\ncheck if their key vectors match" << endl;
    vector<int> copykeys = copy.keys();

    cout << "inUsed Index: object a: ";
    for (int i = 0; i < keys.size(); i++)
    {
      cout << keys[i] << ", ";
    }

    cout << "\ninUsed Index: object copy: ";
    for (int i = 0; i < copykeys.size(); i++)
    {
      cout << copykeys[i] << ", ";
      assert(keys[i] == copykeys[i]);
    }

    if (keys == copykeys)
    {
      cout << "\nthe two vectors are are equal" << endl;

      cout << "\nthen check if their values match" << endl;
      for (int i = 0; i < copykeys.size(); i++)
        assert(a[copykeys[i]] == copy[copykeys[i]]);
      cout << "Their values match" << endl;
    }
    else
      cout << "the two vectors are not are equal" << endl;
    assert(keys == copykeys);

    cout << "\ncheck if their capacities match" << endl;
    cout << "Object a: " << a.capacity() << "  Object copy: " << copy.capacity() << endl;
    if (a.capacity() == copy.capacity())
      cout << "their capacities are equal" << endl;
    else
      cout << "their capacities are not equal" << endl;
    assert(a.capacity() == copy.capacity());

    cout << "\ncheck if their sizes match" << endl;
    cout << "Object a: " << a.size() << "  Object copy: " << copy.size() << endl;
    if (a.size() == copy.size())
      cout << "their sizes are equal" << endl;
    else
      cout << "their sizes are not equal" << endl;
    assert(a.size() == copy.size());
  }

  {
    cout << "\nObject Assignment Testing" << endl;
    LinkedArray<int> copy; copy = a;

    cout << "\ncheck if their inUse results match, by checking containsKey" << endl;
    for (int i = 0; i < copy.capacity(); i++)
      assert(a.containsKey(i) == copy.containsKey(i));
    cout << "Their inUse conditions match" << endl;

    cout << "\ncheck if their key vectors match" << endl;
    vector<int> copykeys = copy.keys();

    cout << "inUsed Index: object a: ";
    for (int i = 0; i < keys.size(); i++)
    {
      cout << keys[i] << ", ";
    }

    cout << "\ninUsed Index: object copy: ";
    for (int i = 0; i < copykeys.size(); i++)
    {
      cout << copykeys[i] << ", ";
      assert(keys[i] == copykeys[i]);
    }

    if (keys == copykeys)
    {
      cout << "\nthe two vectors are are equal" << endl;

      cout << "\nthen check if their values match" << endl;
      for (int i = 0; i < copykeys.size(); i++)
        assert(a[copykeys[i]] == copy[copykeys[i]]);
      cout << "Their values match" << endl;
    }
    else
      cout << "the two vectors are not are equal" << endl;
    assert(keys == copykeys);

    cout << "\ncheck if their capacities match" << endl;
    cout << "Object a: " << a.capacity() << "  Object copy: " << copy.capacity() << endl;
    if (a.capacity() == copy.capacity())
      cout << "their capacities are equal" << endl;
    else
      cout << "their capacities are not equal" << endl;
    assert(a.capacity() == copy.capacity());

    cout << "\ncheck if their sizes match" << endl;
    cout << "Object a: " << a.size() << "  Object copy: " << copy.size() << endl;
    if (a.size() == copy.size())
      cout << "their sizes are equal" << endl;
    else
      cout << "their sizes are not equal" << endl;
    assert(a.size() == copy.size());
  }

  cout << "\nBack to object a, Test its expandability, a[200] and a[-10]" << endl;
  a[200] = 200;
  a[-10] = -10;

  cout << "\nTest the size and capacity again" << endl;
  cout << "The expected capacity is 201, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 201);
  cout << "The expected size is 10, the acutal size is " << a.size() << endl;
  assert(a.size() == 10);

  cout << "\nclear the object a" << endl;
  a.clear();

  cout << "\nTest the size and capacity again" << endl;
  cout << "The expected capacity is 201, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 201);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nObject b Testing, set its initial capacity to 15" << endl;
  LinkedArray<int> b(15);

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 15, the acutal capacity is " << b.capacity() << endl;
  assert(b.capacity() == 15);
  cout << "The expected size is 0, the acutal size is " << b.size() << endl;
  assert(b.size() == 0);

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}