#pragma once
class Time
{
public:
	Time();
	void displayTime();
	int calculateTime(int hour);
	void cdTimer(int second);

	~Time();
	
private:
	int hour = 24;
};

