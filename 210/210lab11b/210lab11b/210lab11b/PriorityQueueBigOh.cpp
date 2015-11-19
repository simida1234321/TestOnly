// Lab 11b, The "Perform A Simple Timing Study" Program
// Programmer: Licong Wang
// on 11/04/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

#include "PriorityQueue.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 11b, The \"Perform A Simple Timing Study\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  // problem setup goes here

  // programmer customizations go here
  int n = 8000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = n / 100; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // more problem setup goes here -- the stuff not timed
    PriorityQueue<int> a(n * 3);
    for (int i = n; i > 0; i--)
      a.enqueue(i);

    // assert that n is the size of the data structure if applicable
    assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    for(int i = 0; i < REPS; i++)
      a.enqueue(n + i + 1);

    clock_t endTime = clock();

    // validation block -- assure that process worked if applicable
    assert(a.size() == n + REPS);

    for (int i = 0; i < n + REPS; i++)
      assert(a.dequeue() >= a.front());

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << endl;
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;
  n = 8000000;

  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // more problem setup goes here -- the stuff not timed
    PriorityQueue<int> a (n * 3);
    for (int i = n; i > 0; i--)
      a.enqueue(i);

    // assert that n is the size of the data structure if applicable
    assert(a.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    for (int i = 0; i < REPS; i++)
      a.dequeue();

    clock_t endTime = clock();

    // validation block -- assure that process worked if applicable
    assert(a.size() == n - REPS);

    for (int i = 0; i < n - REPS; i++)
      assert(a.dequeue() >= a.front());

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm  = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << "Press Enter to continue..." << endl;
  cin.get();
}