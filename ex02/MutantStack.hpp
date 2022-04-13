#ifndef CPP08_MUTANTSTACK_HPP
#define CPP08_MUTANTSTACK_HPP

#include <stack>
#include <clocale>

template <class T>
class MutantStack: public std::stack<T> {
public:
	MutantStack<T>(void) {}
	MutantStack<T>(const MutantStack<T> &src) {}
	~MutantStack<T>(void) {}
	MutantStack<T> &operator=(const MutantStack<T> &rhs) {
		(void) rhs;
		return *this;
	}

	typedef class std::stack<T>::container_type::iterator iterator;

	MutantStack<T>::iterator begin() {
		return this->c.begin();
	}

	MutantStack<T>::iterator end() {
		return this->c.end();
	}
};

#endif
