#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
	std::string* buf;
	int cap;
	int count;
	int next;
public:
	RecentlyPlayed(int capacity) : buf(nullptr), cap(capacity), count(0), next(0) {
		assert(capacity > 0);
		buf = new std::string[capacity];
	}
	RecentlyPlayed(const RecentlyPlayed& o)
		: buf(new std::string[o.cap]), cap(o.cap), count(o.count), next(o.next) {
		for (int i = 0; i < cap; ++i) buf[i] = o.buf[i];
	}
	~RecentlyPlayed() { delete[] buf; }

	void play(const std::string& title) {
		buf[next] = title;
		next = (next + 1) % cap;
		if (count < cap) ++count;
	}
	int size() const { return count; }
	int capacity() const { return cap; }
	std::string get(int i) const {
		assert(i >= 0 && i < count);
		return buf[((next - 1 - i) % cap + cap) % cap];
	}
	void print() const {
		for (int i = 0; i < count; ++i) {
			if (i > 0) std::cout << ", ";
			std::cout << get(i);
		}
		std::cout << '\n';
	}
};

int main()
{
	RecentlyPlayed recent(3);
	recent.play("Heroes");
	recent.play("Literary Mind");
	std::cout << recent.size() << ' ' << recent.capacity() << '\n';
	recent.play("Sports");
	recent.print();
	recent.play("Henry Don't Got Love");
	recent.print();

	RecentlyPlayed copy = recent;
	recent.play("Guided by Angels");
	recent.print();
	copy.print();
	std::cout << copy.get(0) << '\n';
	return 0;
}

/*
Ocekivani ispis:

	2 3
	Sports, Literary Mind, Heroes
	Henry Don't Got Love, Sports, Literary Mind
	Guided by Angels, Henry Don't Got Love, Sports
	Henry Don't Got Love, Sports, Literary Mind
	Henry Don't Got Love
*/
