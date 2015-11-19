// Lab 9a, The "Write, Test, and Apply The AssociativeArray Template" Program
// Programmer: Licong Wang
// on 10/12/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include <cstring>
#include <cassert>

#include "AssociativeArray.h"
#include "AssociativeArray.h" // testing ifndef

struct TermSection
{
  string term;
  string section;
};

bool operator==(const TermSection&, const TermSection&);

int main()
{
  // print my name and this assignment's title
  cout << "Lab 9a, The \"Write, Test, and Apply The AssociativeArray Template\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Object a Testing, using default initial capacity, 0" << endl;
  AssociativeArray<string, TermSection> a;

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 0, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 0);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);
  
  cout << "\nNow reading 100 lines from DvcSchedule and store in the associative array" << endl;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0;

  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    if (n++ > 100)
      break;

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

    TermSection ts = { term, section };
    a[ts] = course;
  }

  fin.close();

  cout << "\nTest capacity and size" << endl;
  cout << "The expected capacity is 99, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 99);
  cout << "The expected size is 99, the acutal size is " << a.size() << endl;
  assert(a.size() == 99);

  cout << "\nTest keys" << endl;
  cout << "The expected size for keys vector is 99, since there are 99 nodes inused" << endl;
  vector<TermSection> keys = a.keys();
  cout << "The size of keys is " << keys.size() << endl;
  assert(keys.size() == 99);

  {
    cout << "\nObject Copy Testing" << endl;
    const AssociativeArray<string, TermSection> copy = a;

    cout << "\ncheck if their key vectors match" << endl;
    vector<TermSection> copykeys = copy.keys();
    if (keys == copykeys)
      cout << "the two vectors are are equal" << endl;
    else
      cout << "the two vectors are not are equal" << endl;
    assert(keys == copykeys);

    cout << "\nNow check if it contains \"Fall 2015, 8240\", from the frist line of DvcSchedules" << endl;
    TermSection ts = { "Fall 2015", "8240" };
    if (copy.containsKey(ts))
    {
      cout << "it contains Fall 2015, 8240" << endl;
      cout << "\nNow check if the matching course is Math-121" << endl;

      if (copy[ts] == "MATH-121")
        cout << "The course is " << copy[ts] << endl;
    }
    assert(copy.containsKey(ts));
    assert(copy[ts] == "MATH-121");
  }

  {
    cout << "\nObject Assignment Testing" << endl;
    AssociativeArray<string, TermSection> copy; copy = a;

    cout << "\ncheck if their key vectors match" << endl;
    vector<TermSection> copykeys = copy.keys();
    if (keys == copykeys)
      cout << "the two vectors are are equal" << endl;
    else
      cout << "the two vectors are not are equal" << endl;
    assert(keys == copykeys);

    cout << "\nNow check if it contains \"Fall 2015, 8240\", from the frist line of DvcSchedules" << endl;
    TermSection ts = { "Fall 2015", "8240" };
    if (copy.containsKey(ts))
    {
      cout << "it contains Fall 2015, 8240" << endl;
      cout << "\nNow check if the matching course is Math-121" << endl;

      if (copy[ts] == "MATH-121")
        cout << "The course is " << copy[ts] << endl;
    }
    assert(copy.containsKey(ts));
    assert(copy[ts] == "MATH-121");
  }

  cout << "\nNow reading 100 lines again from DvcSchedule, and delete the matchings" << endl;

  n = 0;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    if (n++ > 100)
      break;

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

    TermSection ts = { term, section };

    if (a.containsKey(ts))
    {
      assert(course == a[ts]);
      a.deleteKey(ts);
    }

    assert(!(a.containsKey(ts)));
  }

  fin.close();

  cout << "\nTest capacity and size, everything in associative array should be already deleted" << endl;
  cout << "The expected capacity is 99, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 99);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nclear the object a" << endl;
  a.clear();

  cout << "\nTest the size and capacity again" << endl;
  cout << "The expected capacity is 0, the acutal capacity is " << a.capacity() << endl;
  assert(a.capacity() == 0);
  cout << "The expected size is 0, the acutal size is " << a.size() << endl;
  assert(a.size() == 0);

  cout << "\nPress ENTER to continue..." << endl;
  cin.get();
}

bool operator==(const TermSection& x, const TermSection& y)
{
  if (x.term != y.term)
    return false;
  if (x.section != y.section)
    return false;
  return true;
}