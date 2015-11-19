// Lab 2c, The "Using Templated Classes" Program
// Programmer: Licong Wang
// on 08/19/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2c, The \"Using Templated Classes\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  stack <double> s;
  string buf;

  while (true)
  {
    cout << "Enter: ";

    for (stack<double> copy = s; !copy.empty(); copy.pop())
    {
      cout << copy.top() << " ";
    }

    cin >> buf;
    cin.ignore(1000, 10);

    // check for signs and size
    if (buf == "+")
    {
      if (s.size() >= 2)
      {
        double a = s.top();
        s.pop();
        double b = s.top();
        s.pop();
        double c = a + b;
        s.push(c);
      }
    }
    else if (buf == "-")
    {
      if (s.size() >= 2)
      {
        double a = s.top();
        s.pop();
        double b = s.top();
        s.pop();
        double c = b - a;
        s.push(c);
      }
    }
    else if (buf == "/")
    {
      if (s.size() >= 2)
      {
        double a = s.top();
        s.pop();
        double b = s.top();
        s.pop();
        double c = b / a;
        s.push(c);
      }
    }
    else if (buf == "*")
    {
      if (s.size() >= 2)
      {
        double a = s.top();
        s.pop();
        double b = s.top();
        s.pop();
        double c = a * b;
        s.push(c);
      }
    }
    else if (buf == "Q" || buf == "q")
      break;
    else
    {
      double d = atof(buf.c_str());
      s.push(d);
    }
  }

  cout << "\nPress ENTER to continue.\n";
  cin.get();
}

  