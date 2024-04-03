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

	// Je�li lista jest pusta, zar�wno g�owa (head) jak i ogon (tail) wskazuj� na nowy w�ze�
	if (isEmpty()) {
		head = tail = added_node;
	}
	else {
		tail->next = added_node; //Ustawienie wska�nika "next" ostatniego elementu na nowy w�ze�
		tail = added_node; //Aktualizacja wska�nika "tail" na nowy w�ze�
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

	// Przej�cie przez list� do przedostatniego elementu
	node* current = head;
	while (current->next != tail) {
		current = current->next;
	}

	// Usuni�cie ostatniego elementu z pami�ci i aktualizacja wska�nika 'tail'
	delete tail;
	tail = current;
	tail->next = nullptr;
}

void singly_linked_list_upgd::clear()
{
	singly_linked_list::clear();
	tail = nullptr;
}
