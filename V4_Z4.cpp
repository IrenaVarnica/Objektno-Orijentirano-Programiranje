#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

struct PasswordInfo {
	int length;
	int digits;
	int uppercase;
	int special;
};

PasswordInfo analyze(const std::string& password) {

	PasswordInfo info{};
	info.length = (int)password.size();
	info.digits = std::count_if(password.begin(), password.end(), [](char c) {
		return std::isdigit(c);
	});
	info.uppercase = std::count_if(password.begin(), password.end(), [](char c) {
		return std::isupper(c);
	});
	info.special = std::count_if(password.begin(), password.end(), [](char c) {
		return std::ispunct(c);
	});

	return info;
};

bool is_strong(const PasswordInfo& info) {
	return info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1;
};

int main() {
	std::string pass_word;
	std::cout << "unesite lozinku" << std::endl;
	std::cin >> pass_word;
	std::cin.ignore();

	auto result = analyze(pass_word);
	std::cout << "duljina: " << result.length << ",";
	std::cout << "znamenke: " << result.digits << ",";
	std::cout << "velika slova: " << result.uppercase << ",";
	std::cout << "posebni znakovi: " << result.special << ".";
	std::cout << std::endl;

	is_strong(result) ? (std::cout << "Imas snaznu lozinku! :D") : (std::cout << "Slaba ti je lozinka :P");
	std::cout << std::endl;
};