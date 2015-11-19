// Lab 5b, The "Using A Data Structure As A Data Member" Program
// Programmer: Licong Wang
// on 09/16/2015
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

struct SC
{
  string course;
  int count;
};

struct LS
{
  string subjectCode;
  DynamicArray<SC> courses;
};

struct Info
{
  string term;
  string section;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 5b, The \"Using A Data Structure As A Data Member\" Program \n";
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
  bool courseStored;
  bool subjectStored;

  DynamicArray <Info> courseInfo(70000);
  DynamicArray <LS> subjects;

  // read the input file
  while (fin.good())
  {
    // set the check to false
    duplicate = false;
    subjectStored = false;
    courseStored = false;

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
      if (subjects[i].subjectCode == subjectCode)   // check if the subject is stored
      {
        subjectStored = true;
        for (int j = 0; j < subjects[i].courses.size(); j++)
        {
          if (course == subjects[i].courses[j].course)  // check if the course is stored
          {
            courseStored = true;
            subjects[i].courses[j].count++;
            break;
          }
        }

        if (courseStored == true)
          break;

        SC newCourse;
        newCourse.course = course;
        newCourse.count = 1;
        subjects[i].courses[subjects[i].courses.size()] = newCourse;

        break;
      }
    }

    if (subjectStored == true)
      continue;

    LS newSubject;
    newSubject.subjectCode = subjectCode;
    SC newCourse;
    newCourse.course = course;
    newCourse.count = 1;

    newSubject.courses[0] = newCourse;
    subjects[subjects.size()] = newSubject;
  }

  cout << endl;
  fin.close();

  // sort
  for (int i = 0; i < subjects.size(); i++)
    for (int j = i + 1; j < subjects.size(); j++)
      if (subjects[j].subjectCode < subjects[i].subjectCode)
        swap(subjects[j], subjects[i]);

  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  ofstream fout;
  fout.open("DvcSchedule.xls");
  if (!fout.good()) throw "I/O error";

  fout << "Subjects\t" << "Sections\t" << "Numbers" << endl;
  for (int i = 0; i < subjects.size(); i++)
  {
    cout << subjects[i].subjectCode << ", " << subjects[i].courses.size() << " course(s)" << endl;
    fout << subjects[i].subjectCode << "\t\t" << subjects[i].courses.size() << "\n";
    for (int j = 0; j < subjects[i].courses.size(); j++)
    {
      cout << "\t" << subjects[i].courses[j].course << ", " << subjects[i].courses[j].count << " section(s)" << endl;
      fout << "\t" << subjects[i].courses[j].course << "\t" << subjects[i].courses[j].count << "\n";
    }
  }

  fout.close();

  cout << endl;

  cout << "\nDuplicate: " << dup << endl;

  cout.setf(ios::fixed | ios::showpoint);
  cout << setprecision(2);
  cout << "Time used to process and sort: " << elapsedSeconds << endl;

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}