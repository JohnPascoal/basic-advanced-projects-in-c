// -----------------------------------------------------------------------------
// Arquivo: GuessingGame.c
// Autor: John Pascoal
// Criado em: 2025-05-04 às 22:16:29
// Actualizado em: 2025-05-04 às 23:20:30
// -----------------------------------------------------------------------------

#include <stdio.h>

int	main(void)
{
	int	secretNumber;
	int	guess;

	secretNumber = 6;
	do {
	printf("Enter a number: ");
	scanf("%d", &guess);
	}while(guess != secretNumber);
	
	printf("you won, the correct number is %d!", secretNumber);
	return (0);
}
