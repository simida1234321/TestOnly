// Lab 8c, The "Perform A Timing Study On The STL Array Sort Function" Program
// Programmer: Licong Wang
// on 10/07/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // for cout and endl
#include <string> // for string
#include <algorithm>
using namespace std;

#include <cmath> // for log and pow
#include <cassert>
#include <ctime> // for clock() and clock_t
#include <cstdlib> // for srand and rand

int main()
{
  // print my name and this assignment's title
  cout << "Lab 8c, The \"Perform A Timing Study On The STL Array Sort Function\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // problem setup goes here
  srand(time(0));
  rand();

  // programmer customizations go here
  int n = 10000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 5000; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;

  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // more problem setup goes here -- the stuff not timed
    double* a = new double[n];

    for (int i = 0; i < n; i++)
    {
      a[i] = rand() / (rand() + 100.0);
    }

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    for (int reps = 0; reps < REPS; reps++) // use any value for REPS 
    {
      sort(a, a + n);
    }

    clock_t endTime = clock();

    // assert sort;
    for (int i = 1; i < n; i++) assert(a[i - 1] <= a[i]);

    // validation block -- assure that process worked

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

    delete[] a;
  }

  cout << "Press ENTER to continue..." << endl;
  cin.get();
}