// -----------------------------------------------------------------------------
// Arquivo: GuessingGame.c
// Autor: John Pascoal
// Criado em: 2025-05-04 às 22:16:29
// Actualizado em: 2025-05-05 às 11:02:36
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100

void	run(int guess_number, int check_type, int secret_number, int *attempt)
{
	do {
		printf("Enter a number: ");
		check_type = scanf("%d", &guess_number);
		if (check_type != 1)
		{
			printf("\'The number must be a digit between %d and %d\'\n", MIN, MAX);
			while (getchar() != '\n');
			guess_number = -1;
		}
		else
		{
			if (guess_number != secret_number)
			{
				printf("Attempt: %d\n", --*attempt);
				if (guess_number > secret_number)
					printf("\'The secret number is less\'\n");
				else
					printf("\'The secret number is greater\'\n");
			}
		}
	} while (*attempt && guess_number != secret_number);	
}

int	main(void)
{
	int	secret_number;
	int	guess_number;
	int	check_type;
	int	attempt;

	srand(time(NULL));
	secret_number = (rand() % (MAX - MIN + 1)) + MIN;
	check_type = 1;
	guess_number = -1;
	attempt = 10;

	printf("\'Guess the secret number between %d and %d\'\n", MIN, MAX);
	run(guess_number, check_type, secret_number, &attempt);
	if (attempt != 0)
		printf("You won, the correct number is %d!", secret_number);
	else
		printf("You lost, try again!");
	
	return (0);
}
