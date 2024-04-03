#pragma once
#ifndef SD1_SINGLY_LINKED_LIST_h
#define SD1_SINGLY_LINKED_LIST_h
#include <iostream>
#include "list.h"
#include "node.h"
#include <fstream>

class singly_linked_list : public list {
protected:
	node* head;

public:
	singly_linked_list();
	~singly_linked_list();

	void add_begin(int element)override;
	void add_end(int element)override;
	void add_ind(int element, int index)override;
	void delete_begin()override;
	void delete_end()override;
	void delete_ind(int index)override;
	bool isEmpty()override;
	void show()override;
	void clear()override;
	bool find(int element)override;
	int find_by_index(int index)override;
	void load_file(const std::string& filename)override;
	void save_file(const std::string& filename)override;
};

#endif