#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::string clean(const std::string& word)
{
	std::string result;
	for (unsigned char ch : word)
		if (std::isalpha(ch))
			result += static_cast<char>(std::tolower(ch));
	return result;
}

struct WordCount {
	std::string word;
	int count;
};

int main()
{
	std::ifstream in("tekst.txt");
	if (!in) {
		std::cout << "Datoteka tekst.txt ne postoji\n";
		return 1;
	}

	std::map<std::string, int> freq;
	std::string raw;
	while (in >> raw) {
		std::string w = clean(raw);
		if (w.empty())
			continue;                 
		++freq[w];
	}

	std::cout << "razlicitih rijeci: " << freq.size() << '\n';
	std::cout << "alice: " << freq["alice"] << '\n';

	std::vector<WordCount> words;
	for (const auto& p : freq)
		words.push_back({ p.first, p.second });

	std::sort(words.begin(), words.end(), [](const WordCount& a, const WordCount& b) {
		if (a.count != b.count)
			return a.count > b.count;  
		return a.word < b.word;      
		});

	for (std::size_t i = 0; i < 5 && i < words.size(); ++i)
		std::cout << words[i].word << ": " << words[i].count << '\n';
	return 0;
}