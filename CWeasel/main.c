#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GENE_L 100
#define MAX_N_pop 500

struct genset {
	char str[MAX_GENE_L];
	int score;
};

typedef struct genset INDIVIDUAL;

char target[MAX_GENE_L], start[MAX_GENE_L];
INDIVIDUAL* population[MAX_N_pop];
void populate(INDIVIDUAL* ancestor);
char* rand_str(char *str, int n);
int fitness(INDIVIDUAL* ind);
int main() {
	int scan;
	time_t t;
	INDIVIDUAL *adam;

	adam=malloc(sizeof(INDIVIDUAL));
	if (adam == NULL) {
		printf("malloc() failed for adam.");
		exit(1);
	}
	printf("Enter a string upto %d in length\n",MAX_GENE_L-1);
	fgets(target,MAX_GENE_L,stdin);
	srand((unsigned)time(&t));
	printf("start string:\n%s\n", rand_str(start, strlen(target)) );
	strcpy(adam->str, start);
	adam->score = fitness(adam);
	printf("fitness: %d\n", adam->score);
	
	
	//populate()
}

void populate(INDIVIDUAL* ancestor) {

}

char* rand_str(char* str, int n) {
	char c;
	char c_range = '~' - ' ';
	int i;

	for (i = 0; i < n - 1; i++) {
		str[i] = rand() % c_range + ' ';
	}
	str[i] = '\0';

	return str;
}

int fitness(INDIVIDUAL *ind) {
	int f = 0;
	int i;

	for (i = 0; ind->str[i]; i++) {
		if (ind->str[i]==target[i]) {
			f++;
		}
	}
	return f;
}