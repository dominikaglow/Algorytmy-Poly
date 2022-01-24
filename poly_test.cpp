#include "poly_m.cpp"
#include <iostream>

void test1() {
	double* coef_tab1_test1 = new double[5];
	coef_tab1_test1[0] = 6.4;
	coef_tab1_test1[1] = -2;
	coef_tab1_test1[2] = 10;
	coef_tab1_test1[3] = -1;
	coef_tab1_test1[4] = 3;

	Poly<double> w1_t1(coef_tab1_test1, 5);
	std::cout << "w1: ";
	w1_t1.display();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Wspolczynnik przy x^3 wynosi: " << w1_t1[3] << std::endl;
	std::cout << std::endl;
	std::cout << "Wielomian ";
	if (w1_t1.isZero())
	{
		std::cout << "jest";
	}
	else
	{
		std::cout << "nie jest ";
	}
	std::cout << "zerowy." << std::endl;

	double* coef_tab2_test1 = new double[4];
	coef_tab2_test1[0] = 2;
	coef_tab2_test1[1] = -4.5;
	coef_tab2_test1[2] = 14;
	coef_tab2_test1[3] = -5;

	Poly<double> w2_t1(coef_tab2_test1, 4);
	std::cout << "w2: ";
	w2_t1.display();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Wspolczynnik przy x^2 wynosi: " << w2_t1[2] << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;	


	std::cout << "Dzialania: " << std::endl;

	Poly<double>* sum = w1_t1.add(w2_t1);
	std::cout << "w1 + w2 = ";
	sum->display();
	if (sum != nullptr) {
		delete sum;
		sum = nullptr;
	}


	Poly<double>* subs = w1_t1.substract(w2_t1);
	std::cout << std::endl << "w1 - w2 = ";
	subs->display();
	if (subs != nullptr) {
		delete subs;
		subs = nullptr;
	}


	Poly<double>* mul = w1_t1.multiply(w2_t1);
	std::cout << std::endl << "w1 * w2 = ";
	mul->display();
	if (mul != nullptr) {
		delete mul;
		mul = nullptr;
	}

	Poly<double>* pow1 = w1_t1.power(2);
	std::cout << std::endl << "w1^2 = ";
	pow1->display();
	if (pow1 != nullptr) {
		delete mul;
		pow1 = nullptr;
	}

	Poly<double>* pow2 = w2_t1.power(3);
	std::cout << std::endl << "w2^3 = ";
	pow2->display();
	if (pow2 != nullptr) {
		delete mul;
		pow2 = nullptr;
	}



	std::cout << std::endl;
	std::cout << std::endl;
	int x = -2;
	std::cout << "x, dla ktorego zostanie obliczona wartosc wielomianu w1: " << x << std::endl;
	double value = w1_t1.horner(x);
	std::cout << "Oczekiwana wartosc: 106.4" << std::endl;
	std::cout << "Wartosc wielomianu w1 w punkcie " << x << " wynosi: " << value;
}


void test2() {
	int* coef_tab1_test2 = new int[4];
	coef_tab1_test2[0] = 1;
	coef_tab1_test2[1] = 2;
	coef_tab1_test2[2] = 3;
	coef_tab1_test2[3] = 4;

	Poly<int> w1_t2(coef_tab1_test2, 4);
	std::cout << "w1: ";
	w1_t2.display();
	std::cout << std::endl;



	int* coef_tab2_test2 = new int[7];
	coef_tab2_test2[0] = 10;
	coef_tab2_test2[1] = 9;
	coef_tab2_test2[2] = 8;
	coef_tab2_test2[3] = 7;
	coef_tab2_test2[4] = 6;
	coef_tab2_test2[5] = 5;
	coef_tab2_test2[6] = 4;

	Poly<int> w2_t2(coef_tab2_test2, 7);
	std::cout << "w2: ";
	w2_t2.display();
	std::cout << std::endl;
	std::cout << std::endl;



	std::cout << "Dzialania: " << std::endl;

	Poly<int>* sum = w1_t2.add(w2_t2);
	std::cout << "w1 + w2 = ";
	sum->display();
	if (sum != nullptr) {
		delete sum;
		sum = nullptr;
	}


	Poly<int>* subs = w1_t2.substract(w2_t2);
	std::cout << std::endl << "w1 - w2 = ";
	subs->display();
	if (subs != nullptr) {
		delete subs;
		subs = nullptr;
	}


	Poly<int>* mul = w1_t2.multiply(w2_t2);
	std::cout << std::endl << "w1 * w2 = ";
	mul->display();
	if (mul != nullptr) {
		delete mul;
		mul = nullptr;
	}



	std::cout << std::endl;
	std::cout << std::endl;
	int x = 3;
	std::cout << "x, dla ktorego zostanie obliczona wartosc wielomianu w2: " << x << std::endl;
	double value = w2_t2.horner(x);
	std::cout << "Oczekiwana wartosc: 4915" << std::endl;
	std::cout << "Wartosc wielomianu w1 w punkcie " << x << " wynosi: " << value;
}