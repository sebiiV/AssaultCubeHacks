#include "aimbot.h"

/*
We are looking for the Model view projection matrix

Matrix is a 4x4 array of floats
Left | Up | Forward | Translation

Pitch -90  + 90 -- Down is negative
Yaw   -180 + 180 

NEVER GO TO MAXIMUM PITCH OR YAW!

*/

void Aimbot::update(Game &game,std::vector<Player> &players,Player &hacker){
	//Is there an avaliable target near to us
	Player* target = getClosestEnemyToCrosshair(game,players);
	if (target != nullptr) {
		std::cout << "targetID: " << target->playerID << std::endl;

		//resolve health pointer chain
		unsigned int a = target->playerID;

		// lets get the horizontal and vertical distance
		float dx = target->getFootPos().x - hacker.getFootPos().x;
		float dy = target->getFootPos().y - hacker.getFootPos().y;

		//calculate horizontal angle (yaw)
		double angleYaw = atan2(dy, dx) * 180 / M_PI;
		
		//Calcualte verticle angle (pitch)
		double distance = sqrt(dx * dx + dy * dy);
		float dz = target->getFootPos().z - hacker.getFootPos().z;
		double anglePitch = atan2(dz, distance) * 180 / M_PI;

		hacker.setYaw((float)angleYaw + 90);
		hacker.setPitch((float)anglePitch);
	}
}

Player* Aimbot::getClosestEnemyToCrosshair(Game &game, std::vector<Player> &players)
{
	//find first living player in view
	int closestPlayerIndex = -1;
	float dist = 999999999999999;
	for (unsigned int i = 0; i < players.size(); ++i) {
		Vector2 targetPos(0,0);
		//TODO: checks that the other player isn't dead and on the other team
		bool visible = game.view.WorldToScreen(players[i].getHeadPos(),game.gameWidth,game.gameHeight, targetPos);

		if (visible == true) {
			//calculate distance to crosshair
			Vector2 crossHair(game.gameWidth / 2, game.gameHeight / 2);
			float newDist = crossHair.distance(targetPos);
			if (newDist < dist) {
				closestPlayerIndex = i;
				dist = newDist;
			}
		}
	}
	if (closestPlayerIndex != -1) {
		return &players[closestPlayerIndex];
	}
	else {
		return nullptr;
	}
}

