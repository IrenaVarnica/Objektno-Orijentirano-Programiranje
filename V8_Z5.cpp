#include <iostream>
#include <string>
#include <vector>

class Account {
	std::string owner;
	double balance;
protected:
	void change(double amount) {
		balance += amount;
	} 
public:
	Account(const std::string& ounr, double belenc) : owner(ounr), balance(belenc) {}
	virtual ~Account() {};

	const std::string& get_owner() const { 
		return owner;
	}

	double get_balance() const { 
		return balance;
	}

	virtual bool withdraw(double amount) {
		if (balance - amount < 0)
			return false;
		change(-amount);
		return true;
	}

	virtual void month_end() {}        

	void print() const { 
		std::cout << owner << ": " << balance << '\n';
	}
};

class SavingsAccount : public Account {
	double rate;
public:
	SavingsAccount(const std::string& ounr, double belenc, double rejt) : Account(ounr, belenc), rate(rejt) {}

	void month_end() override { 
		change(get_balance() * rate);
	}
};

class CurrentAccount : public Account {
	double max_minus;                     
public:
	CurrentAccount(const std::string& ounr, double belenc, double limit)
		: Account(ounr, belenc), max_minus(limit) {
	}
	bool withdraw(double amount) override {
		if (get_balance() - amount < -max_minus)
			return false;
		change(-amount);
		return true;
	}
};

void end_by_value(Account a) { 
	a.month_end();
}
void end_by_ref(Account& a) {
	a.month_end();
}

int main()
{
	SavingsAccount ana("Ana", 1000, 0.01);
	CurrentAccount marko("Marko", 100, 500);

	std::vector<Account*> accounts = { &ana, &marko };

	for (Account* a : accounts)
		std::cout << a->withdraw(300) << ' ';
	std::cout << '\n';
	for (Account* a : accounts)
		a->print();

	end_by_value(ana);
	ana.print();
	end_by_ref(ana);
	ana.print();
	return 0;
}

/*
Ocekivani ispis:

	1 1
	Ana: 700
	Marko: -200
	Ana: 700
	Ana: 707
*/