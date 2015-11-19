// Lab 8a, The "Perform A Simple Timing Study" Program
// Programmer: Licong Wang
// on 10/05/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // for cout and endl
#include <string> // for string
#include <fstream>
using namespace std;

#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstring> // for strcpy

int main()
{
  // print my name and this assignment's title
  cout << "Lab 8a, The \"Perform A Simple Timing Study\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // problem setup goes here

  // programmer customizations go here
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 10;  // 10 times

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // for parsing the inputfile
    int count = 0;
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    
    for (int reps = 0; reps < REPS; reps++) // use any value for REPS 
    {
      ifstream fin;
      fin.open("dvc-schedule.txt");
      if (!fin.good()) throw "I/O error";

      while (fin.good())
      {
        count++;
        if (count >= n) break;

        // read the line
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());
        if (buf[0] == 0) continue;

        // parse the line
        const string term(token = strtok(buf, tab));
        const string section(token = strtok(0, tab));
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; // invalid line
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
      }

      fin.close();
      count = 0;     
    }

    clock_t endTime = clock();

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
  }

  cout << "Press ENTER to continue..." << endl;
  cin.get();
}