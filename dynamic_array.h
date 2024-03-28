#pragma once
#ifndef DYNAMIC_ARRAY_h
#define DYNAMIC_ARRAY_h

#include <iostream>
#include <cstdlib>

class dynamic_array {
private:
	int *array;
	int size;
	int capacity;

public:
	dynamic_array(int initialCapacity);
	~dynamic_array();
	void add_begin(int element);
	void add_end(int element);
	void add_random(int element);
	void delete_begin(int element);
	void delete_end(int element);
	void delete_random(int element);
	bool isEmpty();
	int getSize();
};

#endif
