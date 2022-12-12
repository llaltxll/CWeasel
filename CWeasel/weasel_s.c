#include "Header.h"


struct record {
	int fitness;
	int index;
};
struct record fittest = {
		0,
		0
};
char STRINGS[MAX_N_POP][MAX_GENE_L];
static void populate(char *);
int weasel_s() {
	int len, generations=0;
	time_t t;
	char temp[MAX_GENE_L];


	srand((unsigned)time(&t));
	//randomise a start string of the same length as target
	len = (int)strlen(target);
	//printf("strlen %d\n", len);
	rand_str(start, len);
	//printf("start string: %s, [len %d]\n", start, len);
	
	printf("--------------start static weasel----------------------\n");
	populate(start);
	while (fittest.fitness < len) {
		strcpy(temp, STRINGS[fittest.index]);
		populate(temp);
		generations++;
		printf("generation[%4d ]\tfitness[%3d ]\tfittest str[ %s ]\n",
			generations, fittest.fitness, STRINGS[fittest.index]);
	}
	printf("--------------end static weasel----------------------\n");
	return 0;
}

void populate(char *ancestor) {
	fittest.fitness = 0;
	fittest.index = 0;
	for (int i = 0; i < MAX_N_POP; i++) {
		for (int j = 0; target[j]; j++) {
			if (rand() % 100 < ENTROPY) {
				STRINGS[i][j] = rand_char();
			}
			else {
				STRINGS[i][j] = ancestor[j];
			}
		}


		if (fitness(STRINGS[i]) > fittest.fitness) {
			fittest.fitness = fitness(STRINGS[i]);
			fittest.index = i;
		}
	}
}