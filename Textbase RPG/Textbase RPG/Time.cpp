#include "Time.h"
#include <iostream>
#include <Windows.h>
using namespace std;


Time::Time()
{
	
}


Time::~Time()
{
}

int Time::CalculateTime(int hour) {
	
	
	this->hour += hour;
	if (this->hour>24) {
		this->hour -= 24; // This changes the actual value of day.hour
	}
	return this->hour;
}

void Time::DisplayTime() {
	cout << "Time now is: ";

	if (hour > 12 || hour >= 24) { // Check if its 12 p.m to avoid 0 p.m.
		cout << hour - 12;  // this equation only Displays the time, It does not change day.hour value
	}
	else {
		cout << hour; // otherwise the time will be displayed normally
	}
	if (hour > 11 && hour <= 23) {  // to check if the time is PM or AM

		cout << " p.m." << endl;
	}

	else {

		cout << " a.m." << endl;
	}


}

void Time::CdTimer(int second) {
	for (int a = 0; a <= second; a++) {

		cout << endl << second - a << "...";
		Sleep(1000); // time is measured in milli second
	}
}