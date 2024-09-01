/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 5;        /* horizontal padding for statusbar */
static const int vertpadbar         = 15;        /* vertical padding for statusbar */
static const int vertpad            = 6;       /* vertical padding of bar */
static const int sidepad            = 20;       /* horizontal padding of bar */
static const char *fonts[]          = { "Terminess Nerd Font:size=14:antialias=true:autohint=true", "Font Awesome 6 Free:size=14:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray[]        = "#6b6b6b";
static const char col_black[]       = "#000000";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_rose[]        = "#EBBCBA";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray,  col_black, col_black },
	[SchemeSel]  = { col_rose, col_black,  col_black  },
	[SchemeStatus]  = { col_gray, col_black,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_rose, col_black,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNorm]  = { col_gray, col_black,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { col_rose, col_black,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm]  = { col_gray, col_black,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}
};

/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };*/
/*static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };*/
static const char *tags[] = { "U", "I", "O", "P", "H", "J", "K", "L", "N" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "mpv",      NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *screenshot[]  = { "flameshot", "gui", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *toggleblur[]  = { "toggleblur", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
{         MODKEY,                     XK_space,         spawn,           {.v   =   dmenucmd      }     },
{         MODKEY,                     XK_Return,        spawn,           {.v   =   termcmd       }     },
{         MODKEY|ShiftMask,           XK_s,             spawn,           {.v   =   screenshot    }     },
{         MODKEY|ShiftMask,           XK_b,             spawn,           {.v   =   toggleblur    }     },
{         MODKEY,                     XK_b,             togglebar,       {0}   },
{         MODKEY,                     XK_j,             focusstack,      {.i   =   +1            }     },
{         MODKEY,                     XK_k,             focusstack,      {.i   =   -1            }     },
/*{       MODKEY,                     XK_i,             incnmaster,      {.i   =   +1            }     },*/
/*{       MODKEY,                     XK_d,             incnmaster,      {.i   =   -1            }     },*/
{         MODKEY,                     XK_bracketleft,   setmfact,        {.f   =   -0.01}        },
{         MODKEY,                     XK_bracketright,  setmfact,        {.f   =   +0.01}        },
/*{       MODKEY|ShiftMask,           XK_h,             setcfact,        {.f   =   +0.25}        },*/
/*{       MODKEY|ShiftMask,           XK_l,             setcfact,        {.f   =   -0.25}        },*/
/*{       MODKEY|ShiftMask,           XK_o,             setcfact,        {.f   =   0.00}         },*/
{         MODKEY|ShiftMask,           XK_Return,        zoom,            {0}   },
{         MODKEY|Mod1Mask,            XK_3,             incrgaps,        {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_3,             incrgaps,        {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_4,             incrigaps,       {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_4,             incrigaps,       {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_5,             incrogaps,       {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_5,             incrogaps,       {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_6,             incrihgaps,      {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_6,             incrihgaps,      {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_7,             incrivgaps,      {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_7,             incrivgaps,      {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_8,             incrohgaps,      {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_8,             incrohgaps,      {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_9,             incrovgaps,      {.i   =   +1            }     },
{         MODKEY|Mod1Mask|ShiftMask,  XK_9,             incrovgaps,      {.i   =   -1            }     },
{         MODKEY|Mod1Mask,            XK_0,             togglegaps,      {0}   },
{         MODKEY|Mod1Mask|ShiftMask,  XK_0,             defaultgaps,     {0}   },
{         MODKEY,                     XK_0,             view,            {0}   },
{         MODKEY,                     XK_c,             killclient,      {0}   },
/*{         MODKEY,                     XK_t,             setlayout,       {.v   =   &layouts[0]}  },*/
/*{         MODKEY,                     XK_f,             setlayout,       {.v   =   &layouts[1]}  },*/
/*{         MODKEY,                     XK_m,             setlayout,       {.v   =   &layouts[2]}  },*/
{         MODKEY|ControlMask,         XK_comma,         cyclelayout,     {.i   =   -1            }     },
{         MODKEY|ControlMask,         XK_period,        cyclelayout,     {.i   =   +1            }     },
{         MODKEY|ShiftMask,           XK_space,         setlayout,       {0}   },
/*{         MODKEY|ShiftMask,           XK_space,         togglefloating,  {0}   },*/
{         MODKEY,                     XK_Tab,           view,            {.ui  =   ~0            }     },
{         MODKEY|ShiftMask,           XK_0,             tag,             {.ui  =   ~0            }     },
/*{       MODKEY,                     XK_Left,          focusmon,        {.i   =   -1            }     },*/
/*{       MODKEY,                     XK_Right,         focusmon,        {.i   =   +1            }     },*/
/*{       MODKEY|ShiftMask,           XK_Left,          tagmon,          {.i   =   -1            }     },*/
/*{       MODKEY|ShiftMask,           XK_Right,         tagmon,          {.i   =   +1            }     },*/
{         MODKEY,                     XK_comma,         viewtoleft,      {0}   },
{         MODKEY,                     XK_period,        viewtoright,     {0}   },
{         MODKEY|ShiftMask,           XK_comma,         tagtoleft,       {0}   },
{         MODKEY|ShiftMask,           XK_period,        tagtoright,      {0}   },
          TAGKEYS(                    XK_u,                               0)
          TAGKEYS(                    XK_i,                               1)
          TAGKEYS(                    XK_o,                               2)
          TAGKEYS(                    XK_p,                               3)
          TAGKEYS(                    XK_h,                               4)
          TAGKEYS(                    XK_j,                               5)
          TAGKEYS(                    XK_k,                               6)
          TAGKEYS(                    XK_l,                               7)
          TAGKEYS(                    XK_n,                               8)
{         MODKEY|ShiftMask,           XK_q,             quit,            {0}   },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
