// Lab 12a, The "Write A Customer Service Simulation" Program
// Programmer: Licong Wang
// on 11/14/2015
// Editor(s) used: Visual studio 2013
// Compiler(s) used: Microsoft c++ complier

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

#include <cstdlib>
#include <ctime>
#include <cmath>

struct Customer
{
  int arrivalTime;
  int startTime;
  int endTime;
  char id;
};

struct ServiceEvent
{
  int clock;
  int serverNumber;
  bool operator<(const ServiceEvent& e) const { return clock > e.clock; }
};

int getRandomNumberOfServiceRequests(double);

int main()
{
  // print my name and this assignment's title
  cout << "Lab 12a, The \"Write A Customer Service Simulation\" Program \n";
  cout << "Programmer: Licong Wang\n";
  cout << "Editor(s) used: Visual studio 2013\n";
  cout << "Compiler(s) used:  Microsoft c++ complier\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  int numberOfServers, maxLength, minTime, maxTime, arrivalStop;
  double avgRate;
  char buf[100];

  // open the input file
  ifstream fin;
  fin.open("Simulation.txt");
  if (!fin.good()) throw "I/O error";

  fin >> buf; numberOfServers = atoi(buf);
  fin >> buf; avgRate = atof(buf);
  fin >> buf; maxLength = atoi(buf);
  fin >> buf; minTime = atoi(buf);
  fin >> buf; maxTime = atoi(buf);
  fin >> buf; arrivalStop = atoi(buf);

  fin.close();

  cout << "number of servers:     " << numberOfServers << endl;
  cout << "customer arrival rate: " << avgRate << " per minute, for " << arrivalStop << " minutes" << endl;
  cout << "maximum queue length:  " << maxLength << endl;
  cout << "minimum service time:  " << minTime << endl;
  cout << "maximum service time:  " << maxTime << endl;
  cout.setf(ios::fixed | ios::showpoint);
  cout << setprecision(2);
  cout << "expected turn away rate: " << avgRate - (double(numberOfServers) * 2 / (maxTime + minTime)) << " per minute, while full" << endl;
  cout << endl;

  queue<Customer> waitQueue;
  priority_queue<ServiceEvent> scheduledEvent;
  vector<Customer> completed;
  vector<Customer> serverArray(numberOfServers);
  vector<bool> inUse(numberOfServers);

  for (int i = 0; i < numberOfServers; i++)
    inUse[i] = false;

  int turnedAway = 0;
  int costumerCreated = 0;

  srand(time(0)); rand();

  // the clock time loop
  for (int time = 0;; time++) // the clock time
  {
    // handle all service events scheduled to complete at this clock time
    while (!scheduledEvent.empty() && scheduledEvent.top().clock == time)
    {
      int serverNum = scheduledEvent.top().serverNumber;
      scheduledEvent.pop();
      serverArray[serverNum].endTime = time;
      completed.push_back(serverArray[serverNum]);
      inUse[serverNum] = false;
    }

    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if (time < arrivalStop)
    {
      int arrivals = getRandomNumberOfServiceRequests(avgRate);
      for (int i = 0; i < arrivals; i++)
      {
        if (waitQueue.size() == maxLength)
          turnedAway++;
        else
        {
          Customer c;
          c.arrivalTime = time;
          c.id = (char)('A' + (costumerCreated++ % 26));
          waitQueue.push(c);
        }
      }
    }

    // for idle servers, move customer from wait queue and begin service
    for (int i = 0; i < serverArray.size(); i++)
    {
      if (inUse[i] == false && !waitQueue.empty())
      {
        serverArray[i] = waitQueue.front();
        waitQueue.pop();
        serverArray[i].startTime = time;
        inUse[i] = true;
        int serviceTime = minTime + rand() % (maxTime - minTime + 1);
        ServiceEvent e;
        e.clock = time + serviceTime;
        e.serverNumber = i;
        scheduledEvent.push(e);
      }
    }

    // output the summary
    cout << "Time: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "line now serving wait queue" << endl;
    cout << "---- ----------- ----------" << endl;

    for (int i = 0; i < serverArray.size(); i++)
    {
      cout << "  " << i << "       ";

      if (inUse[i] == true)
        cout << serverArray[i].id;
      else
        cout << " ";

      if (i == 0)
      {
        cout << "      ";
        for (queue<Customer> copy = waitQueue; !copy.empty(); copy.pop())
          cout << copy.front().id;
      }

      cout << endl;
    }

    cout << "---------------------------" << endl;

    // summarize performance
    if (time > 0)
    {
      int Time;
      double sum = 0;
      double avgTime;
      double avgTurnedAway;

      for (int i = 0; i < completed.size(); i++)
      {
        Time = completed[i].endTime - completed[i].arrivalTime;
        sum += Time;
      }

      if (completed.size() != 0)
        avgTime = sum / completed.size();
      else
        avgTime = 0;

      avgTurnedAway = double(turnedAway) / time;

      cout.setf(ios::fixed | ios::showpoint);
      cout << setprecision(3);
      cout << "Avg time: " << avgTime << ". Turned away per minute: " << avgTurnedAway << endl;
    }

    // if the user wants to quit, break out of this loop
    cout << "Press ENTER to continue, X-ENTER to exit..." << endl;
    cout << endl;

    string s;
    getline(cin, s);
    if (s == "x" || s == "X") 
      break;
  }

  cin.get();
  cout << "Press Enter to continue..." << endl;
}

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnRequests) > 0.0;
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}