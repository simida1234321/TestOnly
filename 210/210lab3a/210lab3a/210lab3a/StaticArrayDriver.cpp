// Lab 3a, The "Write A Static Array Class Template" Program
// Programmer: Licong Wang
// on 09/04/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <vector>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3a, The \"Write A Static Array Class Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Object a Testing" << endl;
  StaticArray<int, 10> a;

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 10, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 10);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nTest square bracket operator" << endl;
  cout << "assign values to each element, squared its index" << endl;
  for (int i = 0; i < 10; i++)
  {
    a[i] = i * i;
  }
  cout << "The values are" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << "expecting a[" << i << "] = " << i * i;
    cout << "  actual value: a[" << i << "] = " << a[i] << endl;
    assert(a[i] == i * i);
  }

  cout << "\nTest the inUsed condition, expecting all of them to be used" << endl;
  for (int i = 0; i < a.capacity(); i++)
  {
    if (a.containsKey(i))
    {
      cout << "Index " << i << " : used" << endl;
      assert(a.containsKey(i));
    }
    else
    {
      cout << "Index " << i << " : not used" << endl;
      assert(!(a.containsKey(i)));
    }
  }

  cout << "\nTest the size and capacity again" << endl;
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
    const StaticArray<int, 10> copy = a;
    cout << "\ncheck if their inUse results match, by checking containsKey" << endl;

    for (int i = 0; i < copy.capacity(); i++)
    {
      cout << "Index " << i << ": Object a: ";
      if (a.containsKey(i))
        cout << "used";
      else
        cout << "not used";
      cout << "  Object copy: ";
      if (copy.containsKey(i))
        cout << "used" << endl;
      else
        cout << "not used" << endl;

      assert(a.containsKey(i) == copy.containsKey(i));
    }

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
      {
        cout << "Index: " << copykeys[i] << "  object a: " << a[copykeys[i]] << "  object copy: " << copy[copykeys[i]] << endl;
        assert(a[copykeys[i]] == copy[copykeys[i]]);
      }
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
    const StaticArray<int, 10> copy = a;
    cout << "\ncheck if their inUse results match, by checking containsKey" << endl;

    for (int i = 0; i < copy.capacity(); i++)
    {
      cout << "Index " << i << ": Object a: ";
      if (a.containsKey(i))
        cout << "used";
      else
        cout << "not used";
      cout << "  Object copy: ";
      if (copy.containsKey(i))
        cout << "used" << endl;
      else
        cout << "not used" << endl;

      assert(a.containsKey(i) == copy.containsKey(i));
    }

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
      {
        cout << "Index: " << copykeys[i] << "  object a: " << a[copykeys[i]] << "  object copy: " << copy[copykeys[i]] << endl;
        assert(a[copykeys[i]] == copy[copykeys[i]]);
      }
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

  cout << "\nclear the object a" << endl;
  a.clear();

  cout << "\nTest the size and capacity again" << endl;
  cout << "The expected capacity is 10, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 10);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}