#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain) {

	auto zadnji = email.rfind("@");
	auto prvi = email.find("@");

	if (prvi == std::string::npos) {
		std::cout << "nema @!" << std::endl;
		return false;
	};

	if (zadnji != prvi) {
		std::cout << "previse @!" << std::endl;
		return false;
	};

	if (prvi == 0) {
		std::cout << "ne @ na pocetku!" << std::endl;
		return false;
	};

	if (prvi == email.size() - 1) {
		std::cout << "ne @ na kraju!" << std::endl;
		return false;
	};

	if (email.find('.', prvi) == std::string::npos) {
		std::cout << "nema tocke u domeni!" << std::endl;
		return false;
	}



	domain = email.substr(prvi + 1);
	user = email.substr(0, prvi);
	return true;
};


int main() {
	std::string email;
	std::string user;
	std::string domain;
	std::cout << "unesite email" << std::endl;
	std::getline(std::cin, email);


	if (split_email(email, user, domain)) {
		std::cout << "email: " << email << std::endl;
		std::cout << "user: " << user << std::endl;
		std::cout << "domain: " << domain << std::endl;
	}

	return 0;
}
