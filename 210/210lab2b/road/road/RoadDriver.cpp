// Lab 2b, The "Writing Templates And Overloading Operators" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#define DEBUG     // enable assert
#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2b, The \"Writing Templates And Overloading Operators\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Road <double> A, B;
  Road <int> C, D;

  // assigning values
  A.setLength(4.1);
  A.setWidth(5.2);

  B.setLength(6.3);
  B.setWidth(7.4);

  C.setLength(4);
  C.setWidth(5);

  D.setLength(6);
  D.setWidth(7);

  cout << "Double Object A: Length: 4.1  Width: 5.2" << endl;
  cout << "Double Object B  Length: 6.3  Width: 7.4" << endl;
  cout << "int Object C  Length: 4  Width: 5" << endl;
  cout << "int Object D  Length: 6  Width: 7" << endl;

  cout << "\nobject A testing:\n";

  cout << "The expected value for Length is 4.1, the acutal value is " << A.getLength() << endl;
  assert(A.getLength() == 4.1);

  cout << "The expected value for Width is 5.2, the acutal value is " << A.getWidth() << endl;
  assert(A.getWidth() == 5.2);

  cout << "The expected value for Volume is 30956.6, the acutal value is " << A.asphalt(3.3) << endl;
  assert(30956.5 < A.asphalt(3.3) && A.asphalt(3.3) < 30956.7);

  {
    cout << "\nobject copy testing:\n";

    Road <double> copy = A; // a read-only copy

    // confirm that copy's contents match road's
    cout << "The expected value for Length is 4.1, the acutal value is " << copy.getLength() << endl;
    assert(copy.getLength() == 4.1);

    cout << "The expected value for Width is 5.2, the acutal value is " << copy.getWidth() << endl;
    assert(copy.getWidth() == 5.2);

    cout << "The expected value for Volume is 30956.6, the acutal value is " << copy.asphalt(3.3) << endl;
    assert(30956.5 < copy.asphalt(3.3) && copy.asphalt(3.3) < 30956.7);
  }

  {
    cout << "\nobject assignment testing:\n";

    Road <double> copy; copy = A;

    // confirm that copy's contents match road's
    cout << "The expected value for Length is 4.1, the acutal value is " << copy.getLength() << endl;
    assert(copy.getLength() == 4.1);

    cout << "The expected value for Width is 5.2, the acutal value is " << copy.getWidth() << endl;
    assert(copy.getWidth() == 5.2);

    cout << "The expected value for Volume is 30956.6, the acutal value is " << copy.asphalt(3.3) << endl;
    assert(30956.5 < copy.asphalt(3.3) && copy.asphalt(3.3) < 30956.7);
  }

  // test if A < B
  cout << "\nNow comparing A and B, depending on length:";
  cout << "\nTesting overloaded operator <, expecting A to be less than B";

  if (A < B)
    cout << "\nRoad A is less than Road B";
  else
    cout << "\nRoad A is not less than Road B";

  assert(A < B);

  // test if B < A
  if (B < A)
    cout << "\nRoad B is less than Road A";
  else
    cout << "\nRoad B is not less than Road A";

  assert(!(B < A));

  // Give B new values, which equal A's
  B.setLength(4.1);
  B.setWidth(5.2);

  // test if A = B
  cout << "\n\nNow assign new values to B, Length: 4.1  Width: 5.2";
  cout << "\nComparing A and B, depending on both length and width:";
  cout << "\nTesting overloaded operator ==, expecting A and B to be equal";
  if (A == B)
    cout << "\nRoad A is equal to Road B";
  else
    cout << "\nRoad A is not equal to Road B";

  assert(A == B);

  // test if C < D
  cout << "\n\nNow comparing C and D, depending on length:";
  cout << "\nTesting overloaded operator <, expecting C to be less than D";

  if (C < D)
    cout << "\nRoad C is less than Road D";
  else
    cout << "\nRoad C is not less than Road D";

  assert(C < D);

  // test if D < C
  if (D < C)
    cout << "\nRoad D is less than Road C";
  else
    cout << "\nRoad D is not less than Road C";

  // Give D new values, which equal C's
  D.setLength(4);
  D.setWidth(5);

  // test if C = D
  cout << "\n\nNow assign new values to D, Length: 4  Width: 5";
  cout << "\nComparing C and D, depending on both length and width:";
  cout << "\nTesting overloaded operator ==, expecting C and D to be equal";

  if (C == D)
    cout << "\nRoad C is equal to Road D" << endl;
  else
    cout << "\nRoad C is not equal to Road D" << endl;

  assert(C == D);

  cout << "\nPress Enter to continue.\n";
  cin.get();
}