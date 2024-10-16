static const unsigned int borderpx  = 0;
static const unsigned int snap      = 0;

static const unsigned int gappih    = 10;
static const unsigned int gappiv    = 10;
static const unsigned int gappoh    = 10;
static const unsigned int gappov    = 20;

static       int smartgaps          = 0;

static const int showbar            = 1;
static const int topbar             = 0;

static const int vertpad            = 10;
static const int sidepad            = 20;

static const int horizpadbar        = 0;
static const int vertpadbar         = 20;

static const char *fonts[]          = { "Terminess Nerd Font:size=16:style=Bold:antialias=true:autohint=true", "Font Awesome 6 Free:size=14:antialias=true:autohint=true"};
static const char dmenufont[]       = "monospace:size=10";

static const char col_gray[]        = "#6b6b6b";
static const char col_black[]       = "#000000";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_rose[]        = "#EBBCBA";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray, col_black, col_black },
	[SchemeSel]  = { col_rose, col_black,  col_black  },
};

static const char *tags[] = { "U", "I", "O", "P", "H", "J", "K", "L", "N" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                 instance    title       tags mask     isfloating   monitor */
	{ "Gimp",                NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",             NULL,       NULL,       1 << 8,       0,           -1 },
	{ "mpv",                 NULL,       NULL,       1 << 8,       0,           -1 },
	{ "VirtualBox Manager",  NULL,       NULL,       1 << 3,       0,           -1 },
};

static const float mfact     = 0.55;
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "  ",  tile },    /* first entry is default */
	{ "  ",  monocle },
	{ "  ",  spiral },
	{ "  ",  dwindle },
	{ "  ",  deck },
	{ "  ",  bstack },
	{ "  ",  bstackhoriz },
	{ " 󰕰 ",  grid },
	{ " 󰾍 ",  nrowgrid },
	{ " 󱗼 ",  horizgrid },
	{ ":::",  gaplessgrid },
	{ " 󰕭 ",  centeredmaster },
	{ "  ",  centeredfloatingmaster },
	{ "  ",  NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

static const char *termcmd[]  = { "st", NULL };

static const char *dmenucmd[] = { "dmenu_run", NULL };

static const char *screenshot[]  = { "flameshot", "gui", NULL };

static const char *toggleblur[]  = { "toggleblur", NULL };

static const char *browser[] = { "qutebrowser", NULL };

static const char *emacs[] = { "emacsclient", "-c", "-a \"emacs\"", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_w,      spawn,          {.v = browser } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emacs } },
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
        { MODKEY|ShiftMask,             XK_s,      spawn,          {.v   =   screenshot    }     },
        { MODKEY|ShiftMask,             XK_b,      spawn,          {.v   =   toggleblur    }     },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_period, focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_comma,  focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_Up,     incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_Down,   incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_bracketleft,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_bracketright,      setmfact,       {.f = +0.01} },
	{ MODKEY|ShiftMask,             XK_bracketleft,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_bracketright,      setcfact,       {.f = -0.25} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY|Mod1Mask,              XK_3,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_3,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_4,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_4,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_5,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_5,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_0,      view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY|ControlMask,		    XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_Tab,    view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_KP_Left,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_KP_Right, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_KP_Left,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_KP_Right, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_u,                      0)
	TAGKEYS(                        XK_i,                      1)
	TAGKEYS(                        XK_o,                      2)
	TAGKEYS(                        XK_p,                      3)
	TAGKEYS(                        XK_h,                      4)
	TAGKEYS(                        XK_j,                      5)
	TAGKEYS(                        XK_k,                      6)
	TAGKEYS(                        XK_l,                      7)
	TAGKEYS(                        XK_n,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

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
