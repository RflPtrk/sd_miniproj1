#include "singly_linked_list.h"

//Konstruktor tworz¹cy pust¹ listê
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

//Dodanie nowego elementu na pocz¹tek listy
void singly_linked_list::add_begin(int element){
	//Utworzenie nowego wêz³a
	node* added_node = new node(element);

	//Ustawienie wskaŸnika nowego wêz³a na dotychczasow¹ g³owê listy
	added_node->next = head;

	//Ustawienie nowego wêz³a na now¹ g³owê listy
	head = added_node;
}

//Dodanie nowego elementu na koniec listy
void singly_linked_list::add_end(int element){
	//Utworzenie nowego wêz³a
	node* added_node = new node(element);

	//Jeœli lista jest pusta, nowy wêze³ zostaje g³ow¹ listy
	if (isEmpty()) {
		head = added_node;
		return;
	}

	//Przejœcie przez listê, aby dotrzeæ do wêz³a ostatniego
	node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}

	//Wstawienie nowego wêz³a na koniec listy
	current->next = added_node;
}

//Dodanie nowego elementu na wybrane miejsce listy
void singly_linked_list::add_ind(int element, int index){
	
	//Sprawdzenie, czy index nale¿y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid³owy index \n";
		return;
	}
	//Jeœli lista jest pusta lub u¿ytkownik chce dodaæ na pocz¹tek listy
	if (isEmpty() || index == 0) {
		add_begin(element);
		return;
	}

	//Utworzenie nowego wêz³a
	node* added_node = new node(element);

	//Przejœcie przez listê, aby dotrzeæ do miejsca przed wskazanym indeksem
	node* current = head;
	int current_index = 0;
	while (current_index < index - 1 && current->next != nullptr) {
		current = current->next;
		current_index++;
	}

	//Sprawdzenie, czy dotarto do koñca listy przed wskazanym indeksem
	if (current_index != index - 1) {
		std::cerr << "Index przekrocza rozmiar listy. \n";
		delete added_node;
		return;
	}

	//Wstawienie nowego wêz³a po wêŸle na miejscu index
	added_node->next = current->next;
	current->next = added_node;
}

//Usuniêcie pierwszego elementu listy
void singly_linked_list::delete_begin(){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Przeniesienie head na drugi element i usuniêcie pierwszego elementu z pamiêci
	node* old_head = head;
	head = head->next;
	delete old_head;
}

//Usuniêcie ostatniego elementu listy
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

	//Przejœcie przez listê do przedostatniego elementu
	node* current = head;
	while (current->next->next != nullptr) {
		current = current->next;
	}

	//Usuniêcie ostatniego elementu z pamiêci
	delete current->next;
	current->next = nullptr;
}

//Usuniêcie wybranego elementu listy
void singly_linked_list::delete_ind(int index){
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}

	//Sprawdzenie, czy index nale¿y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid³owy index \n";
		return;
	}

	//Sprawdzenie, czy u¿ytkownik chce usun¹æ pierwszy element listy
	if (index == 0) {
		delete_begin();
		return;
	}

	//Przejœcie po liœcie do wêz³a poprzedzaj¹cego docelowy wêze³
	node* current = head;
	int count = 0;
	while (current->next != nullptr && count < index - 1) {
		current = current->next;
		count++;
	}

	//Sprawdzenie czy ¿¹dany index jest wiêkszy ni¿ liczba wêz³ów w liœcie
	if (current->next == nullptr) {
		std::cerr << "Podana pozycja nie istnieje w liœcie. \n";
		return;
	}

	//Usuniêcie wybranego wêz³a
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

//Szukanie elementu w liœcie po wartoœci
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

//Szukanie elementu w liœcie po pozycji
int singly_linked_list::find_by_index(int index){
	//Sprawdzenie, czy index nale¿y do liczb naturalnych
	if (index < 0) {
		std::cerr << "Nieprawid³owy numer index. \n";
		return -1;
	}

	node* current = head;
	int curr_index = 0;

	//Przejœcie przez elementy listy a¿ do napotkania oczekiwanej pozycji
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
		file << current->data << "\n"; //Zapisanie wartoœci bie¿¹cego wêz³a do pliku
		current = current->next; //Przejœcie do nastêpnego wêz³a
	}

	file.close();
}
