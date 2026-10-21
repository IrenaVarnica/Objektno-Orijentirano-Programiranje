#include <iostream>
#include <string>

std::string with_separators(std::string digits) {

	auto start = (digits[0] == '-') ? 1 : 0;
	for (int i = digits.size() - 3; i > start; i -= 3) {
		digits.insert(i, ".");
	}

	return digits;
}

std::string without_separators(std::string text) {
	auto dot_finder = text.find('.');
	while (dot_finder != std::string::npos) {
		text.erase(dot_finder,1);
		dot_finder = text.find('.', dot_finder);
	}
	return text;
}

int main() {
	std::string text;
	std::cout << "Unesite brojke: ";
	std::cin >> text;
	std::cin.ignore();
	
	std::cout << "String s tockama: " << with_separators(text) << std::endl;

	std::cout << "String bez tocki: " << without_separators(text) << std::endl;

	return 0;
}