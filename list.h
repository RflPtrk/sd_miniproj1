#pragma once
#ifndef SD1_LIST_H
#define SD1_LIST_H

class list {
public:
	list() = default;
	~list() = default;

	virtual void add_begin(int element) = 0;
	virtual void add_end(int element) = 0;
	virtual void add_ind(int element, int index) = 0;

	virtual void delete_begin() = 0;
	virtual void delete_end() = 0;
	virtual void delete_ind(int index) = 0;

	virtual void load_file(const std::string& filename) = 0;
	virtual void save_file(const std::string& filename) = 0;
	virtual void show() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	virtual int find_by_index(int index) = 0;
	virtual bool find(int element) = 0;
};
#endif // !SD1_LIST_H
