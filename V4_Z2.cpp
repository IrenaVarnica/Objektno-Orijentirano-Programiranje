#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Song {
	std::string title;
	std::string artist;
	int year;
	int plays;
};

void print_song(const Song& s) {
	std::cout << s.title << " - " << s.artist << " (" << s.year << "), "
		<< s.plays << " slusanja" << std::endl;
}

int main() {
	std::vector<Song> songs{
		{ "Ti si sav moj bol", "EKV", 1986, 10000 },
		{ "Ena", "Haustor", 1985, 19000 },
		{ "Zemlja", "EKV", 1987, 7000 },
		{ "Doci cu ti u snovima", "Jure Stublic", 1986, 12000 },
		{ "Djurdevdan", "Bijelo dugme", 1988, 25000 }
	};

	std::sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
		if (a.year != b.year) {
			return a.year < b.year;
		}
		return a.title < b.title;
		});

	std::cout << "Sortirano:" << std::endl;
	for (const Song& s : songs) {
		print_song(s);
	}

	std::string artist;
	std::cout << "Izvodac: ";
	std::getline(std::cin, artist);

	auto by_artist = [&artist](const Song& s) { return s.artist == artist; };

	auto count = std::count_if(songs.begin(), songs.end(), by_artist);
	if (count == 0) {
		std::cout << "Nema pjesama izvodaca " << artist << std::endl;
	}
	else {
		auto oldest = std::find_if(songs.begin(), songs.end(), by_artist);
		std::cout << "pjesama: " << count << std::endl;
		std::cout << "najstarija: ";
		print_song(*oldest);
	}

	auto most_played = std::max_element(songs.begin(), songs.end(),
		[](const Song& a, const Song& b) { return a.plays < b.plays; });
	std::cout << "najslusanija: ";
	print_song(*most_played);
}