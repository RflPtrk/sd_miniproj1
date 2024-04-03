#pragma once
#ifndef SD1_SINGLY_LINKED_LIST_UPGD_H
#define SD1_SINGLY_LINKED_LIST_UPGD_H

#include "singly_linked_list.h"

class singly_linked_list_upgd :public singly_linked_list {
	node* tail;
public:
	singly_linked_list_upgd() :singly_linked_list(), tail(nullptr) {};
	~singly_linked_list_upgd();
	void add_end(int element)override;
	void delete_end()override;
	void clear()override;
};
#endif
