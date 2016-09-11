

typedef struct row {
	int c1;
	char * c2;
} row;


typedef struct node {
	struct node * lwr;
	struct node * hgr;
	int midval;
	int isleaf;
	struct row * rowp;
} node;


row * scanIndexForVal(int valc1, node * root){
	node nextnode = *root;
	while(!nextnode.isleaf){
		if(valc1 < nextnode.midval)
			nextnode = *(nextnode.lwr);
		else
			nextnode = *(nextnode.hgr);
	}
	return nextnode.rowp;
}
