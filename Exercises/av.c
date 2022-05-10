#include <stdio.h>

/**
 * main - prints all arguments without using ac
 * @ac: number of arguments in av
 * @av: array of strings (arguments)
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	while (av != NULL)
	{
		printf("%s\n", *av);
		av++;
	}
	return (0);
}
