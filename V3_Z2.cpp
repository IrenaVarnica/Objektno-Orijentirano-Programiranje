#include <iostream>
#include <vector>


int main() {
	int n;
	std::cout << "Unesite broj dana " << std::endl;
	std::cin >> n;

	std::cin.ignore();

	std::vector<double> temperatures(n);

	for (int i{ 0 };i < n;i++) {
		std::cout << "Koja temperatura na " << i + 1 << ". dan?" << std::endl;
		std::cin >> temperatures[i];
	}

	std::vector<double> changes;
	changes.reserve(n-1);

	for (std::vector<double>::iterator iter = temperatures.begin() + 1;iter != temperatures.end();iter++) {
		changes.push_back(*iter - *(iter - 1));
	}



	std::cout << "Broj dana: " << n << std::endl;

	std::cout << "Temperature: " << std::endl;
	for (int i{ 0 };i < n;i++) {
		std::cout << temperatures[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Promjene: " << std::endl;
	for (int i{ 0 };i < n-1;i++) {
		std::cout << changes[i] << " ";
	}
	std::cout << std::endl;

	temperatures.resize(7, temperatures.back());

	std::cout << "Izvjestaj:";
	for (std::vector<double>::iterator iter = temperatures.begin(); iter != temperatures.end(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	return 0;
}