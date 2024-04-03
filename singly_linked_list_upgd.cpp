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

void singly_linked_list_upgd::add_end(int element)
{
	node* added_node = new node(element);

	// Jeœli lista jest pusta, zarówno g³owa (head) jak i ogon (tail) wskazuj¹ na nowy wêze³
	if (isEmpty()) {
		head = tail = added_node;
	}
	else {
		tail->next = added_node; //Ustawienie wskaŸnika "next" ostatniego elementu na nowy wêze³
		tail = added_node; //Aktualizacja wskaŸnika "tail" na nowy wêze³
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

	// Przejœcie przez listê do przedostatniego elementu
	node* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	// Usuniêcie ostatniego elementu z pamiêci i aktualizacja wskaŸnika 'tail'
	delete tail;
	tail = current;
	tail->next = nullptr;
}

void singly_linked_list_upgd::clear()
{
	singly_linked_list::clear();
	tail = nullptr;
}
