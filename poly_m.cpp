#include "poly_m.h"
#include <iostream>

template <typename T>
Poly<T>::Poly(int degree) {
	wspAmount = degree + 1;
	wspArray = new T[wspAmount];
	for (int i = 0; i < wspAmount; i++) {
		wspArray[i] = 0;
	}
}

template <typename T>
Poly<T>::Poly(T* arrayOfCoef, int amountCoef) {
	wspAmount = amountCoef;
	wspArray = new T[wspAmount];
	for (int i = 0; i < wspAmount; i++) {
		wspArray[i] = arrayOfCoef[i];
	}
}

template <typename T>
Poly<T>::Poly(Poly& other) {
	wspAmount = other.wspAmount;
	wspArray = new double[wspAmount];
	int i = 0;
	while (i < wspAmount) {
		wspArray[i] = other.wspArray[i];
		i++;
	}
}

template <typename T>
Poly<T>::~Poly() {
	delete[] wspArray; //teraz juz na nic nie wskazuje
	wspArray = nullptr; //ustawienie wskaznika na null
	wspAmount = 0; //rozmiar tablicy to 0
}

template<typename T>
double & Poly<T>::operator[](int index)
{
	if (index >= wspAmount) 
	{
		std::cout << "Indeks tablicy poza zakresem, wychodz?!";
		exit(0);
	}
	return wspArray[index];
}

template <typename T>
Poly<T>* Poly<T>::add(Poly& other) {
	int sizeOfSum = 0;
	//wybieranie wiekszego pod wzgledem liczby wspolczynnikow wielomianu
	if (wspAmount >= other.wspAmount) {
		sizeOfSum = wspAmount;
	}
	else {
		sizeOfSum = other.wspAmount;
	}
	//konstruktor tworzacy wielomian o stopniu o jeden mniejszym od ilosci wspolczynnikow
	Poly* result = new Poly(sizeOfSum - 1);
	if (wspAmount < other.wspAmount) {
		int i = 0;
		while (i < wspAmount) {
			result->wspArray[i] = wspArray[i] + other.wspArray[i];
			i++;
		}
		i = wspAmount;
		while (i < other.wspAmount) {
			result->wspArray[i] = other.wspArray[i];
			i++;
		}
	}
	else {
		int i = 0;
		while (i < other.wspAmount) {
			result->wspArray[i] = wspArray[i] + other.wspArray[i];
			i++;
		}
		i = other.wspAmount;
		while (i < wspAmount) {
			result->wspArray[i] = wspArray[i];
			i++;
		}
	}
	return result;
}


template <typename T>
Poly<T>* Poly<T>::substract(Poly& other) {
	int sizeOfSum = 0;
	//wybieranie wiekszego pod wzgledem liczby wspolczynnikow wielomianu
	if (wspAmount >= other.wspAmount) {
		sizeOfSum = wspAmount;
	}
	else {
		sizeOfSum = other.wspAmount;
	}
	Poly* result = new Poly(sizeOfSum - 1);
	if (wspAmount < other.wspAmount) {
		int i = 0;
		while (i < wspAmount) {
			result->wspArray[i] = wspArray[i] - other.wspArray[i];
			i++;
		}
		i = wspAmount;
		while (i < other.wspAmount) {
			if (other.wspArray[i] > 0) {
				result->wspArray[i] = 0 - other.wspArray[i]; //jesli wspolczynnik ten bedzie wiekszy od 0, to po odjeciu go od 
															 //drugiego wielomianu ten wspolczynnik bedzie mial wartosci ujemna
			}
			else {
				result->wspArray[i] = abs(other.wspArray[i]); //jesli wspolczynnik mial wartosc <= 0, to w wyniku bedzie wartosc bezwzgl z tej wartosci
			}
			i++;
		}
	}
	else {
		int i = 0;
		while (i < other.wspAmount) {
			result->wspArray[i] = wspArray[i] - other.wspArray[i];
			i++;
		}
		i = other.wspAmount;
		while (i < wspAmount) {
			result->wspArray[i] = wspArray[i];
			i++;
		}
	}
	return result;
}

template <typename T>
Poly<T>* Poly<T>::multiply(Poly& other) {
	int newDegree = wspAmount + other.wspAmount - 2; //(x^3 + 5x^2 + 0x + 2)(3x^2 + 1x + 9) to stopien iloczynu
													 //bedzie rowny sumie ilosci wspolczynnikow obu wielomianow - 2
	Poly* result = new Poly(newDegree); //tworzenie wielomianu o stopniu newDegree

	for (int i = 0; i < wspAmount; i++) {
		for (int j = 0; j < other.wspAmount; j++) {
			result->wspArray[i + j] = result->wspArray[i + j] + (wspArray[i] * other.wspArray[j]);
		}
	}
	return result;
}

template<typename T>
Poly<T>* Poly<T>::power(int pow_to)
{
	if (pow_to == 0)
	{
		
	}
	Poly* tmp = new Poly(wspArray, wspAmount);
	Poly* ret = new Poly(wspArray, wspAmount);

	for (int n = 1; n < pow_to; n++)
	{
		ret = ret->multiply(*tmp);
	}

	return ret;
}

template <typename T>
int Poly<T>::degree() {
	return wspAmount - 1; //stopien wielomianu jest o 1 mniejszy od ilosci wspolczynnikow
}

template <typename T>
bool Poly<T>::isZero()
{
	bool ret = true;
	for (int i = wspAmount - 1; i > 0; i--)
	{
		if (wspArray[i] > 0.0)
		{
			ret = false;
			break;
		}
	}
	return ret;
}

template <typename T>
T Poly<T>::horner(const T&x) {
	int d = wspAmount - 1; //stopien wielomianu
	T result = 0;
	if (d == 0) {
		result = wspArray[0];
	}
	else {
		result = wspArray[wspAmount - 1]; //poczatkowo wynik jest rowny wspolczynnikowi przy najwyzszej potedze
		int i = wspAmount - 2;
		while (i >= 0) {
			result = x * result + wspArray[i]; //dla x^3 + 2x^2 + 4x + 5: x(x^2 + 2x + 4) + 5 = x(x(x + 2) + 4) + 5 
			i--;
		}
	}
	return result;
}

template <typename T>
void Poly<T>::display() {
	for (int i = wspAmount - 1; i >= 0; i--) {
		if (i == wspAmount - 1) {
			if (wspArray[i] != 0.0)
			{
				std::cout << wspArray[i] << "x^" << i;
			}			
		}
		else {
			if (wspArray[i] != 0.0)
			{
				if (wspArray[i] > 0) {
					std::cout << "+"; //jesli wspolczynnik jest wiekszy badz rowny 0 to na ekranie przed wspolczynnikiem wypisany zostanie plus
									  //jesli wspolczynnik bedzie mniejszy od 0 to na ekranie wypisany zostanie "-" i wart. bezwgl. wspolczynnika
				}
				std::cout << wspArray[i] << "x^" << i;
			}			
		}
	}
}