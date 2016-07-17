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
	
private:
	int hour = 6; //this equates to 6 am in the morning
	int day = 0;
};

