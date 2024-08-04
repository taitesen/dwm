#include <X11/XF86keysym.h>
/* See LICENSE file for copyright and license details. */

/* appearance */
static  const  unsigned  int            borderpx       =           1;   /*border pixel of windows*/
static  const  unsigned  int            gappx          =           16;   /*gaps between windows*/
static  const  unsigned  int            snap           =           5;  /*snap pixel*/
static  const  int                      showbar        =           1;   /*0 means  no       bar*/
static  const  int                      topbar         =           1;   /*0 means  bottom   bar*/
static  const  char                     *fonts[]       =           {"JetBrainsMono Nerd Font:size=14:antialias=true:autohint=true","Font Awesome 6 Free Solid:size=14"};
static  const  char                     dmenufont[]    =           "JetBrainsMono  Nerd Font:size=14:antialias:true";
static  const  char                     col_gray1[]    =           "#222222";
static  const  char                     col_white[]    =           "#ffffff";
static  const  char                     col_black[]    =           "#000000";
static  const  char                     col_yellow1[]  =           "#d79921";
static  const  char                     col_rose[]     =           "#EBBCBA";
static  const  char                     col_gray3[]    =           "#6b6b6b";
static  const  char                     col_yellow[]   =           "#fabd2f";
static  const  char                     col_mauve[]    =           "#ca9ee6";
static  const  char                     col_cyan[]     =           "#005577";
static  const  unsigned  int            baralpha       =           0xd0;
static  const  unsigned  int            borderalpha    =           OPAQUE;

static const char *colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm]  =  {col_gray3,  col_black,  col_black},
    [SchemeSel]   =  {col_rose,   col_black,  col_gray3},
};
static const unsigned int alphas[][3] = {
    /*               fg      bg        border     */
    [SchemeNorm]  =  {OPAQUE,  baralpha,  borderalpha},
    [SchemeSel]   =  {OPAQUE,  baralpha,  borderalpha},
};

/* Brightness*/

/* tagging */
static const char *tags[] = {"", "", "", "", "", "", "", "", ""};

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class                  instance  title   tags mask   isfloating  monitor */
{  "Gimp",                    NULL,     NULL,   0,          1,          -1},
{  "mpv",                     NULL,     NULL,   1 << 3,     0,          -1},
{  "spotify",                 NULL,     NULL,   1 << 4,     0,          -1},
{  "thunar",                  NULL,     NULL,   1 << 5,     0,          -1},
{  "thunderbird",             NULL,     NULL,   1 << 6,     0,          -1},
{  "obs",                     NULL,     NULL,   1 << 7,     0,          -1},
{  "vesktop",                 NULL,     NULL,   1 << 8,     0,          -1},
};

/* layout(s) */
static  const  float  mfact           =  0.55;  /*  factor of  master  area  size  [0.05..0.95]  */
static  const  int    nmaster         =  1;     /*  number of  clients  in  master  area          */
static  const  int    resizehints     =  0;     /*  1  means  respect  size   hints   in   tiled       resizals  */
static  const  int    lockfullscreen  =  1;     /*  1  will   force    focus  on      the  fullscreen  window    */

static const Layout layouts[] = { /* symbol     arrange function */
    {"", tile}, /* first entry is default */
    {"", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
      {MODKEY,                           KEY, view,         {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask,             KEY, toggleview,   {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask,               KEY, tag,          {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag,    {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/*static const char *dmenucmd[] = {*/
/*    "dmenu_run", "-m",      dmenumon, "-fn",    dmenufont, "-nb",     col_gray1,*/
/*    "-nf",       col_gray3, "-sb",    col_cyan, "-sf",     col_gray4, NULL};*/
static  const  char  *dmenucmd[]    =  {"dmenu_run",      NULL};
static  const  char  *termcmd[]     =  {"kitty",             NULL};
static  const  char  *volumeUp[]    =  {"wpctl",          "set-volume",  "@DEFAULT_AUDIO_SINK@",  "5%+",  NULL};
static  const  char  *volumeDown[]  =  {"wpctl",          "set-volume",  "@DEFAULT_AUDIO_SINK@",  "5%-",  NULL};
static  const  char  *screenshot[]  =  {"flameshot",      "gui",         NULL};
static  const  char  *brupcmd[]     =  {"brightnessctl",  "set",         "10%+",                  NULL};
static  const  char  *brdowncmd[]   =  {"brightnessctl",  "set",         "10%-",                  NULL};

static const Key keys[] = {
    /* modifier                    key                 function        argument */
    {MODKEY | ShiftMask,           XK_s,                spawn,          {.v = screenshot}},
    {MODKEY,                       XK_p,                spawn,          {.v = dmenucmd}},
    {MODKEY,                       XK_Return,           spawn,          {.v = termcmd}},
    {MODKEY,                       XK_b,                togglebar,      {0}},
    {MODKEY,                       XK_j,                focusstack,     {.i = +1}},
    {MODKEY,                       XK_k,                focusstack,     {.i = -1}},
    {MODKEY,                       XK_i,                incnmaster,     {.i = +1}},
    {MODKEY,                       XK_d,                incnmaster,     {.i = -1}},
    {MODKEY,                       XK_h,                setmfact,       {.f = -0.05}},
    {MODKEY,                       XK_l,                setmfact,       {.f = +0.05}},
    {MODKEY| ShiftMask,            XK_Return,           zoom,           {0}},
    {MODKEY,                       XK_Tab,              view,           {0}},
    {MODKEY,                       XK_c,                killclient,     {0}},
    {MODKEY,                       XK_t,                setlayout,      {.v = &layouts[0]}},
    {MODKEY,                       XK_f,                setlayout,      {.v = &layouts[1]}},
    {MODKEY,                       XK_m,                setlayout,      {.v = &layouts[2]}},
    {MODKEY,                       XK_space,            setlayout,      {0}},
    {MODKEY | ShiftMask,           XK_space,            togglefloating, {0}},
    {MODKEY,                       XK_0,                view,           {.ui = ~0}},
    {MODKEY | ShiftMask,           XK_0,                tag,            {.ui = ~0}},
    {MODKEY,                       XK_Left,             focusmon,       {.i = -1}},
    {MODKEY,                       XK_Right,            focusmon,       {.i = +1}},
    {MODKEY | ShiftMask,           XK_Left,             tagmon,         {.i = -1}},
    {MODKEY | ShiftMask,           XK_Right,            tagmon,         {.i = +1}},
    {MODKEY,                       XK_minus,            setgaps,        {.i = -1 } },
    {MODKEY,                       XK_equal,            setgaps,        {.i = +1 } },
    {MODKEY | ShiftMask,           XK_equal,            setgaps,        {.i = 0  } },
    {MODKEY,                       XK_comma,            viewtoleft,     {0}},
    {MODKEY,                       XK_period,           viewtoright,    {0}},
    {MODKEY | ShiftMask,           XK_comma,            tagtoleft,      {0}},
    {MODKEY | ShiftMask,           XK_period,           tagtoright,     {0}},
    {MODKEY,                       XK_F3,      	    	spawn,          {.v = volumeUp}},
    {MODKEY,                       XK_F2,    	    	spawn,          {.v = volumeDown}},
    {0,                     XF86XK_MonBrightnessUp,     spawn,          {.v = brupcmd}},
    {0,                     XF86XK_MonBrightnessDown,   spawn,          {.v = brdowncmd}},
    TAGKEYS(                      XK_1,                                 0)
    TAGKEYS(                      XK_2,                                 1)
    TAGKEYS(                      XK_3,                                 2)
    TAGKEYS(                      XK_4,                                 3)
    TAGKEYS(                      XK_5,                                 4)
    TAGKEYS(                      XK_6,                                 5)
    TAGKEYS(                      XK_7,                                 6)
    TAGKEYS(                      XK_8,                                 7)
    TAGKEYS(                      XK_9,                                 8)
    {MODKEY | ShiftMask,          XK_q,                quit,            {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol,           0,              Button1,        setlayout,      {0}},
    {ClkLtSymbol,           0,              Button3,        setlayout,      {.v = &layouts[2]}},
    {ClkWinTitle,           0,              Button2,        zoom,           {0}},
    {ClkStatusText,         0,              Button2,        spawn,          {.v = termcmd}},
    {ClkClientWin,          MODKEY,         Button1,        movemouse,      {0}},
    {ClkClientWin,          MODKEY,         Button2,        togglefloating, {0}},
    {ClkClientWin,          MODKEY,         Button3,        resizemouse,    {0}},
    {ClkTagBar,             0,              Button1,        view,           {0}},
    {ClkTagBar,             0,              Button3,        toggleview,     {0}},
    {ClkTagBar,             MODKEY,         Button1,        tag,            {0}},
    {ClkTagBar,             MODKEY,         Button3,        toggletag,      {0}},
};
