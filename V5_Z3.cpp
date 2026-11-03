#include <iostream>
#include <string>
#include <vector>

struct Song
{
	std::string title;
	std::string artist;
	int seconds;
};

class Album
{
	std::string title;
	int year;
	std::vector<Song> songs;

public:
	Album(const std::string& t, int y, const Song& first)
		: title(t), year(y)
	{
		songs.push_back(first);
	}

	bool add(const Song& s)
	{
		for (const Song& existing : songs)
		{
			if (existing.title == s.title)
			{
				return false;
			}
		}
		songs.push_back(s);
		return true;
	}

	int duration() const
	{
		int total = 0;
		for (const Song& s : songs)
		{
			total += s.seconds;
		}
		return total;
	}

	void print() const
	{
		int d = duration();
		int sec = d % 60;
		std::cout << title << " (" << year << "), " << songs.size() << " pjesme, "
			<< d / 60 << ':' << (sec < 10 ? "0" : "") << sec << '\n';
		for (std::size_t i = 0; i < songs.size(); ++i)
		{
			std::cout << "  " << i + 1 << ". " << songs[i].title << '\n';
		}
	}
};

int main()
{
	Album a("Sol Invictus", 2015, { "Sol Invictus", "Faith No More", 156 });
	a.add({ "Superhero", "Faith No More", 315 });
	a.add({ "Matador", "Faith No More", 368 });
	std::cout << a.add({ "Superhero", "Faith No More", 315 }) << '\n';
	a.print();
	return 0;
}
