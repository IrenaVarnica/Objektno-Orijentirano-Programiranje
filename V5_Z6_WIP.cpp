#include <iostream>

class Coin {
	int value;
	static int coin_counter;
public:
	Coin(const int value) : value(value) {
		++coin_counter;
	}

	~Coin() {
		--coin_counter;
	}

	static int remaining() {
		return coin_counter;
	}
};

void bonus()             
{
	Coin c1(5);
	Coin c2(5);
	Coin c3(10);
	std::cout << Coin::remaining() << '\n';
}

int main()
{
	std::cout << Coin::remaining() << '\n';
	Coin gold(50);
	{
		Coin a(1);
		Coin b(1);
		std::cout << Coin::remaining() << '\n';
	}
	std::cout << Coin::remaining() << '\n';
	bonus();
	std::cout << Coin::remaining() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	0
	3
	1
	4
	1
*/
