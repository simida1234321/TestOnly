// Lab 2a, The "Writing Overloading Operators" Program
// Programmer: Licong Wang
// on 08/27/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h"  // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2a, The \"Writing Overloading Operators\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time A, B;

  // assigning values
  A.setHours(2);
  A.setMinutes(15);
  A.setSeconds(45);

  B.setHours(3);
  B.setMinutes(30);
  B.setSeconds(20);

  cout << "Object A: Hours: 2  Minutes: 15  Seconds: 45" << endl;
  cout << "Object B  Hours: 3  Minutes: 30  Seconds: 20" << endl;

  cout << "\nobject A testing:\n";

  cout << "The expected value for time in hours is 2.2625, the acutal value is " << A.timeInHours() << endl;
  assert(2.2624 < A.timeInHours() && A.timeInHours() < 2.2626);

  cout << "The expected value for time in minutes is 135.75, the acutal value is " << A.timeInMinutes() << endl;
  assert(135.74 < A.timeInMinutes() && A.timeInMinutes() < 135.76);

  cout << "The expected value for time in seconds is 8145, the acutal value is " << A.timeInSeconds() << endl;
  assert(A.timeInSeconds() == 8145);

  {
    cout << "\nobject copy testing:\n";

    const Time copy = A; // a read-only copy

    // confirm that copy's contents match time's
    cout << "The expected value for time in hours is 2.2625, the acutal value is " << copy.timeInHours() << endl;
    assert(2.2624 < copy.timeInHours() && copy.timeInHours() < 2.2626);

    cout << "The expected value for time in minutes is 135.75, the acutal value is " << copy.timeInMinutes() << endl;
    assert(135.74 < copy.timeInMinutes() && copy.timeInMinutes() < 135.76);

    cout << "The expected value for time in seconds is 8145, the acutal value is " << copy.timeInSeconds() << endl;
    assert(copy.timeInSeconds() == 8145);
  }

  {
    cout << "\nobject assignment testing:\n";

    Time copy; copy = A;

    // confirm that copy's contents match time's
    cout << "The expected value for time in hours is 2.2625, the acutal value is " << copy.timeInHours() << endl;
    assert(2.2624 < copy.timeInHours() && copy.timeInHours() < 2.2626);

    cout << "The expected value for time in minutes is 135.75, the acutal value is " << copy.timeInMinutes() << endl;
    assert(135.74 < copy.timeInMinutes() && copy.timeInMinutes() < 135.76);

    cout << "The expected value for time in seconds is 8145, the acutal value is " << copy.timeInSeconds() << endl;
    assert(copy.timeInSeconds() == 8145);
  }

  // test if A < B
  cout << "\nNow comparing A and B:";
  cout << "\nTesting overloaded operator <, expecting A to be less than B";

  if (A < B)
    cout << "\nThe total time in A is shorter than the total time in B";
  else
    cout << "\nThe total time in A is not shorter than the total time in B";

  assert(A < B);

  // test if B < A
  if (B < A)
    cout << "\nThe total time in B is shorter than the total time in A";
  else
    cout << "\nThe total time in B is not shorter than the total time in A";

  assert(!(B < A));

  // Give B new values, which equal A's
  B.setHours(2);
  B.setMinutes(15);
  B.setSeconds(45);

  // test if A = B
  cout << "\n\nNow assign new values to B, Hours: 2  Mintutes: 15  Seconds: 45";
  cout << "\nTesting overloaded operator ==, expecting A and B to be equal";

  if (A == B)
    cout << "\nThe total time in A equals to the total time in B" << endl;
  else
    cout << "\nThe total time in A does not equal to the total time in B" << endl;

  assert(A == B);

  cout << "\nPress Enter to continue.\n";
  cin.get();
}
