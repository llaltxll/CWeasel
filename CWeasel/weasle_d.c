#include "Header.h"

INDIVIDUAL* POPULATION[MAX_N_POP];

static INDIVIDUAL* populate(INDIVIDUAL* ancestor);

int weasel_d() {
	int generations = 1, len;
	time_t t;
	INDIVIDUAL* adam, * fittest;

	srand((unsigned)time(&t));

	adam = (INDIVIDUAL*)malloc(sizeof(INDIVIDUAL));
	if (adam == NULL) {
		printf("malloc() failed for adam.");
		exit(1);
	}

	len = strlen(target);
	rand_str(start, len);
	//printf("strlen %d\n", len);
	//printf("start string:\n%s\n", start);
	strcpy(adam->str, start);
	adam->score = fitness(adam->str);
	//printf("fitness: %d\n", adam->score);

	fittest = adam;
	printf("--------------start dynamic weasel----------------------\n");
	while (fittest->score < len) {
		fittest = populate(fittest);
		generations++;
		printf("generation[%4d ]\tfitness[%3d ]\tfittest str[ %s ]\n", generations, fittest->score, fittest->str);
	}
	//free_pop();
	free(fittest);
	free(adam);
	printf("----------------end dynamic weasel----------------------\n");
	return 0;
}

INDIVIDUAL* populate(INDIVIDUAL* ancestor) {
	INDIVIDUAL* newInd, * fittest;
	fittest = ancestor;


	for (int i = 0; i < MAX_N_POP; i++) {
		newInd = procreate(ancestor);
		POPULATION[i] = newInd;
		if (newInd->score > fittest->score) {
			fittest = newInd;
		}
		else
			free(newInd);

	}

	return fittest;
}

INDIVIDUAL* procreate(INDIVIDUAL* ancestor) {
	INDIVIDUAL* newInd;
	int i;


	newInd = (INDIVIDUAL*)malloc(sizeof(INDIVIDUAL));
	if (newInd == NULL) {
		printf("malloc() failed for newInd.");
		exit(1);
	}
	for (i = 0; ancestor->str[i]; i++) {
		if (rand() % 100 < ENTROPY)
			newInd->str[i] = rand_char();
		else
			newInd->str[i] = ancestor->str[i];
	}
	ancestor->str[i] = newInd->str[i] = ancestor->str[i];
	newInd->score = fitness(newInd->str);

	return newInd;
}


void free_pop() {

	for (int i = 0; i < MAX_N_POP; i++)
		free(POPULATION[i]);
}