// -----------------------------------------------------------------------------
// File: read_file.c
// Author: John Pascoal
// Created on: 2025-05-08 at 09:48:47
// Updated on: 2025-05-09 at 19:24:37
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_L 50

void	print(char* str);

int	read_words(char (*m)[MAX_L])
{
	FILE	*file;
	char	buffer[1024];
	int	n;

	n = 0;
	file = fopen("repository.txt", "r");

	if (!file)
	{
		printf("Error opening file");
		return (-1);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		size_t len = strlen(buffer);
        	if (len > 0 && buffer[len - 1] == '\n')
            		buffer[len - 1] = '\0';
       
		strcpy(m[n], buffer);
		n++;
	}
	
	fclose(file);
	return(n);
}

void	print(char* str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%c ", str[i]);
		i++;
	}
}

void	get_words(char *rand_word, char *w, char *t, char *u)
{
	int	i, j;

	i = 0;
	j = 0;
	while (rand_word[i] != '-')
	{
		w[i] = rand_word[i];
		i++;
	}
	w[i++] = '\0';
	while (rand_word[i])
	{
		t[j++] = rand_word[i];
		i++;
	}	
	t[j] = '\0';

	//printf("%s\n", tip);

	for (i = 0; i < strlen(w); i++)
		u[i] = '_';
	u[i] = '\0';
	print(u);
}

void	start(char m[][MAX_L])
{
	get_words(m
}

int	main(void)
{
	char	m[10][MAX_L];
	int	n_words;

	n_words = read_words(m);
	start(m);
	
	return (0);
}
