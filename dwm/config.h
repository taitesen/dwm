/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Terminess Nerd Font:size=15:style=Bold:antialias=true:autohint=true", "Font Awesome 6 Free:size=16:antialias=true:autohint=true" };
static const char col_gray[]       = "#6b6b6b";
static const char col_black[]       = "#000000";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_rose[]        = "#ebbcba";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray, col_black, col_black },
	[SchemeSel]  = { col_rose, col_black,  col_rose },
};

/* tagging */
static const char *tags[] = { "U", "I", "O", "P", "H", "J", "K", "L", "N" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                         instance    title       tags mask     isfloating   monitor    float x,y,w,h         floatborderpx*/
	{ "Gimp",                        NULL,       NULL,       0,            1,           -1,        50,50,500,500,        -1 },
	{ "zen-beta",                   NULL,       NULL,       1 << 1,       0,           -1,        50,50,500,500,        -1 },
	{ "qutebrowser",                 NULL,       NULL,       1 << 2,       0,           -1,        50,50,500,500,        -1 },
	{ "Zathura",                     NULL,       NULL,       1 << 3,       0,           -1,        50,50,500,500,        -1 },
	{ "eu.betterbird.Betterbird",    NULL,       NULL,       1 << 4,       0,           -1,        50,50,500,500,        -1 },
	{ "Emacs",                       NULL,       NULL,       1 << 5,       1,           -1,        310,10,1300,1020,     -1 },
	{ "mpv",                         NULL,       NULL,       1 << 8,       0,           -1,        50,50,500,500,        -1 },
	{ "floatingst",                  NULL,       NULL,       0,            1,           -1,        460,10,1000,400,      10 },
	{ "smallfloatingst",             NULL,       NULL,       0,            1,           -1,        460,10,1000,100,      10 },
	{ "pwSt",                        NULL,       NULL,       0,            1,           -1,        10,10,300,600,        10 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *termcmd[]  = { "kitty", NULL };
static const char *screenshot[]  = { "flameshot", "gui", NULL };
static const char *toggleblur[]  = { "toggleblur", NULL };
static const char *emacs[]  = { "emacs", NULL };
static const char *quickmarkcmd[] = { "st", "-c", "floatingst", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "ff", NULL };
static const char *pwdClipboard[] = { "st", "-c", "pwSt", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "dongle", NULL };
static const char *gogglecmd[] = { "st", "-c", "smallfloatingst", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "googleSearch", NULL };
static const char *perpcmd[] = { "st", "-c", "smallfloatingst", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "perpSearch", NULL };
static const char *ytcmd[] = { "st", "-c", "smallfloatingst", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "yt", NULL };
static const char *zathuracmd[] = { "st", "-c", "floatingst", "-f", "Terminess Nerd Font:style=Bold:size=19", "-e", "zathuracmd", NULL };

static const Key keys[] = {
	/* modifier               key                 function                argument */
	{ MODKEY|ShiftMask,       XK_y,               spawn,                  {.v = zathuracmd } },
	{ MODKEY,                 XK_y,               spawn,                  {.v = ytcmd } },
	{ MODKEY,                 XK_m,               spawn,                  {.v = gogglecmd } },
	{ MODKEY|ShiftMask,       XK_m,               spawn,                  {.v = perpcmd } },
	{ MODKEY,                 XK_q,               spawn,                  {.v = quickmarkcmd } },
	{ MODKEY,                 XK_e,               spawn,                  {.v = emacs } },
	{ MODKEY,                 XK_space,           spawn,                  {.v = dmenucmd } },
	{ MODKEY|ShiftMask,       XK_space,           spawn,                  {.v = pwdClipboard } },
	{ MODKEY,                 XK_Return,          spawn,                  {.v = termcmd } },
	{ MODKEY|ShiftMask,       XK_s,               spawn,                  {.v = screenshot } },
	{ MODKEY|ShiftMask,       XK_b,               spawn,                  {.v = toggleblur } },
	{ MODKEY,                 XK_b,               togglebar,              {0} },
	{ MODKEY,                 XK_period,          focusstack,             {.i = +1 } },
	{ MODKEY,                 XK_comma,           focusstack,             {.i = -1 } },
	{ MODKEY,                 XK_Up,              incnmaster,             {.i = +1 } },
	{ MODKEY,                 XK_Down,            incnmaster,             {.i = -1 } },
	{ MODKEY,                 XK_bracketleft,     setmfact,               {.f = -0.01} },
	{ MODKEY,                 XK_bracketright,    setmfact,               {.f = +0.01} },
	{ MODKEY|ShiftMask,       XK_Return,          zoom,                   {0} },
	{ MODKEY,                 XK_s,               togglesticky,           {0} },
	{ MODKEY,                 XK_9,               view,                   {0} },
	{ MODKEY,                 XK_c,               killclient,             {0} },
	{ MODKEY,                 XK_1,               setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                 XK_2,               setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                 XK_3,               setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                 XK_4,               setlayout,              {0} },
	{ MODKEY|ShiftMask,       XK_f,               togglefloating,         {0} },
	{ MODKEY,                 XK_0,               view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,       XK_0,               tag,                    {.ui = ~0 } },
	{ MODKEY,                 XK_KP_Left,         focusmon,               {.i = -1 } },
	{ MODKEY,                 XK_KP_Right,        focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,       XK_KP_Left,         tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,       XK_KP_Right,        tagmon,                 {.i = +1 } },
	TAGKEYS(                  XK_u,               0)
	TAGKEYS(                  XK_i,               1)
	TAGKEYS(                  XK_o,               2)
	TAGKEYS(                  XK_p,               3)
	TAGKEYS(                  XK_h,               4)
	TAGKEYS(                  XK_j,               5)
	TAGKEYS(                  XK_k,               6)
	TAGKEYS(                  XK_l,               7)
	TAGKEYS(                  XK_n,               8)
	{ MODKEY|ShiftMask,       XK_q,               quit,                   {0} },
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

