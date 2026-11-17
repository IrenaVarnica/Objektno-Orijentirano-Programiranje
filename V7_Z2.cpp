#include <fstream>
#include <iostream>
#include <string>

class Money {
	int cents;                      
public:
	Money(int euros = 0, int c = 0) : cents(euros * 100 + c) {}
	int get_cents() const { return cents; }
	Money& operator+=(const Money& o) { cents += o.cents; return *this; }
};

Money operator+(Money a, const Money& b) { return a += b; }
bool operator<(const Money& a, const Money& b) { return a.get_cents() < b.get_cents(); }

std::ostream& operator<<(std::ostream& out, const Money& m)
{
	int c = m.get_cents();
	out << c / 100 << '.' << (c % 100 < 10 ? "0" : "") << c % 100 << " EUR";
	return out;
}

std::istream& operator>>(std::istream& in, Money& m)
{
	int euros = 0, cents = 0;
	char dot = 0;
	if (!(in >> euros >> dot >> cents))
		return in;                   
	if (dot != '.') {
		in.setstate(std::ios::failbit);
		return in;
	}
	m = Money(euros, cents);
	return in;
}


int main()
{
	Money a(1, 5);
	Money b(0, 95);
	std::cout << a << " + " << b << " = " << a + b << '\n';

	std::ifstream in("racun.txt");
	if (!in) {
		std::cout << "Datoteka racun.txt ne postoji\n";
		return 1;
	}

	std::string item;
	Money price;
	Money total;
	Money max_price;
	std::string max_item;
	int count = 0;
	while (in >> item >> price) {
		total += price;
		if (max_price < price) {
			max_price = price;
			max_item = item;
		}
		++count;
	}
	if (!in.eof())
		std::cout << "Neispravan zapis: " << item << '\n';

	std::cout << "Stavki: " << count << '\n';
	std::cout << "Ukupno: " << total << '\n';
	std::cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
	return 0;
}

/*
Ocekivani ispis:

	1.05 EUR + 0.95 EUR = 2.00 EUR
	Neispravan zapis: Sok
	Stavki: 5
	Ukupno: 17.23 EUR
	Najskuplje: Kava 7.99 EUR
*/