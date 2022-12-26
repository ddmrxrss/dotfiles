/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */

/* Some app's icons may not work properly with 11-12 font size in the system tray */
static const char *fonts[]          = { "JetBrainsMono Nerd Font:size=13", "JoyPixels:pixelsize=13:antialias=true:autohint=true", "monospace:size=13" };
static const char dmenufont[]       = "JetBrainsMono Nerd Font:size=13" ;

static const char norm_fg[] = "#cdd6f4";
static const char norm_bg[] = "#1e1e2e";
static const char norm_border[] = "#89b4fa";
static const char sel_fg[] = "#89b4fa";
static const char sel_bg[] = "#1e1e2e";
static const char sel_border[] = "#89b4fa";

static const char *colors[][3]      = {
    /*               fg           bg         border                         */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border }, // unfocused wins
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },  // the focused win
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* To get the class name use "xprop | grep WM_CLASS" command */

	/* class     instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
    { NULL,     		 NULL,     "Event Tester", 0,         0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
#include "shiftview.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont };
static const char *termcmd[]  = { "kitty", NULL };
static const char *roficmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    /* Dmenu */
    { Mod1Mask,                       XK_space,      spawn,          {.v = dmenucmd } },
    /* Lanunch terminal	*/
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    /* Toggle status bar	*/
    { MODKEY,                       XK_b,      togglebar,      {0} },
    /* Move to another terminal 	*/
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    /* Move to another terminal	*/
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    /* Rofi */ 
    { MODKEY,			            XK_r, 	   spawn,          {.v = roficmd  } },
    /* Increase the amount of windows in master area */
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    /* Decrease the amount of windows in master area	*/
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    /* Make the primary area smaller */
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    /* Make the primary area larger */
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    /* Toggle master and stack	*/
    { MODKEY,                       XK_f,      zoom,           {0} },
    /* Increase all gaps */
    { MODKEY,                       XK_equal,      incrgaps,       {.i = +1 } },
    /* Decrease all gaps*/
    { MODKEY,                       XK_minus,      incrgaps,       {.i = -1 } },
    /* Reset gaps back to default */
    { MODKEY|ShiftMask,             XK_equal,      defaultgaps,    {0} },
    /* Cycle through the two last tags	*/
    { MODKEY,                       XK_Tab,    view,           {0} },
    /* Kill a window	*/
    { MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
    /* Floating layout	*/
    { MODKEY,                       XK_e,      setlayout,      {.v = &layouts[1]} },
    /* Toggle floating mode on the active window	*/
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    /* Show all windows	*/
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    /* Move focus to the other monitor */
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    /* Move focus to the other monitor */
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    /* Move the active window to the other monitor */
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    /* Move the active window to the other monitor */
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    /* Move to the next tag */
    { MODKEY,            	        XK_n,      shiftview,	   { .i = +1 } },
    /* Move to the previous tag */
    { MODKEY,                       XK_p,      shiftview,	   { .i = -1 } },
    /* Move floating windows */
    { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
    { MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
    { MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
    { MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
    /* Resize floating windows */
    { MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
    { MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
    { MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
    { MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
    /* Move floating windows to edge of screen */
    { MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
    { MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
    { MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
    { MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
    /* Resize floating windows to edge of screen */
    { MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
    { MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
    { MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
    { MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
    /* Navigate tags */
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    /* Quit DWM	*/
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
    /* [left mouse button on layout tag] - cycle through the two last layouts */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    /* [middle mouse button on window title] - toggle master and stack */
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    /* [middle mouse button on status text] - open the terminal */
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    /* [MODKEY] + [left mouse button on window] - move window */
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    /* [MODKEY] + [middle mouse button on window] - toogle window in being floating */
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    /* [MODKEY] + [right mouse button on window] - resize window */
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    /* Shift view */
    { ClkTagBar,            0,              Button4,        shiftview,     { .i = -1 } },
    { ClkTagBar,            0,              Button5,        shiftview,     { .i = +1 } },
};
