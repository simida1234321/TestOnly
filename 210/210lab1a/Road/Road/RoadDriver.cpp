// Lab 1a, The "Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1a, The \"Class Programming And Testing\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Road road;

  // assigning values
  road.setWidth(5.2);
  road.setLength(4.1);

  cout << "\noriginal object testing:\n";

  cout << "The expected value for Width is 5.2, the acutal value is " << road.getWidth() << endl;
  assert(road.getWidth() == 5.2);

  cout << "The expected value for Length is 4.1, the acutal value is " << road.getLength() << endl;
  assert(road.getLength() == 4.1);

  cout << "The expected value for Volume is 30956.6, the acutal value is " << road.asphalt(3.3) << endl;
  assert(30956.5 < road.asphalt(3.3) && road.asphalt(3.3) < 30956.7);

  {
    cout << "\nobject copy testing:\n";

    const Road copy = road; // a read-only copy

    // confirm that copy's contents match road's
    cout << "The expected value for Width is 5.2, the acutal value is " << copy.getWidth() << endl;
    assert(copy.getWidth() == 5.2);

    cout << "The expected value for Length is 4.1, the acutal value is " << copy.getLength() << endl;
    assert(copy.getLength() == 4.1);

    cout << "The expected value for Volume is 30956.6, the acutal value is " << copy.asphalt(3.3) << endl;
    assert(30956.5 < copy.asphalt(3.3) && copy.asphalt(3.3) < 30956.7);
  }

  {
    cout << "\nobject assignment testing:\n";

    Road copy; copy = road;

    // confirm that copy's contents match road's
    cout << "The expected value for Width is 5.2, the acutal value is " << copy.getWidth() << endl;
    assert(copy.getWidth() == 5.2);

    cout << "The expected value for Length is 4.1, the acutal value is " << copy.getLength() << endl;
    assert(copy.getLength() == 4.1);

    cout << "The expected value for Volume is 30956.6, the acutal value is " << copy.asphalt(3.3) << endl;
    assert(30956.5 < copy.asphalt(3.3) && copy.asphalt(3.3) < 30956.7);
  }

  cout << "\nPress Enter to continue.\n";
  cin.get();
}