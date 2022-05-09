#include "easyfind.hpp"

int	main( void )
{
	std::vector<int> vect;
	std::vector<int>::iterator it;
	for (int i = 0; i < 100; i += 5)
		vect.push_back(i);

	try {
		it = easyfind(vect, 15);

		std::cout << "\033[1;32mFOUND: \033[0;0m" << *it << std::endl;

		it = easyfind(vect, 50);

		std::cout << "\033[1;32mFOUND: \033[0;0m" << *it << std::endl;

		it = easyfind(vect, 42);
	} catch (std::exception &e) {
		std::cout << "\033[1;31mNOT FOUND: \033[0;0m" << e.what() << std::endl;
	}
}
