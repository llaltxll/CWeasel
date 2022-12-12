#include "Header.h"

char* rand_str(char* str, int n) {
	int i;

	for (i = 0; i < n ; i++) {
		str[i] = rand_char();
	}
	str[i] = '\0';

	return str;
}
char rand_char() {
	char c;
	char c_range = '~' - ' ';
	c = rand() % c_range + ' ';

	return c;
}
int fitness(char *str) {
	int f = 0;
	int i;

	for (i = 0; str[i]; i++) {
		if (str[i] == target[i]) {
			f++;
		}
	}
	return f;
}