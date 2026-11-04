#pragma once     

#include <string>

class Weapon {
	std::string name;
	int damage;

public:
	Weapon(const std::string& name, int damage);
};
