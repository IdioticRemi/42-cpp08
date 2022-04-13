#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <vector>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <limits.h>

class Span {
public:
	Span(unsigned int size);
	Span(const Span &src);
	Span &operator=(const Span &rhs);
	virtual ~Span();

	void addNumber(int x);

	int shortestSpan();
	int longestSpan();

	void iteratorFiller(std::vector<int>::iterator start, std::vector<int>::iterator end);
	void randomFiller();

private:
	std::vector<int> vec;
	unsigned int size;
};

#endif
