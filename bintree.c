#include "bintree.h"

/**
 * Auch bintrees brauchen nicht per se numerische Schlüssel.
 * Was an bintrees besonders ist, ist, dass sie im Gegensatz zu hashtables eigentlich
 * immer schon sortiert sind.
 *
 * Damit inserts und selects aber wirklich immer nur log(n) Schritte brauchen, 
 * muss der bintree regelmäßig gebalanced werden. 
 */


void freeTree(node * nextnode){
	if(nextnode != 0){
		freeTree(nextnode->left);
		freeTree(nextnode->right);
		free(nextnode);
	}else{
		free(nextnode);
	}
}

node * makeNewNode(int key, node * parentnode){
	node * newnode = (node*) malloc( sizeof(node) );
	newnode->key_val = key;
	newnode->left = 0;
	newnode->right = 0;
	newnode->parent = parentnode;
	return newnode;
}


void insertInTree(int key, node * thisnode){
	if(key < thisnode->key_val){
		if(!thisnode->left){
			thisnode->left = makeNewNode(key, thisnode);
		}else{
			insertInTree(key, thisnode->left);
		}
	}else{
		if(!thisnode->right){
			thisnode->right = makeNewNode(key, thisnode);
		}else{
			insertInTree(key, thisnode->right);
		}
	}
}

node * findNode(int key, node * nextnode){
	if(nextnode->key_val = key){
		return nextnode;
	}else{
		if(key < nextnode->key_val){
			findNode(key, nextnode->left);
		}else{
			findNode(key, nextnode->right);
		}
	}
}



void balanceTree(node * root){
}


void printSortedVals(node * root){}
