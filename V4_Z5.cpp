#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Student {
	std::string jmbag;
	std::string surname;
	int points;
};

int main() {
	std::vector<Student> registered{
		{ "0302", "Kovac", 78 },{ "0117", "Babic", 45 },
		{ "0255", "Maric", 91 },{ "0117", "Babic", 45 },
		{ "0410", "Novak", 78 },{ "0089", "Juric", 62 },
		{ "0255", "Maric", 91 },{ "0520", "Maric", 55 },
		{ "0333", "Peric", 30 }
	};

	std::sort(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) { return a.jmbag < b.jmbag; });

	registered.erase(std::unique(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) { return a.jmbag == b.jmbag; }),
		registered.end());

	std::cout << "prijavljenih: " << registered.size() << std::endl;

	int threshold{};
	std::cout << "Prag: ";
	std::cin >> threshold;

	registered.erase(std::remove_if(registered.begin(), registered.end(),
		[threshold](const Student& s) { return s.points < threshold; }),
		registered.end());

	std::sort(registered.begin(), registered.end(),
		[](const Student& a, const Student& b) {
			if (a.points != b.points) {
				return a.points > b.points;
			}
			return a.surname < b.surname;
		});

	int rank{ 1 };
	for (const Student& s : registered) {
		std::cout << rank++ << ". " << s.surname << " (" << s.jmbag << ") "
			<< s.points << std::endl;
	}
}