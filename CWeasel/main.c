#include "Header.h"

int main() {
	int i;
	printf("Enter a string upto %d in length\n",MAX_GENE_L-1);
	fgets(target,MAX_GENE_L,stdin);
	for (i = 0; target[i] != '\n'; i++)
		;
	target[i] = '\0';
	//weasel_d();
	weasel_s();

	_CrtDumpMemoryLeaks();

	return 0;

}

