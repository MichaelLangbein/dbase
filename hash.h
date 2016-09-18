#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct element{
	char * key;
	char * value;
	struct element * next_element;
} element;


typedef struct hashtable{
	int max_nr_bins;
	element ** elements;
} hashtable;


int hash_function(char * key, int max_nr_bins);

void hash_insert(hashtable * ht, char * key, char * value);

char * hash_get(hashtable * ht, char * key);

void hash_free_element(hashtable * ht, char * key);

void hash_free(hashtable * ht);
