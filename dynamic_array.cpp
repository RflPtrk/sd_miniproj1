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

//Dodanie elementu na początek tablicy
void dynamic_array::add_begin(int element)
{
	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawartości starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pamięci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wskaźnika
		array = newArray;
	}
	
	//Przesuniecie wszystkich elementow o jeden w prawo
	for (int i = size; i > 0; --i) {
		array[i] = array[i - 1];
	}
	array[0] = element; //Dodanie elementu na początek tablicy
	++size; //Zwiekszenie rozmiaru tablicy
}

//Dodanie elementu na koniec tablicy
void dynamic_array::add_end(int element)
{
	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawartości starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pamięci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wskaźnika
		array = newArray;
	}
	//Dodanie elementu na koniec tablicy
	array[++size] = element;
}

//Dodanie elementu w losowe miejsce tablicy
void dynamic_array::add_random(int element)
{
	//Wygenerowanie losowego indeksu od 0 do size
	int randomIndex = rand() % (size + 1);

	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		capacity *= 2;
		int* newArray = new int[capacity];
		//Skopiowanie zawartości starej tablicy do nowej
		for (int i = 0; i < size; ++i) {
			newArray[i] = array[i];
		}
		//Zwolnienie pamięci starej tablicy
		delete[] array;
		//Przypisanie nowej tablicy do wskaźnika
		array = newArray;
	}

	//Przesunięcie elementów od randomIndex do size w prawo
	for (int i = size; i > randomIndex; --i) {
		array[i] = array[i - 1];
	}

	//Wstawienie nowego elementu na losową pozycję
	array[randomIndex] = element;
	++size; //Zwiększenie rozmiaru tablicy
}

//Usunięcie elementu na początku tablicy
void dynamic_array::delete_begin()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (size == 0) {
		throw std::runtime_error("Tablica jest pusta.");
	}

	//Przesuniecie elementow od size do pierwszego elementu w lewo
	for (int i = 1; i <= size; i++) {
		array[i - 1] = array[i];
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

//Usuniecie elementu na koncu tablicy
void dynamic_array::delete_end()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (size == 0) {
		throw std::runtime_error("Tablica jest pusta.");
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

//Usuniecie elementu w losowym miejscu tablicy
void dynamic_array::delete_random()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (size == 0) {
		throw std::runtime_error("Tablica jest pusta.");
	}
	//Wylosowanie indeksu miejsca tablicy
	int randomIndex = rand() % size;

	//Przesuniecie elementow od size do randomIndex w lewo
	for (int i = randomIndex + 1; i <= size; ++i) {
		array[i - 1] = array[i];
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

bool dynamic_array::isEmpty()
{
	return size==0;
}

int dynamic_array::getSize()
{
	return size;
}
