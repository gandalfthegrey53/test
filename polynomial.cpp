#include <iostream>
#include "polynomial.h"

std::ostream& operator<<(std::ostream& os, Term& t)
{
	os << t.coef << "x^" << t.exp;
	return os;
}

Polynomial Polynomial::operator+(const Polynomial& b) const
{
	Polynomial c;
	Polynomial *a = this;
	while (!(*a).poly.IsEmpty() && !b.poly.IsEmpty()) {
		if ((*a).poly)
	}
}

void Polynomial::Show()
{
	poly.Show();
}
