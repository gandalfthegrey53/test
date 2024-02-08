#include <iostream>
#include "polynomial.h"

using namespace std;

int main() {

	std::cout << "test \n" << std::endl;
	Polynomial * p1= new Polynomial;
	Polynomial * p2= new Polynomial;
	p1->Input(1, 1);
	p1->Input(2, 3);
	p1->Input(3, 5);
	p1->Input(4, 5);
	cout << "p1 : ";
	p1->Show();
	p2->Input(6, 1);
	p2->Input(7, 3);
	p2->Input(9, 2);
	p2->Input(3, 5);
	cout << "p2 : ";
	p2->Show();
	Polynomial p3 = *p1 + *p2;
	cout << "p3 : ";
	p3.Show();
	delete p1;
	delete p2;
	return 0;
}

