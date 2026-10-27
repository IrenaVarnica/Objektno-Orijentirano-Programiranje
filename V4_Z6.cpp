#include <algorithm>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split_words(const std::string& text) {
	std::vector<std::string> words;
	std::istringstream iss(text);
	std::string w;
	while (iss >> w) {
		words.push_back(w);
	}
	return words;
}

int main() {
	std::vector<std::string> dictionary{
		"programski", "jezik", "c++", "je", "brz", "i", "mocan",
		"ali", "nije", "jednostavan", "za", "pocetnike"
	};
	std::sort(dictionary.begin(), dictionary.end());

	std::string sentence;
	std::cout << "Recenica: ";
	std::getline(std::cin, sentence);

	std::vector<std::string> unknown;
	for (std::string word : split_words(sentence)) {
		word.erase(std::remove_if(word.begin(), word.end(),
			[](char c) { return c == ',' || c == '.'; }),
			word.end());

		std::transform(word.begin(), word.end(), word.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (word.empty()) {
			continue;
		}
		if (!std::binary_search(dictionary.begin(), dictionary.end(), word)) {
			unknown.push_back(word);
		}
	}

	std::cout << "nepoznatih rijeci: " << unknown.size();
	for (const std::string& w : unknown) {
		std::cout << ' ' << w;
	}
	std::cout << std::endl;
}