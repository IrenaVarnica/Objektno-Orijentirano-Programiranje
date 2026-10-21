#include <algorithm> 
#include <array>
#include <iostream>

constexpr int DAYS = 7;  


double total(const std::array<double, DAYS>& hours) {
	double sum = 0.0;
	for (auto& h : hours)
		sum += h;
	return sum;
}


int best_day(const std::array<double, DAYS>& hours) {
	auto it = std::max_element(hours.begin(), hours.end());
	return static_cast<int>(it - hours.begin()) + 1;
}

int main() {
	std::array<double, DAYS> week1{};
	std::array<double, DAYS> week2{};

	for (int i = 0; i < DAYS; ++i) {
		std::cout << "Sati ucenja za dan " << i + 1 << ": ";
		std::cin >> week1.at(i);
	}

	std::cout << "Prvi tjedan:" << std::endl;
	std::cout << "Ukupno sati: " << total(week1) << std::endl;
	std::cout << "Dan s najvise sati: " << best_day(week1) << ". dan" << std::endl;

	week2.fill(1.5);


	std::cout << "Jesu li prvi i drugi tjedan isti? ";
	(week1 == week2) == 1 ? std::cout << "yep" : std::cout << "nope";
	std::cout << std::endl;

	std::cout << "Je li prvi tjedan manji od drugog tjedna? ";
	(week1 < week2) == 1 ? std::cout << "yep" : std::cout << "nope";
	std::cout << std::endl;

	week1.swap(week2);

	std::cout << "Nakon zamjene:" << std::endl;
	std::cout << "Ukupno sati prvi tjedan: " << total(week1) << std::endl;
	std::cout << "Ukupno sati drugi tjedan: " << total(week2) << std::endl;

	return 0;
}
