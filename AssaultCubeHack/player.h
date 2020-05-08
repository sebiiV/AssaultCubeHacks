#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>

#include "offsets.h"
#include "proc.h"
#include "vector3.h"
#include "game.h"

class Player {

public:
	unsigned int playerID; //always in increments of 4
	HANDLE hProcess;
	uintptr_t p_entity;
	std::string name;

	Vector3 headPos;
	Vector3 footPos;

	Player(unsigned int ID,HANDLE hProcess,uintptr_t p_entity);

	std::string getName();
	Vector3 getHeadPos();
	Vector3 getFootPos();

	void setPitch(float pitch);
	void setYaw(float yaw);


	
};