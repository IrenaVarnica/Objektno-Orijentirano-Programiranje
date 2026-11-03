#include <iostream>
#include <string>

class Clip
{
	int start;
	int end;
	int length;
	std::string name;
	const int max_length = 600; // vrijednost const varijabli mora odmah pri inicijalizaciji bit recena

public:
	Clip(const std::string& name, int start, int end)
		: start(start), end(end), length(end - start), name(name) // name(name) je isto kao this->name
	{												// length(end-start) u originalnom kodu bi krenilo prije start
	}

	void print() const
	{
		std::cout << name << ": " << length << " s\n";
	}
};

int main()
{
	Clip c("Concrete (Shame)", 10, 190);
	c.print();
}