#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	srand(argc == 3 ? atoi(argv[2]) : time(NULL));
	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	char **square = new char* [n];
	for (int i = 0; i < n; i++)
	{
		square[i] = new char[n];
	}

	for (int i = 0; i < n*n; i++)
	{	
		char sign = 'a' + rand()%('z'-'a');
		square[i/n][i%n] = sign;
	}

	return square;
}

void drawCharSquare(char **square, int n)
{
	for (int i = 0; i < n * n; i++)
	{	
		printf("%c%c", square[i/n][i%n], i%n == n-1 ? '\n': ' ');
		
	}
}