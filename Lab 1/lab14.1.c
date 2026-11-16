#include <stdio.h>

char getColomnLetter(int n);
void printChessBoard();
void printDividerRow();
void printLabelsRow();

int main(void) 
{
	printChessBoard();

	getchar();
	return 0;
}

char getColomnLetter(int n)
{
	if (n < 1 || n > 8) return '?';

	return 'a' + n - 1;
}

void printChessBoard()
{
	printDividerRow();

	for (int i = 1; i <= 8; i++)
	{
		printLabelsRow(8 - i + 1);
		printDividerRow();
	}
}

void printDividerRow()
{
	for (int i = 1; i <= 8; i++)
	{
		printf("+----");
	}
	printf("+\n");
}

void printLabelsRow(int row)
{
	for (int i = 1; i <= 8; i++)
	{
		printf("| %c%d ", getColomnLetter(i), row);
	}
	printf("|\n");
}