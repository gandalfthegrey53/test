#include <iostream>
#include "polynomial.h"

std::ostream& operator<<(std::ostream& os, Term& t)
{
	if (t.exp == 0) {
		os << t.coef;
	} else {
		os << t.coef << "x^" << t.exp;
	}
	return os;
}

Polynomial Polynomial::operator+(const Polynomial& b) const
{
	Polynomial c;
	Chain<Term>::ChainIterator ai = poly.begin();
	Chain<Term>::ChainIterator bi = b.poly.begin();
	Chain<Term>::ChainIterator end = poly.end();
	Term temp;
	while (ai && bi) {
		if(ai->exp == bi->exp) {
			int sum = ai->coef + bi->coef;
			temp.Set(sum, ai->exp);
			ai++;
			bi++;
		} else if (ai->exp > bi->exp) {
			temp.Set(ai->coef, ai->exp);
			ai++;
		} else {
			temp.Set(bi->coef, bi->exp);
			bi++;
		}
		c.poly.InsertBack(temp);
	}
	while(ai != end) {
		temp.Set(ai->coef, ai->exp);
		c.poly.InsertBack(temp);
		ai++;
	}
	while(bi != end) {
		temp.Set(bi->coef, bi->exp);
		c.poly.InsertBack(temp);
		bi++;
	}
	return c;
}

void Polynomial::Input(int c, int e)
{
	Term temp;
	temp.Set(c, e);
	poly.Insert(temp);
}

void Polynomial::Show()
{
	poly.Show();
}
