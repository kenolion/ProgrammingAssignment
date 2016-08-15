#include "Time.h"
int Time::hour;
int Time::day;

Time::Time()
{
	
}
Time::Time(int hour,int day)
{
	this->hour = hour;
	this->day = day;

}


Time::~Time()
{
}

void Time::setTime(int hour)
{
	this->hour = hour;
}

int Time::calculateTime(int hour1) {
	hour += hour1;
	if (hour>24) {
		hour -= 24; // This changes the actual value of day.hour heres where it changes to another day
		day++;

		system("cls");
		Sleep(1000);
		cout << "You survived the day. Good job coming this FAR.\nDAY " << Time::getDay() << " starts now.\n";
		system("pause");

	}
	return hour;
}

void Time::displayTime() {
	cout << "Time now is: ";

	if (hour > 12 || hour >= 24) { // Check if its 12 p.m to avoid 0 p.m.
		cout << hour - 12;  // this equation only Displays the time, It does not change day.hour value
	}
	else {
		cout << hour; // otherwise the time will be displayed normally
	}
	if (hour > 11 && hour <= 23) {  // to check if the time is PM or AM

		cout << " p.m" << endl;
	}

	else {

		cout << " a.m." << endl;
	}


}

void Time::cdTimer(int second) {
	for (int a = 0; a <= second; a++) {

		cout << endl << second - a << "...";
		Sleep(1000); // time is measured in milli second
	}
}

int Time::getHour()
{
	return hour;
}

int Time::getDay() {
	return day;
}
