#include <iostream>
#include <vector>

class Board {
	int r, c;
	char border;
	std::vector<char> data;
public:
	Board(int rows, int cols, char border_ch)
		: r(rows), c(cols), border(border_ch), data(rows* cols, ' ') {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (i == 0 || j == 0 || i == r - 1 || j == c - 1)
					data[i * c + j] = border;
	}
	void set(int i, int j, char ch) {
		if (i > 0 && i < r - 1 && j > 0 && j < c - 1)
			data[i * c + j] = ch;
	}
	char get(int i, int j) const { return data[i * c + j]; }
	int rows() const { return r; }
	int cols() const { return c; }
	void print() const {
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) std::cout << data[i * c + j];
			std::cout << '\n';
		}
	}
};

int main()
{
	Board b(4, 8, '#');
	b.set(1, 2, '@');
	Board copy = b;         
	copy.set(2, 5, '*');
	copy.set(0, 0, '!');   
	b.print();
	copy.print();
	std::cout << copy.rows() << ' ' << copy.cols() << ' '
		<< copy.get(2, 5) << '\n';
	return 0;
}

