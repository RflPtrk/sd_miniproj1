#include "array_list.h"

//Konstruktor tworzacy pusta tablice
array_list::array_list():list()
{
	array = nullptr;
	size = 0;
	capacity = 0;
}

//Konstruktor tworzacy tablice o ustalonym rozmiarze i wypelniona losowymi liczbami
array_list::array_list(int array_size):list(), size(array_size),capacity(2*array_size)
{
	array = new int[capacity];
	if (!array) {
		std::cerr << "Blad alokacji pamieci dla tablicy dynamicznej.\n";
		return;
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::max());

	//Wypelnienie tablicy losowymi liczbami calkowitymi
	for (int i = 0; i < size; ++i) {
		array[i] = dist(gen);
	}
}

//Destruktor
array_list::~array_list()
{
	delete[] array;
}

//Dodanie elementu na początek tablicy
void array_list::add_begin(int element)
{
	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}

	//Przesuniecie wszystkich elementow o jeden w prawo
	for (int i = size; i > 0; --i) {
		array[i] = array[i - 1];
	}
	array[0] = element; //Dodanie elementu na początek tablicy
	++size; //Zwiekszenie rozmiaru tablicy
}

//Dodanie elementu na koniec tablicy
void array_list::add_end(int element)
{
	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}
	//Dodanie elementu na koniec tablicy
	array[size++] = element;
}

//Dodanie elementu w losowe miejsce tablicy
void array_list::add_ind(int element, int index)
{

	//Jeśli tablica jest pełna, to rozmiar zostaje podwojony
	if (size == capacity) {
		enlarge();
	}

	//Sprawdzenie, czy numer indeks jest prawidlowy
	if (index > size || index < 0) {
		std::cerr << "Nieprawidlowy numer index \n";
		return;
	}

	//Przesunięcie elementów od randomIndex do size w prawo
	for (int i = size; i > index; --i) {
		array[i] = array[i - 1];
	}

	array[index] = element; //Wstawienie nowego elementu na losową pozycję
	++size; //Zwiększenie rozmiaru tablicy
}

//Usunięcie elementu na początku tablicy
void array_list::delete_begin()
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (isEmpty()) {
		std::cerr << "Tablica jest pusta. \n";
		return;
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
		std::cerr << "Tablica jest pusta. \n";
		return;
	}
	--size; //Zmniejszenie rozmiaru tablicy
}

//Usuniecie elementu w losowym miejscu tablicy
void array_list::delete_ind(int index)
{
	//Jesli rozmiar tablicy jest rowny zero, niech wyskoczy blad
	if (isEmpty()) {
		std::cerr << "Tablica jest pusta. \n";
		return;
	}

	//Sprawdzenie, czy numer indeks jest prawidlowy
	if (index > size || index < 0) {
		std::cerr << "Nieprawidlowy numer index \n";
		return;
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
	//Skopiowanie zawartości starej tablicy do nowej
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}
	//Zwolnienie pamięci starej tablicy
	delete[] array;
	//Przypisanie nowej tablicy do wskaźnika
	array = newArray;
}

void array_list::show()
{
	if (isEmpty()) {
		std::cout << "Tablica jest pusta. \n";
		return;
	}
	for (int i = 0; i < size; i++) {
		std::cout << "Element: " << array[i] << std::endl << "Numer index: " << i << std::endl;
	}
}

void array_list::clear()
{
	size = 0; //Reset rozmiaru tablicy na zero, aby usunac wszystkie elementy
}

//Wyszukiwanie elementu na podstawie wartości
bool array_list::find(int element)
{
	if (isEmpty()) {	//Sprawdzenie czy tablica jest pusta
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (element == array[i]) {
			std::cout << "Element: " << array[i] << std::endl << "Indeks elementu: " << i << std::endl;
			return true;
		}
	}
	std::cerr << "Nie znaleziono podanego elementu.";
	return false;
}

int array_list::find_by_index(int index)
{
	if (index >= size || index < 0) {
		std::cerr << "Nieprawidlowy numer index. \n";
		return 0;
	}
	return array[index];
}

void array_list::load_file(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}
	int value;
	while (file >> value) {
		add_end(value);
	}
	file.close();
}

void array_list::save_file(const std::string& filename)
{
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}

	for (int i = 0; i < size; ++i) {
		file << array[i] << std::endl;
	}

	file.close();
}
