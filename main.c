#include "shell.h"

/**
* interactive - this is the main function of the interactive
*	simple shell programe
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void interactive(int argc,__attribute__((unused)) char **argv)
{
	char *lineptr = NULL, *lineptr_cpy = NULL, **av = NULL;
	/*char *prompt = "$ ";*/
	size_t x = 0;
	int y = 0;
	ssize_t reach_char;
	const char *delim = " \n";

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		reach_char = getline(&lineptr, &x, stdin);
		if (reach_char == -1)
			break;
		if (reach_char == 1)
			continue;
		av = input_parser(lineptr, delim, &argc);
		argc = no_token(lineptr, delim);
		is_exit(av, lineptr, lineptr_cpy, argc);
		is_env(av);
		if (strcmp(av[0], "env") != 0)
			exec(av);
		for (y = 0; y < argc; y++)
			free(av[y]);
		free(av);

	}
	free(lineptr);
}
/**
* non_interactive - this is the main function of the interactive
*       simple shell programe
*@argc: this is an integer argument
*@argv: character pointer array
* Return: The function returns a value of 0 on success
*/

void non_interactive(int argc,__attribute__((unused)) char **argv)
{
	char *lineptr = NULL, *lineptr_cpy = NULL, **av = NULL;
	size_t x = 0;
	ssize_t reach_char = 0;
	const char *delim = " \n";
	int y;


	while (1)
	{
/*		reach_char = getline(&lineptr, &x, stdin);
		if (*lineptr != '\n')
		{
			lineptr[reach_char - 1] = '\0';
			printf("lineptr = %s\n", lineptr);
			lineptr_cpy = _alloc(reach_char);
			strcpy(lineptr_cpy, lineptr);
			if (check_space(lineptr) == 1)
			{
				free(lineptr_cpy);
				exit(0);
			}
			av = input_parser(lineptr, delim, &argc);
			argc = no_token(lineptr, delim);
			is_exit(av, lineptr, lineptr_cpy, argc);
			is_env(av);
			if (strcmp(av[0], "env") != 0)
				exec(argv);
			for (y = 0; y < argc; y++)
				free(av[y]);
			free(av);
		}
		free(lineptr);*/
		 reach_char = getline(&lineptr, &x, stdin);
                 if (reach_char == -1)
                         break;
                 if (reach_char == 1)
                         continue;
                 av = input_parser(lineptr, delim, &argc);
                 argc = no_token(lineptr, delim);
                 is_exit(av, lineptr, lineptr_cpy, argc);
                 is_env(av);
                 if (strcmp(av[0], "env") != 0)
                         exec(av);
                 for (y = 0; y < argc; y++)
                         free(av[y]);
                 free(av);
         }
         free(lineptr);
}

/**
*main - code for main function
*@argc: integer argument
*@argv: pointer array
*Return: returns 0
*/

int main(int argc, char **argv)
{
/*	char **temp;*/
	/*int y = 0;*/

	if (isatty(STDIN_FILENO))
	{
		interactive(argc, argv);
	}
	else
	{
		non_interactive(argc, argv);
	}
/*	temp = argv;*/

	/*if (temp != NULL)
	{
		for (; *temp != NULL; temp++)
		{
			free(*temp);
			*temp = NULL;
		}
		free(argv);
		argv = NULL;
	}*/
/*	for (y = 0; y <= argc; y++)
		free(argv[y]);
	free(argv);*/
	return (0);
}
