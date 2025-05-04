// -----------------------------------------------------------------------------
// Arquivo: GuessingGame.c
// Autor: John Pascoal
// Criado em: 2025-05-04 às 22:16:29
// Actualizado em: 2025-05-05 às 00:27:48
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 10

int	rand_secret_number(void)
{
	srand(time(NULL));

	return ((rand() % (MAX - MIN + 1)) + MIN);
}

int	main(void)
{
	int	secretNumber;
	int	guess;

	secretNumber = rand_secret_number();

	printf("Guess the correct number between %d and %d!\n", MIN, MAX);
	do {
		printf("Enter a number: ");
		scanf("%d", &guess);
	} while (guess != secretNumber);
	
	printf("You won, the correct number is %d!", secretNumber);
	
	return (0);
}
