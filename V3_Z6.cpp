#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text) {
	std::vector<std::string> words;
	auto start = text.find_first_not_of(' ');

	while (start != std::string::npos) {
		auto end = text.find(' ', start);
		if (end == std::string::npos) {
			words.push_back(text.substr(start));
			break;
		}
		words.push_back(text.substr(start, end - start));
		start = text.find_first_not_of(' ', end);
	}
	return words;
}

int main() {
	std::string sentence;
	std::cout << "Unesite recenicu: ";
	std::getline(std::cin, sentence);

	std::vector<std::string> words = split_words(sentence);

	std::string longest = words[0];
	for (const std::string& w : words) {
		if (w.size() > longest.size()) {
			longest = w;
		}
	}
	std::cout << "Broj rijeci: " << words.size() << std::endl;
	std::cout << "Najdulja rijec: " << longest << std::endl;


	std::string reversed;
	for (int i = (int)words.size() - 1; i >= 0; i--) {
		reversed += words[i];
		if (i > 0) {
			reversed += "-";
		}
	}
	std::cout << "Obrnuto: " << reversed << std::endl;


	std::string first = words[0];
	for (const std::string& w : words) {
		if (w < first) {
			first = w;
		}
	}
	std::cout << "Prva po abecedi: " << first << std::endl;

	return 0;
}