#ifndef GAMEINPUT_H
#define GAMEINPUT_H
/*
-----------------------------------------------------------------------------
 Class: GameInput

 Desc: An input event specific to a Game definied by an instrument and a button space.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/
enum GameController
{
	GAME_CONTROLLER_1 = 0,	// left controller
	GAME_CONTROLLER_2,		// right controller
	MAX_GAME_CONTROLLERS,	// leave this at the end
	GAME_CONTROLLER_INVALID,
};

typedef int GameButton;

enum	// DanceButtons
{
	DANCE_BUTTON_LEFT,
	DANCE_BUTTON_RIGHT,
	DANCE_BUTTON_UP,
	DANCE_BUTTON_DOWN,
	DANCE_BUTTON_UPLEFT,
	DANCE_BUTTON_UPRIGHT,
	DANCE_BUTTON_START,
	DANCE_BUTTON_BACK,
	DANCE_BUTTON_MENULEFT,
	DANCE_BUTTON_MENURIGHT,
	DANCE_BUTTON_MENUUP,
	DANCE_BUTTON_MENUDOWN,
	NUM_DANCE_BUTTONS,		// leave this at the end
};

enum	// PumpButtons
{
	PUMP_BUTTON_UPLEFT,
	PUMP_BUTTON_UPRIGHT,
	PUMP_BUTTON_CENTER,
	PUMP_BUTTON_DOWNLEFT,
	PUMP_BUTTON_DOWNRIGHT,
	PUMP_BUTTON_START,
	PUMP_BUTTON_BACK,
	PUMP_BUTTON_MENULEFT,
	PUMP_BUTTON_MENURIGHT,
	PUMP_BUTTON_MENUUP,
	PUMP_BUTTON_MENUDOWN,
	NUM_PUMP_BUTTONS,		// leave this at the end
};

enum	// EZ2Buttons
{
	EZ2_BUTTON_FOOTUPLEFT,
	EZ2_BUTTON_FOOTUPRIGHT,
	EZ2_BUTTON_FOOTDOWN,
	EZ2_BUTTON_HANDUPLEFT,
	EZ2_BUTTON_HANDUPRIGHT,
	EZ2_BUTTON_HANDLRLEFT,
	EZ2_BUTTON_HANDLRRIGHT,
	EZ2_BUTTON_START,
	EZ2_BUTTON_BACK,
	EZ2_BUTTON_MENULEFT,
	EZ2_BUTTON_MENURIGHT,
	EZ2_BUTTON_MENUUP,
	EZ2_BUTTON_MENUDOWN,
	NUM_EZ2_BUTTONS,		// leave this at the end
};

enum	// ParaButtons
{
	PARA_BUTTON_LEFT,
	PARA_BUTTON_UPLEFT,
	PARA_BUTTON_UP,
	PARA_BUTTON_UPRIGHT,
	PARA_BUTTON_RIGHT,
	PARA_BUTTON_START,
	PARA_BUTTON_BACK,
	PARA_BUTTON_MENULEFT,
	PARA_BUTTON_MENURIGHT,
	PARA_BUTTON_MENUUP,
	PARA_BUTTON_MENUDOWN,
	NUM_PARA_BUTTONS,		// leave this at the end
};

enum // 3DDX Buttons
{
	DS3DDX_BUTTON_HANDLEFT,
	DS3DDX_BUTTON_FOOTDOWNLEFT,
	DS3DDX_BUTTON_FOOTUPLEFT,
	DS3DDX_BUTTON_HANDUP,
	DS3DDX_BUTTON_HANDDOWN,
	DS3DDX_BUTTON_FOOTUPRIGHT,
	DS3DDX_BUTTON_FOOTDOWNRIGHT,
	DS3DDX_BUTTON_HANDRIGHT,
	DS3DDX_BUTTON_START,
	DS3DDX_BUTTON_BACK,
	DS3DDX_BUTTON_MENULEFT,
	DS3DDX_BUTTON_MENURIGHT,
	DS3DDX_BUTTON_MENUUP,
	DS3DDX_BUTTON_MENUDOWN,
	NUM_DS3DDX_BUTTONS, // leave this at the end.
};

const GameButton MAX_GAME_BUTTONS = 14;
const GameButton GAME_BUTTON_INVALID = MAX_GAME_BUTTONS+1;



struct GameInput
{
	GameInput(): controller(GAME_CONTROLLER_INVALID), button(GAME_BUTTON_INVALID) { }

	GameInput( GameController c, GameButton b ): controller(c), button(b) { }

	GameController	controller;
	GameButton		button;

	bool operator==( const GameInput &other ) { return controller == other.controller && button == other.button; };

	inline bool IsValid() const { return controller != GAME_CONTROLLER_INVALID; };
	inline void MakeInvalid() { controller = GAME_CONTROLLER_INVALID; button = GAME_BUTTON_INVALID; };

	CString toString();
	bool fromString( CString s );
};



#endif
