// -----------------------------------------------------------------------------
// File: main.c
// Author: John Pascoal
// Created on: 2025-05-08 at 09:48:47
// Updated on: 2025-05-10 at 14:38:57
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 100

int	read_words(char (*m)[MAX_WORD_LENGTH]);
void	print_unknown_word(const char *unknown_word);
void	get_word_and_hint(const char *word_tip, char *target_word, char *hint, char *unknown_word);
char	*check_letter(char letter, char *target_word, char *unknown_word);
void	game_over(int attempt, const char *target_word);
void	start(const char *word_tip, int max_attempt);

int	main(void)
{
	char	words[MAX_WORDS][MAX_WORD_LENGTH];
	int	n_words;
	int	rand_index;

	n_words = read_words(words);
	if (n_words <= 0)
	{
		printf("Error: No words loaded\n");
		return (1);
	}
	srand(time(NULL));
	rand_index = (rand() % n_words);
	start(words[rand_index], 6);
	
	return (0);
}

int	read_words(char (*m)[MAX_WORD_LENGTH])
{
	FILE	*file;
	char	buffer[1024];
	int	word_count;

	word_count = 0;
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
		strcpy(m[word_count], buffer);
		word_count++;
	}
	
	fclose(file);
	return(word_count);
}

void	print_unknown_word(const char *unknown_word)
{
	int	i;

	i = 0;
	while (unknown_word[i])
	{
		printf("%c ", unknown_word[i]);
		i++;
	}
	printf("\n");
}

void	get_word_and_hint(const char *word_tip, char *target_word, char *hint, char *unknown_word)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (word_tip[i] != '-' && word_tip[i] != '\0')
	{
		target_word[i] = word_tip[i];
		i++;
	}
	target_word[i++] = '\0';
	while (word_tip[i])
	{
		hint[j++] = word_tip[i];
		i++;
	}	
	hint[j] = '\0';

	for (i = 0; i < strlen(target_word); i++)
		unknown_word[i] = '_';
	unknown_word[i] = '\0';
}

char	*check_letter(char letter, char *target_word, char *unknown_word)
{
	char*	result;

	result = strchr(target_word, letter);
	if (result != NULL)
	{
		unknown_word[result - target_word] = letter;
		target_word[result - target_word] = '_';
	}
	return (result);
}

void	game_over(int attempt, const char *target_word)
{
	if (attempt)
	{
		printf("Congratulations! You guessed the word.\n");
		printf("The coreect word is: %s", target_word);
	}
	else
		printf("Game over! You ran out of attempts.");
}

int	msg_except(char *guessed_letters, char guess, char *target_word, char *unknown_word, int *max_attempt)
{
	if (!isalpha(guess)) {
            printf("\nInvalid input. Please enter a letter.\n");
	    return (1);
        }

        if (strchr(guessed_letters, guess) != NULL) {
            printf("\nYou already tried that letter.\n");
	    return (1);
        }
	
        if (check_letter(guess, target_word, unknown_word) != NULL)
		printf("\nCorrect guess!\n");
	else
	{
		printf("\nIncorrect guess.\n",--*max_attempt);
		strncat(guessed_letters, &guess, 1);
	}
	return (0);
}

void	start(const char *word_tip, int max_attempt)
{
	char	target_word[MAX_WORD_LENGTH];
	char	hint[MAX_WORD_LENGTH];
	char	unknown_word[MAX_WORD_LENGTH];
	char	init_word[MAX_WORD_LENGTH];
	char	guessed_letters[max_attempt];
	char	guess_str[10];
	char	guess;

	get_word_and_hint(word_tip, target_word, hint, unknown_word);
	strcpy(init_word, target_word);
	printf("Hint: \'%s\'\n", hint);
	do {
		printf("Word: ");
		print_unknown_word(unknown_word);
		printf("Attempt left: %d\n", max_attempt);
		printf("Guessed letters: %s\n", guessed_letters);
		printf("Guess a letter: ");
		fgets(guess_str, sizeof(guess_str), stdin);
		guess = toupper(guess_str[0]);
		msg_except(guessed_letters, guess, target_word, unknown_word, &max_attempt);
	} while (max_attempt && strcmp(init_word, unknown_word));
	game_over(max_attempt, init_word);
}
