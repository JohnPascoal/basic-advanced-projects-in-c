// -----------------------------------------------------------------------------
// Arquivo: GuessingGame.c
// Autor: John Pascoal
// Criado em: 2025-05-04 às 22:16:29
// Actualizado em: 2025-05-05 às 09:38:55
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100

int	rand_secret_number(void)
{
	return ((rand() % (MAX - MIN + 1)) + MIN);
}

int	main(void)
{
	int	secretNumber;
	int	guess;
	int	check_type;

	srand(time(NULL));
	secretNumber = rand_secret_number();

	printf("\"Guess the secret number between %d and %d\"\n", MIN, MAX);
	do {
		printf("Enter a number: ");
		check_type = scanf("%d", &guess);

		if (check_type != 1)
		{
			printf("Put a number between %d and %d\n", MIN, MAX);
			while (getchar() != '\n');
            		guess = -1; 
		}
		else
		{
			if (guess != secretNumber)
			{
				if (guess > secretNumber)
					printf("\"The secret number is less\"\n");
				else
					printf("\"The secret number is greater\"\n");
			}
		}
	} while (guess != secretNumber);
	
	printf("You won, the correct number is %d!", secretNumber);
	
	return (0);
}
