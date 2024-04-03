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
