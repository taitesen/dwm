/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1; /* -b  option; if 0, dmenu appears at bottom     */
static const unsigned int alpha = 0xff;     /* Amount of opacity. 0xff is opaque             */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 400;                    /* minimum width when centered */
static const float menu_height_ratio = 4.0f;  /* This is the ratio used in the original calculation */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
    "Terminess Nerd Font:size=15:antialias:true:autohint=true:style=Bold",
    "monospace:size=15:antialias=true:autohint=true"};

static const char *prompt = NULL ; /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
    /*     fg         bg       */
    [SchemeNorm]  =  {"#bbac9b",  "#1d1a1c"},
    [SchemeSel]   =  {"#1d1a1c",  "#bbac9b"},
    [SchemeOut]   =  {"#000000",  "#d79921"},
};

static const unsigned int alphas[SchemeLast][2] = {
	[SchemeNorm] = { OPAQUE, alpha },
	[SchemeSel] = { OPAQUE, alpha },
	[SchemeOut] = { OPAQUE, alpha },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/* -h option; minimum height of a menu line */
static unsigned int lineheight = 35;
static unsigned int min_lineheight = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
