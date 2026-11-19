#include <iostream>
#include <string>
#include <vector>

class Vehicle {
protected:
	std::string name;
	double kilometers;
	double fuel_consumption;

public:
	Vehicle(std::string n, double km, double consumption)
		: name(n), kilometers(km), fuel_consumption(consumption) {}

	virtual double consumption() const {
		return fuel_consumption;
	}

	double fuel() const {
		return kilometers * consumption() / 100;
	}

	virtual void print() const {
		std::cout << name << ": " << fuel() << " l";
	}

	virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
	bool eco;

public:
	Car(std::string n, double km, double consumption, bool e)
		: Vehicle(n, km, consumption), eco(e) {}

	double consumption() const override {
		if (eco)
			return fuel_consumption * 0.8;

		return fuel_consumption;
	}
};

class Truck : public Vehicle {
private:
	double load;

public:
	Truck(std::string n, double km, double consumption, double l)
		: Vehicle(n, km, consumption), load(l) {}

	double consumption() const override {
		return fuel_consumption + 2 * load;
	}

	void print() const override {
		Vehicle::print();
		std::cout << " (teret " << load << " t)";
	}
};


int main()
{
	// Car: ime, kilometri, osnovna potrosnja, eco nacin
	Car clio("Clio", 200, 6.0, false);
	Car yaris("Yaris", 200, 6.0, true);

	// Truck: ime, kilometri, osnovna potrosnja, teret u tonama
	Truck iveco("Iveco", 300, 20.0, 5);

	std::vector<Vehicle*> fleet = { &clio, &yaris, &iveco };

	double total = 0;

	for (Vehicle* v : fleet) {
		v->print();
		std::cout << '\n';
		total += v->fuel();
	}

	std::cout << "ukupno: " << total << " l\n";

	return 0;
}
/*
Ocekivani ispis:

	Clio: 12 l
	Yaris: 9.6 l
	Iveco: 90 l (teret 5 t)
	ukupno: 111.6 l
*/


/*
Odgovor: fuel() ne mora bit virtualna jer se koristi s consumption()
koji je sam po sebi virtualan pa se nema sta overrideat
*/
