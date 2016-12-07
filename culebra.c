#include <stdio.h>
#define TAM 5

void Culebra (int (*)[]);

int main (int argc, char *argv[])
{
	int array[TAM][TAM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int i, j;
	
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			printf("%i\t", array[i][j]);
		}
		printf("\n");
	}
	printf("\n");printf("\n");
	Culebra(array);
	return 0;
}

void Culebra (int (*array)[TAM]) {
	int i, j;
	for (i = 0; i < TAM; i++) {
		if (i%2 == 0) {			
			for (j = 0; j < TAM; j++) {
				printf("%i\t", array[j][i]);
			}
		}
		else {
			for (j = TAM-1; j >= 0; j--) {
				printf("%i\t", array[j][i]);
			}
		}
		printf("\n");
	}
}
