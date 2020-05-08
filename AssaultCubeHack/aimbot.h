#define _USE_MATH_DEFINES

#include <vector>
#include <math.h>
#include "offsets.h"
#include "player.h"
#include "vector2.h"
#include "game.h"


class Aimbot {
public:
	void update(Game &game,std::vector<Player> &players,Player &hacker);
private:
	Player* getClosestEnemyToCrosshair(Game &game, std::vector<Player> &players);
};

