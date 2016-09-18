#include <stdio.h>


typedef struct element{
	int key;
	char * value;
} element;


typedef struct hashtable{
	int max;
	int number_of_elements;
	element ** elements;
} hashtable;


int hashf(int key, int try, int max){
	return (key + try)%max;
}


int hash_insert(hashtable * ht, element * el){
	int try;
	int hash;
	
	if(ht->number_of_elements >= ht->max) return 0;
	while

}
