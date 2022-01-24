#include "poly_m.cpp"
#include "poly_test.h"
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 1" << std::endl;
	std::cout << std::endl;
	test1();
	std::cout << std::endl;
	std::cout << "-----------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;


	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 2" << std::endl;
	std::cout << std::endl;
	test2();
	std::cout << std::endl;
	std::cout << "-----------------------------------------------";
	std::cout << std::endl;
	std::cout << std::endl;

	int degree1, degree2, size1, size2;
	std::cout << "Podaj stopien wielomianu: ";
	std::cin >> degree1;
	size1 = degree1 + 1;

	double* coef_tab1 = new double[size1];

	for (int i = degree1; i >= 0; i--) {
		std::cout << "Wspolczynnik dla x^" << i << " ";
		std::cin >> coef_tab1[i];
	}

	Poly<double> w1(coef_tab1, size1);

	std::cout << std::endl;
	std::cout << "w1: ";
	w1.display();
	std::cout << std::endl;
	if (w1.isZero())
	{
		std::cout << "Wielomian w1 jest zerowy." << std::endl;
	}
	else
	{
		std::cout << "Wielomian w1 nie jest zerowy." << std::endl;
	}




	std::cout << std::endl;
	std::cout << "Podaj stopien drugiego wielomianu: ";
	std::cin >> degree2;
	size2 = degree2 + 1;

	double* coef_tab2 = new double[size2];

	for (int i = degree2; i >= 0; i--) {
		std::cout << "Wspolczynnik dla x^" << i << " ";
		std::cin >> coef_tab2[i];
	}

	Poly<double> w2(coef_tab2, size2);

	std::cout << std::endl;
	std::cout << "w2: ";
	w2.display();
	std::cout << std::endl;
	if (w2.isZero())
	{
		std::cout << "Wielomian w2 jest zerowy." << std::endl;
	}
	else
	{
		std::cout << "Wielomian w2 nie jest zerowy." << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "Dzialania: " << std::endl;

	Poly<double>* sum = w1.add(w2);
	std::cout << "w1 + w2 = ";
	sum->display();
	if (sum != nullptr) {
		delete sum;
		sum = nullptr;
	}


	Poly<double>* mul = w1.multiply(w2);
	std::cout << std::endl << "w1 * w2 = ";
	mul->display();
	if (mul != nullptr) {
		delete mul;
		mul = nullptr;
	}
	
	Poly<double>* pow1 = w1.power(2);
	std::cout << std::endl << "w1^2 = ";
	pow1->display();
	if (pow1 != nullptr) {
		delete pow1;
		pow1 = nullptr;
	}

	Poly<double>* pow2 = w2.power(3);
	std::cout << std::endl << "w2^3 = ";
	pow2->display();
	if (pow2 != nullptr) {
		delete pow1;
		pow2 = nullptr;
	}


	double x;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "x, dla ktorego zostanie obliczona wartosc wielomianu: ";
	std::cin >> x;
	std::cout << std::endl;
	double value = w1.horner(x);
	std::cout << "Wartosc wielomianu w1 w punkcie " << x << " wynosi: " << value;
	std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}