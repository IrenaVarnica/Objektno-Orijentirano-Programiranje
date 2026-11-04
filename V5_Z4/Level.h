#pragma once    

#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level {
	std::vector<Enemy> enemies;
	std::vector<Weapon> weapons;   

public:
	Level(const Enemy& first_enemy);
	int enemy_count() const;
	int weapon_count() const;
};
