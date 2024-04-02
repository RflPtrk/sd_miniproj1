#include "SinglyLinkedListH.h"
using namespace std;

SinglyLinkedListH::SinglyLinkedListH() : head(nullptr) {}

SinglyLinkedListH::~SinglyLinkedListH() 
    {
        node* current = head;
        while (current != nullptr) 
        {
            node* temp = current;
            current = current->next;
            delete temp;
            // pomocnicza, która przechowuje adres current wêz³a,
            // aby  nie utraciæ referencji do wêz³a, który ~~zostanie usuniêty.
        }
        head = nullptr;
    }

void SinglyLinkedListH::add_begin(int element) 
    {
        node* new_node = new node(element);
        new_node->next = head; //czyli nowy wêze³ wskazuje na obecny pierwszy element listy.
        head = new_node; //aktualizacja headu teraz ju¿ jako ten pierwszy element
    }

void SinglyLinkedListH::add_end(int element) 
    {
        node* new_node = new node(element);
        if (isEmpty()) 
        {
            head = new_node;
            // czyli zamiast isEmpty.
        }
        else 
        {
            node* current = head;
            while (current->next != nullptr) 
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }

void SinglyLinkedListH::add_ind(int element, int index) 
    {
        if (index < 0) 
        {
            std::cout << "Invalid index\n";
            return;
        }
        if (index == 0) 
        {
            add_begin(element);
        }
        else 
        {
            node* new_node = new node(element);
            node* current = head;
            for (int i = 0; i < index - 1 && current != nullptr; i++) 
            {
                current = current->next;
            }
            if (current == nullptr) 
            {
                std::cout << "Invalid index\n";
                //return;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }

void SinglyLinkedListH::delete_begin() 
    {
        if (isEmpty()) 
        {
            std::cout << "List is empty\n";
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

void SinglyLinkedListH::delete_end() 
    {
        if (isEmpty()) 
        {
            std::cout << "List is empty\n";
        }
        if (head->next == nullptr) 
        {
            delete head;
            head = nullptr;
        }
        else {
            node* current = head;
            while (current->next->next != nullptr) 
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

void SinglyLinkedListH::delete_ind(int index) 
    {
        if (index < 0) 
        {
            std::cout << "Invalid index\n";
        }
        if (index == 0) 
        {
        delete_begin();
        // lub return delete_begin();
        }
        node* current = head;
        for (int i = 0; i < index - 1 && current != nullptr; i++)
        {
            current = current->next;
        }
        if (current == nullptr || current->next == nullptr) 
        {
            std::cout << "Invalid index\n";
        }
        node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
bool SinglyLinkedListH::isEmpty() 
    {
        return head == nullptr; 
    }

void SinglyLinkedListH::show() 
    {
        node* current = head;
        while (current != nullptr) 
        {
            std::cout << "\nliczba: \n" << current->num << "\nAdres:\n " << current;
            current = current->next;
        }
        std::cout << std::endl;
    }

void SinglyLinkedListH::clear() 
    {
        node* current = head;
        while (current != nullptr) 
        {
            node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

bool SinglyLinkedListH::find(int element) 
    {
        node* current = head;
        while (current != nullptr) 
        {
            if (current->num == element) 
            {
                std::cout << "Number: " << element << std::endl;
                std::cout << "Adress: " << current << std::endl;
                return true;
            }
            current = current->next;
        }
        std::cerr << "No number found";
        return false;
    }

int SinglyLinkedListH::find_by_index(int index) 
    {
        if (index < 0) 
        {
            std::cout << "Invalid index\n";
            return 1;
        }
        node* current = head;
        for (int i = 0; i < index && current != nullptr; i++) 
        {
            current = current->next;
            //size fix
        }
        if (current == nullptr) 
        {
            //since not size
            std::cout << "Invalid index\n";
            return 1;
        }
        return current->num;
    }

void SinglyLinkedListH::load_file(const std::string& filename) 
    {
        std::ifstream file(filename);
        if (!file.is_open()) 
        {
            std::cerr << "issue with file, cannot open" << filename << std::endl;
            return;
        }
        int number;
        while (file >> number) 
        {
            add_end(number);
        }
        file.close();
    }

void SinglyLinkedListH::save_file(const std::string& filename) 
    {
        std::ofstream file(filename);
        if (!file.is_open()) 
        {
            std::cerr << "issue with file, cannot open " << filename << std::endl;
            return;
        }
        node* current = head;
        while (current != nullptr) 
        {
            file << current->num << "\n";
            current = current->next;
        }
        file.close();
    }
