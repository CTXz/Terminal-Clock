#include <iostream>
#include <chrono>
#include <math.h>

using namespace std;
using namespace std::chrono;

static const int nLines = 5;

class asciiNum
{
	public:
	string lines[nLines]; // Vertical Lines
};


/* Declare Numbers in ASCII */
asciiNum ascii[10];
asciiNum colon;

void initAsciiTimes()
{
	ascii[0].lines[0] = "|||||";
	ascii[0].lines[1] = "|   |";
	ascii[0].lines[2] = "|   |";
	ascii[0].lines[3] = "|   |";
	ascii[0].lines[4] = "|||||";

	ascii[1].lines[0] = "|||";
	ascii[1].lines[1] = "|||";
	ascii[1].lines[2] = "|||";
	ascii[1].lines[3] = "|||";
	ascii[1].lines[4] = "|||";

	ascii[2].lines[0] = "|||||";
	ascii[2].lines[1] = "    |";
	ascii[2].lines[2] = "|||||";
	ascii[2].lines[3] = "|    ";
	ascii[2].lines[4] = "|||||";

	ascii[3].lines[0] = "|||||";
	ascii[3].lines[1] = "    |";
	ascii[3].lines[2] = "|||||";
	ascii[3].lines[3] = "    |";
	ascii[3].lines[4] = "|||||";

	ascii[4].lines[0] = "|   |";
	ascii[4].lines[1] = "|   |";
	ascii[4].lines[2] = "|||||";
	ascii[4].lines[3] = "    |";
	ascii[4].lines[4] = "    |";

	ascii[5].lines[0] = "|||||";
	ascii[5].lines[1] = "|    ";
	ascii[5].lines[2] = "|||||";
	ascii[5].lines[3] = "    |";
	ascii[5].lines[4] = "|||||";

	ascii[6].lines[0] = "|||||";
	ascii[6].lines[1] = "|    ";
	ascii[6].lines[2] = "|||||";
	ascii[6].lines[3] = "|   |";
	ascii[6].lines[4] = "|||||";

	ascii[7].lines[0] = "|||||";
	ascii[7].lines[1] = "    |";
	ascii[7].lines[2] = "    |";
	ascii[7].lines[3] = "    |";
	ascii[7].lines[4] = "    |";

	ascii[8].lines[0] = "|||||";
	ascii[8].lines[1] = "|   |";
	ascii[8].lines[2] = "|||||";
	ascii[8].lines[3] = "|   |";
	ascii[8].lines[4] = "|||||";

	ascii[9].lines[0] = "|||||";
	ascii[9].lines[1] = "|   |";
	ascii[9].lines[2] = "|||||";
	ascii[9].lines[3] = "    |";
	ascii[9].lines[4] = "    |";

	colon.lines[0] = " ||| ";
	colon.lines[1] = " ||| ";
	colon.lines[2] = "     ";
	colon.lines[3] = " ||| ";
	colon.lines[4] = " ||| ";	
}

void displayTime(int h, int m)
{
	int digitH[2] = {(h / 10), (h % 10)};
	int digitM[2] = {(m / 10), (m % 10)};

	for (int i = 0; i < nLines; i++)
	{
		cout

		<< ascii[digitH[0]].lines[i] + " " + ascii[digitH[1]].lines[i]	// Hours
		<<  " " + colon.lines[i] + " " 									// Colon 
		<< ascii[digitM[0]].lines[i] + " " + ascii[digitM[1]].lines[i]	// Minutes

		<< endl;
	}
}

/* Get Minutes of Current Day */
unsigned long getMinutes()
{
	system_clock::time_point currentHour = system_clock::now();
	system_clock::duration tillNow = currentHour.time_since_epoch();

	unsigned long minutes = ((tillNow.count() / pow(10, 9)) / 60 ); // Get to minutes since epoch

	return minutes - ((minutes / 60) * 60); // Get minutes of current day
}

/* Get Hours of Current Day */
unsigned long getHours()
{
	system_clock::time_point currentHour = system_clock::now();
	system_clock::duration tillNow = currentHour.time_since_epoch();

	unsigned long hours = (((tillNow.count() / pow(10, 9)) / 60) / 60 ); // Get to hours since epoch
	
	hours += 2; // +2 CEST

	return hours - ((hours / 24) * 24); // Get Hours of current day
}

int main ()
{
	/* Initialize ASCII art for time digits */
	initAsciiTimes();

	unsigned long minuteStamp;

	while (true)
	{
		/* Update Clock */
		if (getMinutes() != minuteStamp)
		{
			/* Update time stamp */
			minuteStamp = getMinutes();

			/* Clear screen */
			cout << "\033[2J\033[1;1H" << endl;

			/* Finally draw the time */
	 		displayTime(getHours(), getMinutes());
		}
	}

	return 0;
}
