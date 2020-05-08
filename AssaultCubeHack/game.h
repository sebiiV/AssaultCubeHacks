#pragma once

#include <Windows.h>
#include "proc.h"
#include "offsets.h"
#include "matrix.h"

class Game
{
public:

	// Window information
	HANDLE hProcess = 0;
	DWORD procID = 0;

	// useful pointers
	uintptr_t moduleBase;
	uintptr_t p_player;
	uintptr_t p_entitylist;
	uintptr_t p_viewMatrix;

	// Game state info
	unsigned int i_player_no = 0;
	Viewmatrix view;
	int gameWidth;
	int gameHeight;

	Game(const wchar_t* application_name);
	unsigned int getPlayerCount();
	void updateViewMatrix();
	
};

