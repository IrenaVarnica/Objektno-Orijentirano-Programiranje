#include "Level.h"


Level::Level(const Enemy& first_enemy)
{
	enemies.push_back(first_enemy);     
}

int Level::enemy_count() const
{
	return static_cast<int>(enemies.size());
}

int Level::weapon_count() const
{
	return static_cast<int>(weapons.size());
}

