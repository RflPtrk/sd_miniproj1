#include "dynamic_array.h"
//Konstruktor
dynamic_array::dynamic_array(int initialCapacity)
{
	array = new int[initialCapacity];
	size = 0;
	capacity = initialCapacity;
}

//Destruktor
dynamic_array::~dynamic_array()
{
	delete[] array;
}

//Dodanie elementu na pocz�tek tablicy
void dynamic_array::add_begin(int element)
{
	//Je�li tablica jest pe�na, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawarto�ci starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pami�ci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wska�nika
		array = newArray;
	}
	//Dodanie elementu na pocz�tek tablicy
	array[++size] = element;
}

//Dodanie elementu na koniec tablicy
void dynamic_array::add_end(int element)
{
	//Je�li tablica jest pe�na, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawarto�ci starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pami�ci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wska�nika
		array = newArray;
	}
	//Dodanie elementu na koniec tablicy
	array[size++] = element;
}

//Dodanie elementu w losowe miejsce tablicy
void dynamic_array::add_random(int element)
{
	//Wygenerowanie losowego indeksu od 0 do size
	int randomIndex = rand() % (size + 1);

	//Je�li tablica jest pe�na, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawarto�ci starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pami�ci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wska�nika
		array = newArray;
	}

	//Przesuni�cie element�w od randomIndex do size w prawo
	for (int i = size; i > randomIndex; --i) {
		array[i] = array[i - 1];
	}

	//Wstawienie nowego elementu na losow� pozycj�
	array[randomIndex] = element;
	++size; //Zwi�kszenie rozmiaru tablicy
}
