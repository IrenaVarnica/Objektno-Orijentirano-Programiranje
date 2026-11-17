#include <iostream>
#include <utility>

class IntStack {
	int* data;
	int n;
	int cap;
public:
	IntStack(int capacity = 2)
		: data(new int[capacity > 0 ? capacity : 1]), n(0), cap(capacity > 0 ? capacity : 1) {
	}

	IntStack(const IntStack& o) : data(new int[o.cap]), n(o.n), cap(o.cap) {
		std::cout << "copy konstruktor\n";
		for (int i = 0; i < n; ++i) data[i] = o.data[i];
	}

	IntStack& operator=(const IntStack& o) {
		std::cout << "copy assignment\n";
		if (this != &o) {
			int* novi = new int[o.cap];         
			for (int i = 0; i < o.n; ++i) novi[i] = o.data[i];
			delete[] data;                     
			data = novi;
			n = o.n;
			cap = o.cap;
		}
		return *this;
	}

	IntStack(IntStack&& o) noexcept : data(o.data), n(o.n), cap(o.cap) {
		std::cout << "move konstruktor\n";
		o.data = nullptr;
		o.n = 0;
		o.cap = 0;
	}

	IntStack& operator=(IntStack&& o) noexcept {
		std::cout << "move assignment\n";
		if (this != &o) {
			delete[] data;
			data = o.data;
			n = o.n;
			cap = o.cap;
			o.data = nullptr;
			o.n = 0;
			o.cap = 0;
		}
		return *this;
	}

	~IntStack() { delete[] data; }

	void push(int x) {
		if (n == cap) {
			int novi_cap = cap > 0 ? 2 * cap : 2;  
			int* novi = new int[novi_cap];
			for (int i = 0; i < n; ++i) novi[i] = data[i];
			delete[] data;
			data = novi;
			cap = novi_cap;
		}
		data[n++] = x;
	}
	void pop() { if (n > 0) --n; }
	int top() const { return data[n - 1]; }
	bool empty() const { return n == 0; }
	int size() const { return n; }
	int capacity() const { return cap; }
};


int main()
{
	IntStack a;
	a.push(10);
	a.push(20);
	a.push(30);

	IntStack b = a;           
	b = a;                       
	IntStack c = std::move(a);   
	b = std::move(c);           

	std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
	return 0;
}

/*
Ocekivani ispis:

	copy konstruktor
	copy assignment
	move konstruktor
	move assignment
	0 0 3 30
*/