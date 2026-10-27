#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool starts_with(const std::string& s, const std::string& prefix) {
	if (prefix.size() > s.size()) {
		return false;
	}
	return std::equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix) {
	if (suffix.size() > s.size()) {
		return false;
	}
	return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
	std::vector<std::string> files{
		"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md",
		"vjezba04.h", "notes.txt", "vjezba03.cpp"
	};

	auto cpp_count = std::count_if(files.begin(), files.end(),
		[](const std::string& f) { return ends_with(f, ".cpp"); });
	std::cout << ".cpp datoteka: " << cpp_count << std::endl;

	files.erase(std::remove_if(files.begin(), files.end(),
		[](const std::string& f) { return starts_with(f, "vjezba"); }),
		files.end());

	for (const std::string& f : files) {
		std::cout << f << ' ';
	}
	std::cout << std::endl;
}