#pragma once
#ifndef SD1_NODE_H
#define SD1_NODE_H
class node {
public:
int num;
node* next;
node(int number) :num(number), next(nullptr) {};
};

#endif
