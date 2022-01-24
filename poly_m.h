#ifndef POLY_M_H_INCLUDED
#define POLY_M_H_INCLUDED

template <typename T>
class Poly {
private:
	T* wspArray;
	int wspAmount;

public:
	Poly(int degree); //tworzy wielomian stopnia degree o wspolczynnikach rownych 0
	Poly(T* arrayOfCoef, int amountCoef); //tworzy wielomian o podanej liczbie wspolczynnikow, wartosci wspolczynnikow znajduja sie w tablicy arrayOfCoef
	Poly(Poly& other); //copy constructor
	~Poly();
	double& operator[](int index);

	Poly* add(Poly& other);
	Poly* substract(Poly& other);
	Poly* multiply(Poly& other);
	Poly* power(int pow_to);	

	int degree(); //funkcja zwraca stopien wielomianu
	bool isZero();

	T horner(const T&x);

	void display();
};

#endif
