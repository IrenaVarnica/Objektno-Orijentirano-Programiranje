#include <iostream>
#include <string>
#include <vector>

class Enemy {
	std::string name;
	int x, y;
	int health = 100;
public:
	Enemy(const std::string& n, int x, int y) : name(n), x(x), y(y) {}
	std::string get_name() const { return name; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_health() const { return health; }
	bool is_alive() const { return health > 0; }
	void move(int dx, int dy) { x += dx; y += dy; }
	void take_damage(int d) { health = (d >= health) ? 0 : health - d; }
};

class Level {
	int rows, cols;
	std::vector<Enemy> enemies;
	bool inside(int x, int y) const { return x >= 0 && x < cols && y >= 0 && y < rows; }
public:
	Level(int r, int c) : rows(r), cols(c) {}
	bool add(Enemy e) {
		if (!inside(e.get_x(), e.get_y())) return false;
		enemies.push_back(e);
		return true;
	}
	void step(int dx, int dy) {
		for (Enemy& e : enemies)
			if (inside(e.get_x() + dx, e.get_y() + dy))
				e.move(dx, dy);
	}
	void print() const {
		for (const Enemy& e : enemies)
			std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ") "
			<< e.get_health() << '\n';
	}
};

int main()
{
	Level cave(5, 10);
	cave.add(Enemy("Gnome", 1, 1));
	std::cout << cave.add(Enemy("Troll", 8, 3))
		<< cave.add(Enemy("Bat", 12, 2)) << '\n';
	cave.step(1, 1);
	cave.print();
	cave.step(1, 1);
	cave.print();
	return 0;
}

/*
Ocekivani ispis:

	10
	Gnome (2, 2) 100
	Troll (9, 4) 100
	Gnome (3, 3) 100
	Troll (9, 4) 100
*/