#include <stdio.h>

void printTableHeader();

int main(void)
{
	printTableHeader();

	unsigned long long sum = 0;

	for (int i = 1; i <= 64; i++) {
		unsigned long long onField = (unsigned long long)1 << (i - 1);
		sum = ((unsigned long long)1 << i) - 1;
		printf("%5d | %20llu | %20llu (= %8.1e) \n", i, onField, sum, (double)sum);

		if (i % 8 == 0) printf("------+----------------------+---------------------------------\n");
	}

	double singleGrainWeight = 55e-6;
	double worldwideGrainsWeight = 735.5e9;

	printf("\nOverall grains: %llu\nSingle grain weight: %.0f mg (=%.1e kg)\nWorldwide grains production: %.1f million tons (=%.3e kg)\nP = %.2f\n",
		sum,
		singleGrainWeight * 1e6, singleGrainWeight,
		worldwideGrainsWeight * 1e-9, worldwideGrainsWeight,
		singleGrainWeight * sum / worldwideGrainsWeight
	);

	getchar();
	return 0;
}

void printTableHeader() 
{
	printf("Field | On field             | Sum\n");
	printf("------+----------------------+---------------------------------\n");
}