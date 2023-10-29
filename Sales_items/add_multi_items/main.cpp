#include <iostream>
#include "../Sales_item.h"

int main() {
	Sales_item total;

	if (std::cin >> total) {

		Sales_item items;

		while (std::cin >> items) {
			if (total.isbn() == items.isbn()) {
				total += items;
				} 
			else {
				std::cout << total << std::endl;
				total = items;
				
				break;
			}
		}
		std::cout << total << std::endl;
	}

	else {
		std::cerr << "No data!! Add some fucker" << std::endl;
		return -1;
	}

	return 0; 
}
