#include "array_list.h"
array_list::array_list():list()
{
	array = nullptr;
	size = 0;
	capacity = 0;
}
//Konstruktor
array_list::array_list(int initialCapacity)
{
	array = new int[initialCapacity];
	size = 0;
	capacity = initialCapacity;
}

//Destruktor
array_list::~array_list()
{
	delete[] array;
}

//Dodanie elementu na pocz¹tek tablicy
void array_list::add_begin(int element)
{
	//Jeœli tablica jest pe³na, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}

	//Przesuniecie wszystkich elementow o jeden w prawo
	for (int i = size; i > 0; --i) {
		array[i] = array[i - 1];
	}
	array[0] = element; //Dodanie elementu na pocz¹tek tablicy
	++size; //Zwiekszenie rozmiaru tablicy
}

//Dodanie elementu na koniec tablicy
void array_list::add_end(int element)
{
	//Jeœli tablica jest pe³na, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}
	//Dodanie elementu na koniec tablicy
	array[++size] = element;
}

//Dodanie elementu w losowe miejsce tablicy
void array_list::add_ind(int element, int index)
{

	//Jeœli tablica jest pe³na, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}

	//Sprawdzenie, czy numer indeks jest prawidlowy
	if (index > size || index < 0) {
		std::cerr << "Nieprawidlowy numer index" << std::endl;
	}

	//Przesuniêcie elementów od randomIndex do size w prawo
	for (int i = size; i > index; --i) {
		array[i] = array[i - 1];
	}

	array[index] = element; //Wstawienie nowego elementu na losow¹ pozycjê
	++size; //Zwiêkszenie rozmiaru tablicy
}

//Usuniêcie elementu na pocz¹tku tablicy
void array_list::delete_begin()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (isEmpty()) {
		std::cerr << "Tablica jest pusta." << std::endl;
	}

	//Przesuniecie elementow od size do pierwszego elementu w lewo
	for (int i = 1; i <= size; i++) {
		array[i - 1] = array[i];
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

//Usuniecie elementu na koncu tablicy
void array_list::delete_end()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (isEmpty()) {
		std::cerr << "Tablica jest pusta." << std::endl;
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

//Usuniecie elementu w losowym miejscu tablicy
void array_list::delete_ind(int index)
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (isEmpty()) {
		std::cerr << "Tablica jest pusta." << std::endl;
	}

	//Sprawdzenie, czy numer indeks jest prawidlowy
	if (index > size || index < 0) {
		std::cerr << "Nieprawidlowy numer index" << std::endl;
	}

	//Przesuniecie elementow od size do randomIndex w lewo
	for (int i = index; i <= size; ++i) {
		array[i - 1] = array[i];
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

bool array_list::isEmpty()
{
	return size==0;
}

int array_list::getSize()
{
	return this->size;
}

int array_list::getCapacity()
{
	return this->capacity;
}

void array_list::enlarge()
{
	capacity *= 2;
	int* newArray = new int[capacity];
	//Skopiowanie zawartoœci starej tablicy do nowej
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}
	//Zwolnienie pamiêci starej tablicy
	delete[] array;
	//Przypisanie nowej tablicy do wskaŸnika
	array = newArray;
}
