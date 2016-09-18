#include <stdlib.h>


typedef struct node {
	struct node * lwr;
	struct node * hgr;
	int key_val;
} node;


void freeTree(node * nextnode);

void insertInTree(int key, node * nextnode);

node * findNode(int key, node * nextnode);
