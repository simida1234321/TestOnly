// Lab 5a, The "Applying A Data Structure To A Big Data Application" Program
// Programmer: Licong Wang
// on 09/14/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#include <cstring>
#include <ctime>

#include "DynamicArray.h"

struct Class
{
  string subjectCode;
  int count;
};

struct Info
{
  string term;
  string section;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 5a, The \"Applying A Data Structure To A Big Data Application\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  clock_t startTime = clock();

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  int n = 0;
  int dup = 0;
  bool duplicate;
  bool stored;

  DynamicArray <Info> courseInfo(70000);
  DynamicArray <Class> subjects;

  // read the input file
  while (fin.good())
  {
    // set the check to false
    duplicate = false;
    stored = false;

    if (++n % 1000 == 0)
    {
      cout << '.'; 
      cout.flush();
    }

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

    // check duplicate, continue if does
    for (int i = 0; i < courseInfo.size(); i++)
    {
      if (term == courseInfo[i].term && section == courseInfo[i].section)
      {
        dup++;
        duplicate = true;
        break;
      }
    }

    if (duplicate == true)
      continue;

    Info newInfo;
    newInfo.term = term;
    newInfo.section = section;
    courseInfo[courseInfo.size()] = newInfo;
    
    // check already stored
    for (int i = 0; i < subjects.size(); i++)
    {
      if (subjects[i].subjectCode == subjectCode)
      {
        subjects[i].count++;
        stored = true;
        break;
      }
    }

    if (stored == true)
      continue;

    Class y;
    y.subjectCode = subjectCode;
    y.count = 1;
    subjects[subjects.size()] = y;
  }

  cout << endl;

  fin.close();

  // sort
  for (int i = 0; i < subjects.size(); i++)
    for (int j = i + 1; j < subjects.size(); j++)
      if (subjects[j].subjectCode < subjects[i].subjectCode)
        swap(subjects[j], subjects[i]);

  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  for (int i = 0; i < subjects.size(); i++)
  {
    cout << subjects[i].subjectCode << ", " << subjects[i].count << " sections" << endl;
  }

  cout << "\nDuplicate: " << dup << endl;

  cout.setf(ios::fixed | ios::showpoint);
  cout << setprecision(2);
  cout << "Time used to process and sort: " << elapsedSeconds << endl;

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}