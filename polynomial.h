#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include "chain.h"

struct Term {
	int coef;
	int exp;
	Term Set(int c, int e) {
		coef = c;
		exp = e;
		return *this;
	}
};

class Polynomial {
	public:
		Polynomial operator+(const Polynomial& b) const;
		void Input(int c, int e);
		void Show();
	private:
		Chain<Term> poly;
};

#endif
