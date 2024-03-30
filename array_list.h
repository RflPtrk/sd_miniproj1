#pragma once
#ifndef SD1_ARRAY_LIST_h
#define SD1_ARRAY_LIST_h

#include "list.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

class array_list: public list {
private:
	int *array;
	int size;
	int capacity;

public:
	array_list();
	array_list(int array_size);
	~array_list();
	void add_begin(int element)override;
	void add_end(int element)override;
	void add_ind(int element, int index)override;
	void delete_begin()override;
	void delete_end()override;
	void delete_ind(int index)override;
	bool isEmpty()override;
	int getSize();
	int getCapacity();
	void enlarge();
	void show()override;
	void clear()override;
	bool find(int element)override;
	int find_by_index(int index)override;
	void load_file(const std::string& filename)override;
	void save_file(const std::string& filename)override;
};

#endif
