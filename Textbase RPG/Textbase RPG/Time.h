#pragma once
class Time
{
public:
	Time();
	void DisplayTime();
	int CalculateTime(int hour);
	void CdTimer(int second);

	~Time();
	
private:
	int hour = 24;
};

