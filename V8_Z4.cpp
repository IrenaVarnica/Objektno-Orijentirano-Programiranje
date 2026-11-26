#include <iostream>
#include <string>
#include <vector>

class Item {
	std::string title;
public:
	Item(const std::string& t) : title(t) {}
	virtual ~Item() {};
	virtual void print() const { std::cout << title; }
};

class Book : public Item {
	std::string author;
public:
	Book(const std::string& t, const std::string& a) : Item(t), author(a) {}
	void print() const override {
		Item::print();
		std::cout << " (" << author << ')';
	}
};

class Film : public Item {
	int minutes;
public:
	Film(const std::string& t, int m) : Item(t), minutes(m) {}
	void print() const override {
		Item::print();
		std::cout << " [" << minutes << " min]";
	}
};


class Member {
	std::string name;
	std::vector<Item*> items;
public:
	Member(const std::string& n) : name(n) {}

	void receive(Item* it) { items.push_back(it); }
	Item* release(std::size_t i) {       
		Item* it = items[i];
		items.erase(items.begin() + i);
		return it;
	}
	std::size_t size() const {
		return items.size(); 
	}

	void print() const {
		std::cout << name << ':';
		for (const Item* it : items) {
			std::cout << ' ';
			it->print();
		}
		std::cout << '\n';
	}
};

class Library {
	std::vector<Item*> items;
public:
	void add(Item* it) { items.push_back(it); }

	bool lend(std::size_t i, Member& m) {
		if (i >= items.size())
			return false;
		m.receive(items[i]);              
		items.erase(items.begin() + i);
		return true;
	}

	bool take_back(Member& m, std::size_t i) {
		if (i >= m.size())
			return false;
		items.push_back(m.release(i));      
		return true;
	}

	void print() const {
		std::cout << "knjiznica:";
		for (const Item* it : items) {
			std::cout << ' ';
			it->print();
		}
		std::cout << '\n';
	}
};

int main()
{
	Book dune("Dina", "Frank Herbert");
	Film dune_film("Dina", 155);
	Book odyssey("2001: Odiseja u svemiru", "Arthur C. Clarke");

	Library lib;
	lib.add(&dune);
	lib.add(&dune_film);
	lib.add(&odyssey);
	lib.print();

	Member ana("Ana");
	lib.lend(1, ana);
	std::cout << lib.lend(5, ana) << '\n';
	lib.print();
	ana.print();

	lib.take_back(ana, 0);
	lib.print();
	ana.print();
	return 0;
}

/*
Ocekivani ispis:

	knjiznica: Dina (Frank Herbert) Dina [155 min] 2001: Odiseja u svemiru (Arthur C. Clarke)
	0
	knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke)
	Ana: Dina [155 min]
	knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke) Dina [155 min]
	Ana:
*/