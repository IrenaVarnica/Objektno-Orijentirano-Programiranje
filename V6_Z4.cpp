#include <iostream>

class Board {
	int r, c;
	char border;
	char* data;
public:
	Board(int rows, int cols, char border_ch)
		: r(rows), c(cols), border(border_ch), data(new char[rows * cols]) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				data[i * c + j] = (i == 0 || j == 0 || i == r - 1 || j == c - 1) ? border : ' ';
	}
	Board(const Board& o) : r(o.r), c(o.c), border(o.border), data(new char[o.r * o.c]) {
		for (int k = 0; k < r * c; ++k) data[k] = o.data[k];
	}
	~Board() { delete[] data; }

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
