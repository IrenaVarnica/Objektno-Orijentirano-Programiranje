#include <iostream>

struct Member {
	Member() { std::cout << "M "; }
	~Member() { std::cout << "~M "; }
};

struct Base {
	Base() { std::cout << "B "; }
	virtual ~Base() { std::cout << "~B "; }   // dodano virtual (bez njega zadnji red je samo ~B)
	void hello() const { std::cout << "Base::hello\n"; }
	virtual void greet() const { std::cout << "Base::greet\n"; }
};

struct Derived : public Base {
	Member m;
	Derived() { std::cout << "D\n"; }
	~Derived() { std::cout << "~D "; }
	void hello() const { std::cout << "Derived::hello\n"; }
	void greet() const override { std::cout << "Derived::greet\n"; }
};

int main()
{
	{
		Derived d;
		d.hello();   // Derived::hello: hello nije virtualna pa gleda tip varijable 
		d.greet();   // Derived::greet: greet je override-an
		Base& r = d;
		r.hello();   // Base::hello: nevirtualna metoda pa gleda tip reference 
		r.greet();   // Derived::greet: virtualna metoda pa gleda tip objekta 
	}
	std::cout << '\n';

	Base* p = new Derived;
	p->greet();   // Derived::greet: virtualna metoda, objekt je override-an
	delete p;     // bez virtual:poziva se samo ~Base, ~D i ~M se preskacu
	std::cout << '\n';
	return 0;
}

/*
Ocekivani ispis:

	B M D
	Derived::hello
	Derived::greet
	Base::hello
	Derived::greet
	~D ~M ~B
	B M D
	Derived::greet
	~B

Nakon dodavanja virtual ispred ~Base() zadnji redak je:

	~D ~M ~B
*/