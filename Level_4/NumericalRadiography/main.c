// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-06 at 21:50:47
// Updated on: 2025-05-07 at 12:12:57
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <math.h>

void	print(char signal[], char parity[], char magnitude[], char divisibility[])
{
	printf("\nSignal:\n\t%s\n", signal);
	printf("Parity:\n\t%s\n", parity);
	printf("Magnitude:\n\t%s\n", magnitude);
	printf("Divisibility:\n\t%s", divisibility);
}

int	is_prime(int value)
{
	int	i;

	if (value == 2)
		return (1);
	if (value < 2 || !(value % 2))
		return (0);

	i = 3;
	while (i <= sqrt(value))
	{
		if (!(value % i))
			return (0);
		i += 2;
	}
	return (1);
}

void	comp(float value, char *s, char *p, char *m, char *d)
{
	if (value > 0)
		strcpy(s, "Positive");
	else if (value < 0)
		strcpy(s, "Negative");
	else
		strcpy(s, "Neutro");

	if (value == (int)value)
	{
		strcpy(m, "Integer");
		if ((int)value % 2 == 0)
			strcpy(p, "Even");
		else
			strcpy(p, "Odd");

		if (value >= 2)
		{
			if (is_prime((int)value))
				strcpy(d, "Prime");
			else
				strcpy(d, "Composite");
		}
		else
			strcpy(d, "N/A");
	}
	else
	{
		strcpy(m, "Decimal");
		strcpy(p, "-------");
		strcpy(d, "N/A");
	}
}
void	start(float value)
{
	char    signal[9];
        char    parity[9];
        char    magnitude[10];
        char    divisibility[10];

	comp(value, signal, parity, magnitude, divisibility);
	print(signal, parity, magnitude, divisibility);
}

int	main(void)
{
	float	value;
	
	printf("Enter a number: ");
        scanf("%f", &value);
	
	start(value);
	return (0);
}
