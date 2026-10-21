#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v) {
	int i{};
	while (true) {
		std::cout << "Add number: " << std::endl;
		std::cin >> i;
		if (i < 1 || i > 20) {
			break;
		}
		v.push_back(i);

		std::cout << "Size: " << v.size() << std::endl;
		std::cout << "Capacity: " << v.capacity() << std::endl;

		std::cin.ignore();
	}
}

void print_vector(const std::vector<int>& v) {
	std::cout << "Vector: " << std::endl;
	for (int i{ 0 };i < v.size();i++) {
		std::cout << v[i] << ' ';
		
	}
	std::cout << std::endl;
} 


int main() {
	std::vector<int> vec;

	//input_vector(vec);
	//print_vector(vec);
	
	//std::cout << "Reversed: " << std::endl;
	//for (auto i = vec.rbegin(); i != vec.rend(); i++)
	//	std::cout << *i << ' ';


	std::vector<int> reserved_vec;
	reserved_vec.reserve(100);

	input_vector(reserved_vec);
	print_vector(reserved_vec);

	reserved_vec.shrink_to_fit();
	std::cout << "Capacity after shrinking: " << reserved_vec.capacity() << std::endl;


	return 0;
}