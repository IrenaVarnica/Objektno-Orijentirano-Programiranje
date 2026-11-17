#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Vec2 {
	int x, y;

	Vec2& operator+=(const Vec2& o) { x += o.x; y += o.y; return *this; }
	Vec2& operator-=(const Vec2& o) { x -= o.x; y -= o.y; return *this; }
};

Vec2 operator+(Vec2 a, const Vec2& b) { return a += b; }
Vec2 operator-(Vec2 a, const Vec2& b) { return a -= b; }
Vec2 operator*(Vec2 v, int k) { return { v.x * k, v.y * k }; }
Vec2 operator*(int k, Vec2 v) { return v * k; }
bool operator==(const Vec2& a, const Vec2& b) { return a.x == b.x && a.y == b.y; }
bool operator!=(const Vec2& a, const Vec2& b) { return !(a == b); }
std::ostream& operator<<(std::ostream& out, const Vec2& v)
{
	return out << '(' << v.x << ", " << v.y << ')';
}


struct Enemy {
	std::string name;
	Vec2 pos;
};


class InRange {
	Vec2 center;
	int range;
public:
	InRange(Vec2 c, int r) : center(c), range(r) {}
	bool operator()(const Enemy& e) const {
		Vec2 d = e.pos - center;
		return d.x * d.x + d.y * d.y <= range * range;
	}
};


int main()
{
	std::vector<Enemy> enemies = {
		{ "Goblin",{ 2, 2 } },{ "Troll",{ 6, 1 } },{ "Bat",{ 3, 5 } },
		{ "Ghost",{ 0, 0 } },{ "Slime",{ 7, 7 } }
	};
	Vec2 player{ 3, 3 };

	InRange near(player, 2);                                         
	std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n'; 

	std::cout << std::count_if(enemies.begin(), enemies.end(), InRange(player, 2)) << '\n';
	int range = 2;

	std::cout << std::count_if(enemies.begin(), enemies.end(),
		[&](const Enemy& e) {
			Vec2 d = e.pos - player;
			return d.x * d.x + d.y * d.y <= range * range;
		})	<< '\n';
	return 0;
}
