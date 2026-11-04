#include <iostream>
#include "Player.h"

Player::Player(const std::string& name, Level& level) : name(name), level(level)
{
}



void Player::print() const
{
	std::cout << "Igrac: " << name << '\n';
	std::cout << "Level: neprijatelja " << level.enemy_count()
		<< ", oruzja " << level.weapon_count() << '\n';
}
