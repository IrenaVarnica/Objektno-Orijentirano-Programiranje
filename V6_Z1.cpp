#include <iostream>

class IntStack {
	int* data;
	int n;
	int cap;
public:
	IntStack(int capacity = 2) : data(new int[capacity > 0 ? capacity : 1]), n(0), cap(capacity > 0 ? capacity : 1) {}
	IntStack(const IntStack& o) : data(new int[o.cap]), n(o.n), cap(o.cap) {
		for (int i = 0; i < n; ++i) data[i] = o.data[i];
	}
	~IntStack() { delete[] data; }

	void push(int x) {
		if (n == cap) {
			int* novi = new int[2 * cap];
			for (int i = 0; i < n; ++i) novi[i] = data[i];
			delete[] data;
			data = novi;
			cap *= 2;
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
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;     
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}
