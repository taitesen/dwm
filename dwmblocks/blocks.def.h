//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "cat /tmp/recordingicon",				       	0,		3},
	{"", "sh sb-brightness",				           	5,		0},
	{"", "sh sb-volume",				            	5,		0},
	{"", "sh sb-ram",    				            	5,		0},
	{"", "sh sb-battery",				            	5,		0},
	{"", "sh sb-clock",		     		            	5,		0},
	{"", "sh sb-internet",				            	5,		0},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = "";
static unsigned int delimLen = 5;
