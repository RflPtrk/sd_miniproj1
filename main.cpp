#include <iostream>
#include <chrono>
#include "array_list.h"
#include "singly_linked_list.h"
#include "singly_linked_list_upgd.h"

//dotyczy badan
/*int main()
{
	int value;
	int number = 200000;
	for (int i = 0; i <= 9; i++) {
		array_list lista_test(number);
		//lista_test.delete_end();
		lista_test.save_file("C:\\Users\\HP\\Desktop\\test2.txt");

		singly_linked_list_upgd lista_test1;
		lista_test1.load_file("C:\\Users\\HP\\Desktop\\test2.txt");*/

		/*auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < number; i++) {
			lista_test1.delete_end();
		}

		auto end = std::chrono::steady_clock::now();
		auto elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		std::cout <<elapsed_seconds.count() << std::endl; */
		
		
		/*std::ifstream file("C:\\Users\\HP\\Desktop\\test2.txt");
		if (!file.is_open()) {
			std::cerr << "Nie można otworzyć pliku.\n";
			return 1;
		}

		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < number; ++i) {
			if (!(file >> value)) {
				std::cerr << "Błąd podczas wczytywania danych z pliku.\n";
				return 1;
			}
			lista_test1.add_end(value);
		}

		auto end = std::chrono::steady_clock::now();
		auto elapsed_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		std::cout <<elapsed_seconds.count() << std::endl;

		value = 0;
		file.close();*/

		//dotyczy testowania operacji na jednym elemencie
		//auto start = std::chrono::steady_clock::now();
		//lista_test1.load_file("C:\\Users\\HP\\Desktop\\test2.txt");

		//lista_test1.add_end(74216742618);
		//auto end = std::chrono::steady_clock::now();
		//auto elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		//std::cout << elapsed_seconds.count() << std::endl;
		//lista_test.save_file("C:\\Users\\HP\\Desktop\\test1.txt");*/ 
		//lista_test.clear();
		//lista_test1.clear();
	//}
	//return 0;
//}

//dotyczy menu
void method_choice(list* lista) {
	bool cond = true;
	while (cond) {
		//system("CLS");
		unsigned int wybor;
		std::cout << "Wybierz jedna z opcji: (1-10) \n";
		std::cout << "1. Wczytaj liste z pliku. \n2. Zapisz liste do pliku. \n3. Dodaj element na poczatek listy. \n4. Dodaj element na koniec listy. \n5. Dodaj element w wybrane miejsce listy. \n";
		std::cout << "6. Usun pierwszy element listy. \n7. Usun ostatni element listy. \n8. Usun wybrany element listy. \n9. Wypisz liste. \n10. Znajdz element w liscie. \n";
		std::cin >> wybor;

		int element, index;
		std::string filename;
		switch (wybor) {
		case 1:
			std::cout << "Wpisz nazwe pliku: \n";
			std::cin >> filename;
			lista->load_file(filename);
			break;
		case 2:
			std::cout << "Wpisz nazwe pliku: \n";
			std::cin >> filename;
			lista->save_file(filename);
			break;
		case 3:
			std::cout << "Podaj element: \n";
			std::cin >> element;
			lista->add_begin(element);
			break;
		case 4:
			std::cout << "Podaj element: \n";
			std::cin >> element;
			lista->add_end(element);
			break;
		case 5:
			std::cout << "Podaj element i index: \n";
			std::cin >> element >> index;
			lista->add_ind(element, index);
		case 6:
			lista->delete_begin();
			break;
		case 7:
			lista->delete_end();
			break;
		case 8:
			std::cout << "Podaj index: \n";
			std::cin >> index;
			lista->delete_ind(index);
			break;
		case 9:
			lista->show();
			break;
		case 10:
			std::cout << "Podaj element: \n";
			std::cin >> element;
			lista->find(element);
			break;
		default:
			std::cout << "Powrot do menu.";
			cond = false;
			break;

		}
	}
}

void implem_choice() {

	std::cout << "Wybierz rodzaj implementacji: (1-3)\n";
	std::cout << "1. Tablica dynamiczna \n2. Lista jednokierunkowa [head] \n3. Lista jednokierunkowa [head i tail]. \n";
	unsigned int wybor;
	std::cin >> wybor;
	list* lista = nullptr;

	switch (wybor) {
	case 1:
		std::cout << "Tablica dynamiczna.\n";
		lista = new array_list(1);
		method_choice(lista);
		delete lista;
		break;

	case 2:
		std::cout << "Lista jednokierunkowa [head]. \n";
		lista = new singly_linked_list;
		method_choice(lista);
		delete lista;
		break;

	case 3:
		std::cout << "Lista jednokierunkowa [head i tail] \n";
		lista = new singly_linked_list_upgd;
		method_choice(lista);
		delete lista;
		break;

	default:
		std::cout << "Opuszczanie programu. \n";
		return;

	}

}


int main() {
	while (true) {
		implem_choice();
	}
	return 0;
}
