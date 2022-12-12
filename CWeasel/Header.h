#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include <time.h>

#ifndef WEASLE

#define _CRTDBG_MAP_ALLOC	
#define MAX_GENE_L	100
#define MAX_N_POP	500
#define ENTROPY		5


struct genset {
	char str[MAX_GENE_L];
	int score;
};

typedef struct genset INDIVIDUAL;

int weasel_s();
int weasel_d();
char target[MAX_GENE_L], start[MAX_GENE_L];

char* rand_str(char* str, int n);
INDIVIDUAL* procreate(INDIVIDUAL* ancestor);
void free_pop();
char rand_char();

#endif // !WEASLE