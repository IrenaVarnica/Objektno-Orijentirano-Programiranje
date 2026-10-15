#include <iostream>
#include <string>
bool split_email(const std::string& email, std::string& user, std::string& domain) {
	
	auto zadnji = email.rfind("@");
	auto prvi = email.find("@");
	auto duljina = email.length();

	if (prvi == std::string::npos) {
		std::cout << "nema @!";
		return false;
	};
	
	if (email.find(".") == std::string::npos) {
		std::cout << "nema tocke!";
		return false;
	};

	if (zadnji != prvi) {
		std::cout << "previse @!";
		return false;
	};

	if (email.find_first_of("@") == 0) {
		std::cout << "ne @ na pocetku!";
		return false;
	};

	if (email.find_first_of("@") == zadnji) {
		std::cout << "ne @ na kraju!";
		return false;
	};

	domain.substr(prvi, duljina);
	user.substr(0, prvi);
	return true;
};
	

int main() {
	std::string email;
	std::string user;
	std::string domain;
	std::cout << "unesite email" << std::endl;
	std::getline(std::cin, email);


	split_email(email, user, domain);

	std::cout << "email" << email << std::endl;
	std::cout << "user" << user << std::endl;
	std::cout << "domain" << domain << std::endl;

	return 0;
}