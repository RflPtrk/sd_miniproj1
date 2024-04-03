#include "singly_linked_list.h"

//Konstruktor tworzący pustą listę
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

//Dodanie nowego elementu na początek listy
void singly_linked_list::add_begin(int element){
	//Utworzenie nowego węzła
	node* added_node = new node(element);

	//Ustawienie wskaźnika nowego węzła na dotychczasową głowę listy
	added_node->next = head;

	//Ustawienie nowego węzła na nową głowę listy
	head = added_node;
}

//Dodanie nowego elementu na koniec listy
void singly_linked_list::add_end(int element){
	//Utworzenie nowego węzła
	node* added_node = new node(element);

	//Jeśli lista jest pusta, nowy węzeł zostaje głową listy
	if (isEmpty()) {
		head = added_node;
		return;
	}

	//Przejście przez listę, aby dotrzeć do węzła ostatniego
	node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}

	//Wstawienie nowego węzła na koniec listy
	current->next = added_node;
}

//Dodanie nowego elementu na wybrane miejsce listy
void singly_linked_list::add_ind(int element, int index){
	
	//Sprawdzenie, czy index należy do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawidłowy index \n";
		return;
	}
	//Jeśli lista jest pusta lub użytkownik chce dodać na początek listy
	if (isEmpty() || index == 0) {
		add_begin(element);
		return;
	}

	//Utworzenie nowego węzła
	node* added_node = new node(element);

	//Przejście przez listę, aby dotrzeć do miejsca przed wskazanym indeksem
	node* current = head;
	int current_index = 0;
	while (current_index < index -1 && current != nullptr) {
		current = current->next;
		current_index++;
	}

	//Sprawdzenie, czy dotarto do końca listy przed wskazanym indeksem
	if (current_index != index -1) {
		std::cerr << "Index przekrocza rozmiar listy. \n";
		delete added_node;
		return;
	}

	//Wstawienie nowego węzła po węźle na miejscu index
	added_node->next = current->next;
	current->next = added_node;
}

//Usunięcie pierwszego elementu listy
void singly_linked_list::delete_begin(){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Przeniesienie head na drugi element i usunięcie pierwszego elementu z pamięci
	node* old_head = head;
	head = head->next;
	delete old_head;
}

//Usunięcie ostatniego elementu listy
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

	//Przejście przez listę do przedostatniego elementu
	node* current = head;
	while (current->next->next != nullptr) {
		current = current->next;
	}

	//Usunięcie ostatniego elementu z pamięci
	delete current->next;
	current->next = nullptr;
}

//Usunięcie wybranego elementu listy
void singly_linked_list::delete_ind(int index){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Sprawdzenie, czy index należy do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawidłowy index \n";
		return;
	}

	//Sprawdzenie, czy użytkownik chce usunąć pierwszy element listy
	if (index == 0) {
		delete_begin();
		return;
	}

	//Przejście po liście do węzła poprzedzającego docelowy węzeł
	node* current = head;
	int count = 0;
	while (current->next != nullptr && count < index - 1) {
		current = current->next;
		count++;
	}

	//Sprawdzenie czy żądany index jest większy niż liczba węzłów w liście
	if (current->next == nullptr) {
		std::cerr << "Podana pozycja nie istnieje w liście. \n";
		return;
	}

	//Usunięcie wybranego węzła
	node* removable_node = current->next;
	current->next = removable_node->next;
	delete removable_node;
}

//Sprawdzenie czy lista jest pusta
bool singly_linked_list::isEmpty(){
	return head == nullptr;
}

//Wypisanie elementów listy
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

//Szukanie elementu w liście po wartości
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

//Szukanie elementu w liście po pozycji
int singly_linked_list::find_by_index(int index){
	//Sprawdzenie, czy index należy do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawidłowy numer index. \n";
		return -1;
	}

	node* current = head;
	int curr_index = 0;

	//Przejście przez elementy listy aż do napotkania oczekiwanej pozycji
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

//Wczytanie elementów do listy z pliku
void singly_linked_list::load_file(const std::string& filename){
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}

	int value;
	while (file >> value) {
		add_end(value); //Dodanie odczytanych elementów na koniec listy
	}

	file.close();
}

//Zapisywanie elementów listy do pliku
void singly_linked_list::save_file(const std::string& filename){
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Nie mozna otworzyc pliku: " << filename << "\n";
		return;
	}

	node* current = head;
	while (current != nullptr) {
		file << current->data << "\n"; //Zapisanie wartości bieżącego węzła do pliku
		current = current->next; //Przejście do następnego węzła
	}

	file.close();
}
