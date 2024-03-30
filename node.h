#pragma once
#ifndef SD1_NODE_H
#define SD1_NODE_H
class node {
	int num;
	node* next;
public:
	node(int number) :num(number), next(nullptr) {};
};

#endif