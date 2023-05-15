#include <stdio.h>

/**
 * print_words - Splits a string into words and prints them.
 * @input: The input string.
 * @delimiter: The delimiter string.
 *
 * Return: void.
 */
void print_words(const char *input, const char *delimiter)
{
	int count = 0;
	char *copy = strdup(input);
	char **words = NULL;
	char *token;

	token = strtok(copy, delimiter);
	while (token != NULL)
	{
		count++;
		words = realloc(words, count * sizeof(char *));
		words[count - 1] = strdup(token);
		token = strtok(NULL, delimiter);
	}

	printf("Words:\n");
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", words[i]);
		free(words[i]);
	}
	free(words);
	free(copy);
}

/**
 * main - Entry point.
 *
 * Return: Always 0.
 */
int main(void)
{
	const char *input = "Hello, World! This is a test string.";
	const char *delimiter = " ,.!";

	print_words(input, delimiter);

	return (0);
}
