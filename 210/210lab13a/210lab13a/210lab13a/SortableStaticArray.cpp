// Lab 3b, The "Write A Static Array Class Template" Program
// Programmer: Licong Wang
// on 09/04/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#include "SortableStaticArray.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3b, The \"Write A Static Array Class Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  SortableStaticArray<int, 100> a;
  string buf;
  int key;
  int value;

  while (true)
  {
    cout << "Input an index and a value [Q to quit]: ";

    cin >> buf;
    if (buf == "Q" || buf == "q")
      break;
    key = atoi(buf.c_str());

    cin >> buf;
    value = atoi(buf.c_str());
    a[key] = value;
  }

  cout << "\nI stored this many values : " << a.size() << endl;
  cout << "These values are:" << endl;

  vector<int> keys = a.keys();
  for (int i = 0; i < keys.size(); i++)
    cout << keys[i] << " " << a[keys[i]] << endl;

  while (true)
  {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> buf;

    if (buf == "Q" || buf == "q")
      break;
    else
    {
      key = atoi(buf.c_str());
      if (a.containsKey(key))
        cout << "Found it -- the value stored at " << key << " is " << a[key] << endl;
      else
        cout << "I didn't find it" << endl;
    }
  }

  a.sort();
  keys = a.keys();
  for (int i = 0; i < keys.size(); i++)
    cout << keys[i] << " " << a[keys[i]] << endl;


  cout << "\nPress ENTER to continue.\n";
  cin.ignore();  // prevent cin.get() from getting a new line from previous cin
  cin.get();
}
