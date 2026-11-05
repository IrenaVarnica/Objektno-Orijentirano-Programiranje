#define _CRT_SECURE_NO_WARNINGS    
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

class LogFile {
private:
	std::FILE* file;

public:
	
	LogFile(const std::string& name) {
		file = std::fopen(name.c_str(), "a");
	}

	~LogFile() {
		if (file != nullptr) {
			std::fclose(file);
		}
	}

	void write(const std::string& line) {
		std::fputs(line.c_str(), file);
		std::fputs("\n", file);
	}

	LogFile(const LogFile&) = delete;
	LogFile& operator=(const LogFile&) = delete;
};

int log_songs(const std::vector<std::string>& titles) {
	LogFile log("played.log");

	int count = 0;
	for (const std::string& title : titles) {
		if (title == "STOP") {
			return count;
		}

		log.write(title);
		count++;
	}

	return count;
}

int main()
{
	std::remove("played.log");
	int n = log_songs({ "Superhero", "Sports", "STOP", "Matador" });
	std::cout << n << '\n';

	std::cout << log_songs({ "One Rizla" }) << '\n';

	std::FILE* f = std::fopen("played.log", "r");
	char line[100];

	while (std::fgets(line, sizeof line, f))
		std::cout << line;

	std::fclose(f);

	return 0;
}