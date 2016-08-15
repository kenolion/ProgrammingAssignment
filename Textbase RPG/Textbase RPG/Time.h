#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Time
{
public:
	Time();
	Time(int hour,int day);
	void displayTime();
	static int calculateTime(int hour);
	void cdTimer(int second);
	static int getHour();
	static int getDay();
	~Time();
	void setTime(int hour);
	
private:
	static int hour; //this equates to 6 am in the morning
	static int day;
};

