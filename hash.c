#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Funktionsweise:
 * Elemente müssen in einem array untergebracht werden. 
 * Wir wollen, dass der array anhand eines keys indiziert, nicht anhand des array-indices.
 * Dafür müssen wir also keys (strings) auf array-indices (ints) mappen.Das macht die hashfunktion.
 * Eine hashfunktion gibt für einen key einen arrayindex aus, worin dieses element untergebracht werden soll.
 * Der arrayindex (der hash) ist jedoch nicht für jeden key einzigartig. 
 * Anstelle dessen bringen wir in jedem array-element eine linked list unter. Diese liste besteht aus all jenen elementen,
 * für die die jeweils einzigartigen keys ein und denselben hash ergeben haben.
 * Der hash ist also nicht eine 1-1 zuordnung, sondern eine erste gruppierung.
 *
 * Einfügen:
 * key to hash
 * element in linkedlist hinter hash
 *
 * Auslesen:
 * key to hash
 * foreach element in linkedlist: key == gesuchter key?
 */

typedef struct element{
	char * key;
	char * value;
	struct element * next_element;
} element;


typedef struct hashtable{
	int max_nr_bins;
	element ** elements;
} hashtable;


int hash_function(char * key, int max_nr_bins) {

	int keylength = strlen(key);
	int sum = 0;

	int i;
	for (i=0; i < keylength; i++){
		sum += (int)key[i];
	}
	return sum % max_nr_bins;
}


void hash_insert(hashtable * ht, char * key, char * value){
	element * el = malloc(sizeof(element));
	el->key = key;
	el->value = value;
	int hash = hash_function(key, ht->max_nr_bins);
	element * currentel = ht->elements[hash];
	while(currentel->next_element){
		currentel = currentel->next_element;
	}
	currentel->next_element = el;
}

char * hash_get(hashtable * ht, char * key){
	int hash = hash_function(key, ht->max_nr_bins);
	element * currentel = ht->elements[hash];
	if(currentel->value == key){
		return currentel->value;
	}
	while(currentel->next_element){
		currentel = currentel->next_element;
		if(currentel->value == key){
			return currentel->value;
		}
	}
	return "Element not found!\n";
}

void hash_free_element(hashtable * ht, char * key){
			
}

void hash_free(hashtable * ht){}

int main(){
	hashtable ht;
	ht.max_nr_bins = 5;
	element e1 = {"alpha", "value one"};
	element e2 = {"beta", "value one"};
	element e3 = {"gamma", "value one"};
	element e4 = {"epsilon", "value one"};
	element e5 = {"delta", "value one"};
	element e6 = {"theta", "value one"};
	return 0;
}
