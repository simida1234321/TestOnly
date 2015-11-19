// Lab 2a, The "Writing Overloading Operators" Program
// Programmer: Licong Wang
// on 08/27/2015
// Editor(s) used: Visual Studio 2013
// Compiler(s) used: Microsoft c++ complier

#ifndef Time_h
#define Time_h

class Time
{
public:
	void setHours(int);  // setters
	void setMinutes(int);
	void setSeconds(int);
	double timeInHours() const;  // getters
	double timeInMinutes() const;
	int timeInSeconds() const;

private:
	int Hours;
	int Minutes;
	int Seconds;
};

bool operator<(const Time&, const Time&);
bool operator==(const Time&, const Time&);

#endif
