#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <stack>
#include <clocale>

template <typename T>
class MutantStack: public std::stack<T> {
public:
	MutantStack<T>(void) {}
	MutantStack<T>(const MutantStack<T> &src) : std::stack<T>(src) {}
	~MutantStack<T>(void) {}
	MutantStack<T> &operator=(const MutantStack<T> &rhs) {
		(void) rhs;
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack<T>::iterator begin() {
		return this->c.begin();
	}

	MutantStack<T>::iterator end() {
		return this->c.end();
	}
};

#endif
