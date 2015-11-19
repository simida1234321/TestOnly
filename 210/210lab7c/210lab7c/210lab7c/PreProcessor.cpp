// Lab 7c, The "Use A Stack" Program
// Programmer: Licong Wang
// on 10/02/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <fstream>
#include <string>
#include <stack>     // using STL stack
using namespace std;

struct Token
{
  char symbol;
  int lineNumber;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 7c, The \"Use A Stack\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  string fileName;
  ifstream fin;
  int count = 0;
  stack<Token> a;
  char error ;
  bool result = true;
  bool ignoreAll = false;  // true when a opening comment offset is found

  cout << "Enter the filename: ";
  getline(cin, fileName);

  fin.open(fileName.c_str());
  if (!fin.good()) throw "I/O error";

  while (fin.good())
  {
    string line;
    getline(fin, line);
    count++;
    bool ignoring = false;  // true when a quote is found

    for (int i = 0; i < line.length(); i++)
    {
      if (line[i] == '*' && i + 1 < line.length())  // when finding the close comment offset
      {
        if (line[i + 1] == '/')
        {
          if (ignoring == true) // if after a quote
            continue;
          if (a.empty())      // no matching opening comment offset
          {
            error = '/';
            result = false;
            break;
          }
          else if (a.top().symbol == '/')  // find match
          {
            ignoreAll = false;
            a.pop();
          }
          else  // dismatch
          {
            error = '/';
            result = false;
            break;
          }
        }
      }
      if (ignoreAll) // check for comment offsets 
        continue;

      if (line[i] == '\"')
      {
        ignoring = !ignoring;
        if (a.empty())  // if empty, first quote
        {
          Token token;
          token.symbol = '"';
          token.lineNumber = count;
          a.push(token);
        }
        else if (a.top().symbol == '\"')  // if matching, second quote
        {
          a.pop();
        }
        else  // if not empty and not matching, first quote
        {
          Token token;
          token.symbol = '"';
          token.lineNumber = count;
          a.push(token);
        }
      }

      if (ignoring) // check for quotes
        continue;

      if (line[i] == '/' && i + 1 < line.length())
        if (line[i + 1] == '/')
          break;

      if (line[i] == '/' && i + 1 < line.length())
        if (line[i + 1] == '*')
        {
          ignoreAll = true;
          Token token;
          token.symbol = '/';
          token.lineNumber = count;
          a.push(token);
        }
        
      if (line[i] == '(')
      {
        Token token;
        token.symbol = '(';
        token.lineNumber = count;
        a.push(token);
      }

      if (line[i] == '{')
      {
        Token token;
        token.symbol = '{';
        token.lineNumber = count;
        a.push(token);
      }

      if (line[i] == '[')
      {
        Token token;
        token.symbol = '[';
        token.lineNumber = count;
        a.push(token);
      }

      if (line[i] == ')')
      {
        if (a.empty())
        {
          error = ')';
          result = false;
          break;
        }
        else if (a.top().symbol == '(')
        {
          a.pop();
        }
        else
        {
          error = ')';
          result = false;
          break;
        }
      }

      if (line[i] == '}')
      {
        if (a.empty())
        {
          error = '}';
          result = false;
          break;
        }
        else if (a.top().symbol == '{')
        {
          a.pop();
        }
        else
        {
          error = '}';
          result = false;
          break;
        }
      }

      if (line[i] == ']')
      {
        if (a.empty())
        {
          error = ']';
          result = false;
          break;
        }
        else if (a.top().symbol == '[')
        {
          a.pop();
        }
        else
        {
          error = ']';
          result = false;
          break;
        }
      }
    }

    if (result == false)  // if an error exists
      break;   // exit while loop

    if (!(a.empty()))
      if (a.top().symbol == '\"')  // didnt find maching quote
      {
        break;  // exit while loop
      }
  }

  fin.close();

  if (result == false)
  {
    if (error == ')')
    {
      cout << "Closing parenthesis found in line " << count << " of " << fileName;
      cout << "\nBut no matching opening parenthesis found" << endl;
    }
    if (error == '}')
    {
      cout << "Closing curly brace found in line " << count << " of " << fileName;
      cout << "\nBut no matching opening curly brace found" << endl;
    }
    if (error == ']')
    {
      cout << "Closing square bracket found in line " << count << " of " << fileName;
      cout << "\nBut no matching opening square bracket found" << endl;
    }
    if (error == '/')
    {
      cout << "Closing comment offset found in line " << count << " of " << fileName;
      cout << "\nBut no matching opening comment offset found" << endl;
    }
  }
  else if (!(a.empty()))
  {
    if (a.top().symbol == '(')
    {
      cout << "Opening parenthesis found in line " << a.top().lineNumber << " of " << fileName;
      cout << "\nBut no matching closing parenthesis found" << endl;
    }
    if (a.top().symbol == '{')
    {
      cout << "Opening curly brace found in line " << a.top().lineNumber << " of " << fileName;
      cout << "\nBut no matching closing curly brace found" << endl;
    }
    if (a.top().symbol == '[')
    {
      cout << "Opening square bracket found in line " << a.top().lineNumber << " of " << fileName;
      cout << "\nBut no matching closing square bracket found" << endl;
    }
    if (a.top().symbol == '/')
    {
      cout << "Opening comment offset found in line " << a.top().lineNumber << " of " << fileName;
      cout << "\nBut no matching closing comment offset found" << endl;
    }
    if (a.top().symbol == '\"')
    {
      cout << "Opening quote found in line " << count << " of " << fileName;
      cout << "\nBut no matching closing quote found" << endl;
    }
  }
  else 
    cout << "No mismatches found by my preprocessor in " << fileName << endl;

  cin.get();
  cout << "Press ENTER to continue..." << endl;
}
