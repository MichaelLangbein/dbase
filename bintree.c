#include <stdlib.h>


typedef struct node {
	struct node * lwr;
	struct node * hgr;
	int key_val;
} node;



void freeTree(node * root){
	if(root != 0){
		freeTree(root->lwr);
		freeTree(root->hgr);
		free(root);
	}else{
		free(root);
	}
}

void insertInTree(int key, node * nextnode){

	if(nextnode == 0){
	
		nextnode = (struct node*) malloc( sizeof( struct node ) );
		nextnode->key_val = key;
		nextnode->lwr = 0;    
		nextnode->hgr = 0; 
	}
	else{
		if(key < nextnode->key_val){
			insertInTree(key, nextnode->lwr);
		}
		else{
			insertInTree(key, nextnode->hgr);
		}
	}
}
