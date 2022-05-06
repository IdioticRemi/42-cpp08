#ifndef CPP08_MAIN_HPP
#define CPP08_MAIN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm>

class ItemNotFoundException : public std::exception {
	virtual const char * what () const throw () {
		return "could not find requested item in container";
	}
};

template<typename T>
typename T::iterator easyfind(T &container, int toFind) {
	typename T::iterator result = find(container.begin(), container.end(), toFind);

	if (result == container.end())
		throw ItemNotFoundException();
	return result;
}

#endif
