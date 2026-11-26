#include <iostream>
#include <string>
#include <vector>

class Enemy {
	std::string name;
	int health;
public:
	Enemy(const std::string& nejm, int helf) : name(nejm), health(helf) {}

	virtual ~Enemy() { 
		std::cout << name << " nestaje\n"; 
	} 

	virtual void take_damage(int d) { 
		health -= d;
	}

	const std::string& get_name() const { 
		return name; 
	}

	int get_health() const { 
		return health; 
	}
};

class Goblin : public Enemy {
public:
	Goblin() : Enemy("Goblin", 20) {}
};

class Bat : public Enemy {
	bool evade = false;         
public:
	Bat() : Enemy("Bat", 15) {}
	void take_damage(int d) override {
		if (evade) {
			std::cout << get_name() << " izbjegne udarac\n";
			evade = false;
		}
		else {
			Enemy::take_damage(d);
			evade = true;
		}
	}
};

class Ghost : public Enemy {
public:
	Ghost() : Enemy("Ghost", 30) {}
	void take_damage(int d) override { 
		Enemy::take_damage(d / 2);
	}  
};

class Level {
	std::vector<Enemy*> enemy_list;     
public:

	Level() {};

	Level(const Level&) = delete;            
	Level& operator=(const Level&) = delete;

	~Level() {
		for (Enemy* e : enemy_list)
			delete e;
	}

	void add(Enemy* e) {
		enemy_list.push_back(e);
	}

	auto size() const { 
		return enemy_list.size();
	}

	void explode(int d) {
		for (Enemy* e : enemy_list)
			e->take_damage(d);          
	}

	void remove_dead() {
		for (std::size_t i = 0; i < enemy_list.size(); ) {
			if (enemy_list[i]->get_health() <= 0) {
				delete enemy_list[i];
				enemy_list.erase(enemy_list.begin() + i);
			}
			else {
				++i;
			}
		}
	}

	void print() const {
		for (const Enemy* e : enemy_list)
			std::cout << e->get_name() << ' ' << e->get_health() << '\n';
	}
};

int main()
{
	Level cave;
	cave.add(new Goblin);       
	cave.add(new Bat);
	cave.add(new Ghost);
	cave.add(new Goblin);
	std::cout << cave.size() << '\n';

	cave.explode(10);                
	cave.print();
	std::cout << "---\n";
	cave.explode(10);
	cave.print();
	std::cout << "---\n";
	cave.remove_dead();
	std::cout << cave.size() << '\n';
	std::cout << "--- kraj ---\n";
	return 0;                        
}

/*
Ocekivani ispis:

	4
	Goblin 10
	Bat 5
	Ghost 25
	Goblin 10
	---
	Bat izbjegne udarac
	Goblin 0
	Bat 5
	Ghost 20
	Goblin 0
	---
	Goblin nestaje
	Goblin nestaje
	2
	--- kraj ---
	Bat nestaje
	Ghost nestaje
*/