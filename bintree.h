#include <stdlib.h>


typedef struct node {
	struct node * left;
	struct node * right;
	struct node * parent;
	int key_val;
} node;


void freeTree(node * nextnode);

node * makeNewNode(int key, node * parentnode);

void insertInTree(int key, node * nextnode);

node * findNode(int key, node * nextnode);

void balanceTree(node * root);

void printSortedVals(node * root);
