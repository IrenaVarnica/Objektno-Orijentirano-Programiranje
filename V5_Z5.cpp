
#include <iostream>
#include <string>

class Ticket {
	std::string naziv;
	int id;
	static int next_id;

public:
	Ticket(const std::string& str) : naziv(str), id(next_id++) {}
	int get_id() const { return id; }
	static auto issued() {
		return next_id;
	}

};

int Ticket::next_id = 0;

int main()
{
	std::cout << Ticket::issued() << '\n';
	Ticket t1("Shame, Zagreb");
	Ticket t2("Shame, Zagreb");
	Ticket t3("Viagra Boys, Ljubljana");
	std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
	std::cout << Ticket::issued() << '\n';
	return 0;
}

