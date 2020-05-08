// AssaultCubeHack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <windows.h>
#include <string>

#include "proc.h"

#include "offsets.h"
#include "game.h"
#include "aimbot.h"


int main()
{
	std::cout << "Assault Cube Hack" << std::endl;
	std::cout << "=================" << std::endl;

	// Lets initialize all our handles and such
	Game game(application);
	Aimbot aimbot;

	//this is you, you cheater
	Player hacker(0,game.hProcess,game.p_player);

	//These are the scrubs
	std::vector<Player> players;


	//int i = game.getPlayerCount();


	// instantiate all the player objects
	for (unsigned int i = 4; i < game.getPlayerCount() * 4; i += 4) { //Increment by 4 as, 4 byte pointers
		Player temp(i,game.hProcess,game.p_entitylist);
		players.push_back(temp);
	}

	//print out all the player names
	for (unsigned int i = 0; i < players.size(); ++i) {
		std::cout << "name: " << players[i].getName() << std::endl;
	}

	// the hack loop
	while (!(GetAsyncKeyState(VK_DELETE)))
	{

		//aimbot if ctrl is down
		if (GetKeyState(VK_CONTROL) & 0x8000)
		{
			game.updateViewMatrix();
			aimbot.update(game, players, hacker);
		}
	}

		return 0;
}
