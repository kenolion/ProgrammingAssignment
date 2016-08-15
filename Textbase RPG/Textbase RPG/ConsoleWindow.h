#ifndef CONSOLEWINDOW
#define CONSOLEWINDOW

class ConsoleWindow
{

public:
	static void ShowConsoleCursor(bool torf);
	static void SetDrawingPoint(int x, int y);
	static void SetFontColour(int kolor);
	static void equalSignMaker9000(int eqCount); // COUT'S EQUAL SIGNS
	ConsoleWindow(); // ignore 4now
	~ConsoleWindow();

};

#endif