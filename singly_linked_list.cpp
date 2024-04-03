#include "singly_linked_list.h"

//Konstruktor tworz�cy pust� list�
singly_linked_list::singly_linked_list():head(nullptr){}

//Destruktor
singly_linked_list::~singly_linked_list(){
	node* current = head;
	while (current != nullptr) {
		node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;

}

//Dodanie nowego elementu na pocz�tek listy
void singly_linked_list::add_begin(int element){
	//Utworzenie nowego w�z�a
	node* added_node = new node(element);

	//Ustawienie wska�nika nowego w�z�a na dotychczasow� g�ow� listy
	added_node->next = head;

	//Ustawienie nowego w�z�a na now� g�ow� listy
	head = added_node;
}

//Dodanie nowego elementu na koniec listy
void singly_linked_list::add_end(int element){
	//Utworzenie nowego w�z�a
	node* added_node = new node(element);

	//Je�li lista jest pusta, nowy w�ze� zostaje g�ow� listy
	if (isEmpty()) {
		head = added_node;
		return;
	}

	//Przej�cie przez list�, aby dotrze� do w�z�a ostatniego
	node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}

	//Wstawienie nowego w�z�a na koniec listy
	current->next = added_node;
}

//Dodanie nowego elementu na wybrane miejsce listy
void singly_linked_list::add_ind(int element, int index){
	
	//Sprawdzenie, czy index nale�y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid�owy index \n";
		return;
	}
	//Je�li lista jest pusta lub u�ytkownik chce doda� na pocz�tek listy
	if (isEmpty() || index == 0) {
		add_begin(element);
		return;
	}

	//Utworzenie nowego w�z�a
	node* added_node = new node(element);

	//Przej�cie przez list�, aby dotrze� do miejsca przed wskazanym indeksem
	node* current = head;
	int current_index = 0;
	while (current_index < index - 1 && current->next != nullptr) {
		current = current->next;
		current_index++;
	}

	//Sprawdzenie, czy dotarto do ko�ca listy przed wskazanym indeksem
	if (current_index != index - 1) {
		std::cerr << "Index przekrocza rozmiar listy. \n";
		delete added_node;
		return;
	}

	//Wstawienie nowego w�z�a po w�le na miejscu index
	added_node->next = current->next;
	current->next = added_node;
}

//Usuni�cie pierwszego elementu listy
void singly_linked_list::delete_begin(){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Przeniesienie head na drugi element i usuni�cie pierwszego elementu z pami�ci
	node* old_head = head;
	head = head->next;
	delete old_head;
}

//Usuni�cie ostatniego elementu listy
void singly_linked_list::delete_end(){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Sprawdzenie, czy lista zawiera tylko jeden element
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	//Przej�cie przez list� do przedostatniego elementu
	node* current = head;
	while (current->next->next != nullptr) {
		current = current->next;
	}

	//Usuni�cie ostatniego elementu z pami�ci
	delete current->next;
	current->next = nullptr;
}

//Usuni�cie wybranego elementu listy
void singly_linked_list::delete_ind(int index){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Sprawdzenie, czy index nale�y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid�owy index \n";
		return;
	}

	//Sprawdzenie, czy u�ytkownik chce usun�� pierwszy element listy
	if (index == 0) {
		delete_begin();
		return;
	}

	//Przej�cie po li�cie do w�z�a poprzedzaj�cego docelowy w�ze�
	node* current = head;
	int count = 0;
	while (current->next != nullptr && count < index - 1) {
		current = current->next;
		count++;
	}

	//Sprawdzenie czy ��dany index jest wi�kszy ni� liczba w�z��w w li�cie
	if (current->next == nullptr) {
		std::cerr << "Podana pozycja nie istnieje w li�cie. \n";
		return;
	}

	//Usuni�cie wybranego w�z�a
	node* removable_node = current->next;
	current->next = removable_node->next;
	delete removable_node;
}

//Sprawdzenie czy lista jest pusta
bool singly_linked_list::isEmpty(){
	return head == nullptr;
}

//Wypisanie element�w listy
void singly_linked_list::show(){
	node* current = head;
	while (current != nullptr) {
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

//Wyczyszczenie listy
void singly_linked_list::clear(){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	while (head != nullptr) {
		delete_begin();
	}
}

//Szukanie elementu w li�cie po warto�ci
bool singly_linked_list::find(int element){
	node* current = head;
	while (current != nullptr) {
		if (current->data == element) {
			std::cout << "Element: " << element << std::endl;
			std::cout << "Adres elementu: " << current << std::endl;
			return true;
		}
		current = current->next;
	}
	std::cerr << "Nie odnaleziono podanego elementu. \n";
	return false;
}

//Szukanie elementu w li�cie po pozycji
int singly_linked_list::find_by_index(int index){
	//Sprawdzenie, czy index nale�y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid�owy numer index. \n";
		return -1;
	}

	node* current = head;
	int curr_index = 0;

	//Przej�cie przez elementy listy a� do napotkania oczekiwanej pozycji
	while (current != nullptr) {
		if (curr_index == index) {
			return current->data;
		}
		current = current->next;
		curr_index++;
	}

	std::cerr << "Nie odnaleziono elementu o podanym numerze index. \n";
	return -1;
}

//Wczytanie element�w do listy z pliku
void singly_linked_list::load_file(const std::string& filename){
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}

	int value;
	while (file >> value) {
		add_end(value); //Dodanie odczytanych element�w na koniec listy
	}

	file.close();
}

//Zapisywanie element�w listy do pliku
void singly_linked_list::save_file(const std::string& filename){
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}

	node* current = head;
	while (current != nullptr) {
		file << current->data << "\n"; //Zapisanie warto�ci bie��cego w�z�a do pliku
		current = current->next; //Przej�cie do nast�pnego w�z�a
	}

	file.close();
}
