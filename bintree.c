#include <stdlib.h>


typedef struct node {
	struct node * lwr;
	struct node * hgr;
	int key_val;
} node;



void freeTree(node * nextnode){
	if(nextnode != 0){
		freeTree(nextnode->lwr);
		freeTree(nextnode->hgr);
		free(nextnode);
	}else{
		free(nextnode);
	}
}


void insertInTree(int key, node * nextnode){
	if(nextnode == 0){
	
		nextnode = (struct node*) malloc( sizeof( struct node ) );
		nextnode->key_val = key;
		nextnode->lwr = 0;    
		nextnode->hgr = 0; 
	}else{
		if(key < nextnode->key_val){
			insertInTree(key, nextnode->lwr);
		}else{
			insertInTree(key, nextnode->hgr);
		}
	}
}

node * findNode(int key, node * nextnode){
	if(nextnode->key_val = key){
		return nextnode;
	}else{
		if(key < nextnode->key_val){
			findNode(key, nextnode->lwr);
		}else{
			findNode(key, nextnode->hgr);
		}
	}
}
