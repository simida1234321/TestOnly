// Lab 1b, The "More Class Programming And Testing" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
using namespace std;

#include <cassert>

#include "Time.h"
#include "Time.h"  // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1b, The \"More Class Programming And Testing\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;

  // assigning values
  time.setHours(2);
  time.setMinutes(15);
  time.setSeconds(45);

  cout << "Hours: 2  Minutes: 15  Seconds: 45" << endl;
  cout << "\noriginal object testing:\n";

  cout << "The expected value for time in hours is 2.2625, the acutal value is " << time.timeInHours() << endl;
  assert(2.2624 < time.timeInHours() && time.timeInHours() > 2.2626);

  cout << "The expected value for time in minutes is 135.75, the acutal value is " << time.timeInMinutes() << endl;
  assert(135.74 < time.timeInMinutes() && time.timeInMinutes() < 135.76);

  cout << "The expected value for time in seconds is 8145, the acutal value is " << time.timeInSeconds() << endl;
  assert(time.timeInSeconds() == 8145);

  {
    cout << "\nobject copy testing:\n";

    const Time copy = time; // a read-only copy

    // confirm that copy's contents match time's
    cout << "The expected value for time in hours is 2.2625, the acutal value is " << copy.timeInHours() << endl;
    assert(2.2624 < copy.timeInHours() && time.timeInHours() < 2.2626);

    cout << "The expected value for time in minutes is 135.75, the acutal value is " << copy.timeInMinutes() << endl;
    assert(135.74 < copy.timeInMinutes() && time.timeInMinutes() < 135.76);

    cout << "The expected value for time in seconds is 8145, the acutal value is " << copy.timeInSeconds() << endl;
    assert(copy.timeInSeconds() == 8145);
  }

  {
    cout << "\nobject assignment testing:\n";

    Time copy; copy = time;

    // confirm that copy's contents match time's
    cout << "The expected value for time in hours is 2.2625, the acutal value is " << copy.timeInHours() << endl;
    assert(2.2624 < copy.timeInHours() && time.timeInHours() < 2.2626);

    cout << "The expected value for time in minutes is 135.75, the acutal value is " << copy.timeInMinutes() << endl;
    assert(135.74 < copy.timeInMinutes() && time.timeInMinutes() < 135.76);

    cout << "The expected value for time in seconds is 8145, the acutal value is " << copy.timeInSeconds() << endl;
    assert(copy.timeInSeconds() == 8145);
  }

  cout << "\nPress Enter to continue.\n";
  cin.get();
}