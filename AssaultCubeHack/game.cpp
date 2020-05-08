#include "game.h"

#include <iostream>



Game::Game(const wchar_t* application_name) {
	this->procID = GetProcID(application_name);
	this->moduleBase = GetModuleBaseAddress(procID, application_name);
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procID);		// This is a really easy way to get caught...

	this->p_viewMatrix = moduleBase + view_matrix_offset;
	this->p_player = moduleBase + player_offset;
	this->p_entitylist = moduleBase + entity_list_offset;
	this->view;

	//lets calculate window size
	// Annoyingly requires a different type of handle
	RECT screen;
	HWND windowHandle = FindWindow(NULL, applicationName);
	if (GetClientRect(windowHandle, &screen)) {
		this->gameHeight = screen.bottom - screen.top;
		this->gameWidth = screen.right - screen.left; 
	}
	else {
		std::cout << "Failed to get window size" << std::endl;
		exit(1);
	}

}

unsigned int Game::getPlayerCount() {
	ReadProcessMemory(hProcess, (BYTE*)p_player+number_of_player_offset, &i_player_no, sizeof(i_player_no), nullptr);
	return i_player_no;
}

void Game::updateViewMatrix() {
	char buf[sizeof(view.matrix)];		
	ReadProcessMemory(hProcess, (BYTE*)p_viewMatrix, &buf, sizeof(buf), nullptr);
	view = *((Viewmatrix*)&buf);

	#ifdef DEBUG
		view.debugString();
	#endif // DEBUG

}
