//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
	{"", "sh sb-brighness",				            	5,		0},
	{"", "sh sb-volume",				            	5,		0},
	{"", "sh sb-cpu",    				            	5,		0},
	{"", "sh sb-batter",				            	5,		0},
	{"", "sh sb-clock",		     		            	5,		0},
	{"", "sh sb-internet",				            	5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
