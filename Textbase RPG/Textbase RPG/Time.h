#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Time
{
public:
	Time();
	void displayTime();
	int calculateTime(int hour);
	void cdTimer(int second);
	int getHour();
	~Time();
	void setTime(int hour);

private:
	static int hour; //this equates to 6 am in the morning
	static int day;
};

