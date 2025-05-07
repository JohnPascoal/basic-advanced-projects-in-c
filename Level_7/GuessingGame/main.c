// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-04 at 22:16:29
// Updated on: 2025-05-06 at 22:32:30
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 100

void	game_over(int attempt, int secret_number)
{	
	if (attempt)
		printf("You won, the correct number is %d!", secret_number);
	else
		printf("You lost, try again!");	
}

void	start(int secret_number, int *attempt)
{
	int	guess_number;
	int	check_type;

	do {
		printf("Enter a number: ");
		check_type = scanf("%d", &guess_number);
		if (check_type != 1)
		{
			printf("\'The number must be a digit\'\n");
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
	game_over(*attempt, secret_number);
}

int	main(void)
{
	int	secret_number;
	int	attempt;

	srand(time(NULL));
	secret_number = (rand() % (MAX - MIN + 1)) + MIN;
	attempt = 10;

	printf("\'Guess the secret number between %d and %d\'\n", MIN, MAX);
	start(secret_number, &attempt);

	return (0);
}
