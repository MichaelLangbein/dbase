#include "bintree.h"
#include "hash.h"


int main(){

	// Zuerst ein bintree
	
	int data[] = {1,4,6,9,12,17,178};
	int arrlen = sizeof(data)/sizeof(int);

	node root = {0,0,0};	
	
	int i;
	for(i=0; i<arrlen; i++){
		insertInTree(data[i], &root);	
	}
}
