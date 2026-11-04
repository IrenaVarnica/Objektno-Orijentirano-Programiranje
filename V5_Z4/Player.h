#pragma once   

#include <string>
#include "Level.h"

class Player {
	std::string name;

	Level& level;

public:
	Player(const std::string& name, Level& level);
	void print() const;     
};
