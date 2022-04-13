#include "Span.hpp"

Span::Span(unsigned int size): size(size) {
	std::cout << "Constructor called" << std::endl;
}

Span::Span(const Span &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Span &Span::operator=(const Span &rhs) {
	std::cout << "Assignement operator called" << std::endl;
	this->vec.clear();
	for (unsigned long i = 0; i < rhs.vec.size(); i++)
		this->vec.push_back(rhs.vec[i]);
	return *this;
}

Span::~Span() {
	std::cout << "Destructor called" << std::endl;
	this->vec.clear();
}

void Span::addNumber(int x) {
	if (this->vec.size() >= this->size)
		throw std::length_error("Cannot add any more number");
	this->vec.push_back(x);
}

int Span::shortestSpan() {
	if (this->vec.size() < 2)
		throw std::length_error("Cannot find shortest span if less than 2 values");
	int shortest = INT_MAX;
	std::vector<int> temp = this->vec;

	std::sort(temp.begin(), temp.end());

	std::vector<int>::iterator it = temp.begin();
	while ((it + 1) != temp.end()) {
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
		it++;
	}
	return shortest;
}

int Span::longestSpan() {
	if (this->vec.size() < 2)
		throw std::length_error("Cannot find longest span if less than 2 values");
	std::vector<int> temp = this->vec;

	std::sort(temp.begin(), temp.end());
	return *(temp.end() - 1) - *temp.begin();
}

void Span::iteratorFiller(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (this->size - this->vec.size() <= 0)
		throw std::length_error("Cannot add that many integers");

	copy(start, end, std::back_inserter(this->vec));
}

void Span::randomFiller() {
	while (this->vec.size() < this->size) {
		this->vec.push_back(rand());
	}
}
