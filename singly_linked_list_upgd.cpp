#include "singly_linked_list_upgd.h"

singly_linked_list_upgd::~singly_linked_list_upgd()
{
		node* current = head;
		while (current != nullptr) {
			node* next = current->next;
			delete current;
			current = next;
		}
		head = tail = nullptr;

}

void singly_linked_list_upgd::add_begin(int element)
{
	//Utworzenie nowego węzła
	node* added_node = new node(element);
	if(isEmpty()){
		//Ustawienie wskaźnika nowego węzła na dotychczasową głowę listy
		added_node->next = head;

		//Ustawienie nowego węzła na nową głowę listy
		head = tail = added_node;
		return;
	}
	//Ustawienie wskaźnika nowego węzła na dotychczasową głowę listy
	added_node->next = head;

	//Ustawienie nowego węzła na nową głowę listy
	head = added_node;

}

void singly_linked_list_upgd::add_end(int element)
{
	node* added_node = new node(element);

	// Jeśli lista jest pusta, zarówno głowa (head) jak i ogon (tail) wskazują na nowy węzeł
	if (isEmpty()) {
		head = tail = added_node;
	}
	else {
		tail->next = added_node; //Ustawienie wskaźnika "next" ostatniego elementu na nowy węzeł
		tail = added_node; //Aktualizacja wskaźnika "tail" na nowy węzeł
	}
}

void singly_linked_list_upgd::delete_end()
{
	//Sprawdzenie czy lista jest pusta
	if (isEmpty()) {
		std::cerr << "Lista jest pusta. \n";
		return;
	}
	//Sprawdzenie, czy lista zawiera tylko jeden element
	if (head == tail) {
		delete head;
		head = tail = nullptr;
		return;
	}

	// Przejście przez listę do przedostatniego elementu
	node* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	// Usunięcie ostatniego elementu z pamięci i aktualizacja wskaźnika 'tail'
	delete tail;
	tail = current;
	tail->next = nullptr;
}

void singly_linked_list_upgd::clear()
{
	singly_linked_list::clear();
	tail = nullptr;
}
