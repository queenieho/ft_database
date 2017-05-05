/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:54:38 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 01:46:22 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_db_exe(char **av, t_table *table)
{
	pid_t	pid; 
	pid_t	wpid;
  	int		status;

	pid = fork();
	if (pid < 0)
		perror("sql"); // Error forking
	else if (pid == 0) // Child process
	{
		// printf("Child process\n");
		if (ft_dbms(av[0], av, table) == -1) 
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else	// Parent process
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

char	*ft_readline()
{
	char	*line;
	size_t	bufsize;

	line = NULL;
	bufsize = 0;
	getline(&line, &bufsize, stdin);
	return (line);
}

void	ft_init_table(t_table *t)
{
	int	idx;

	idx = 0;
	bzero(t->col_id, sizeof(int) * COL_SIZE);
	bzero(t->row_id, sizeof(int) * ROW_SIZE);
	t->columns = (t_column *)malloc(sizeof(t_column) * COL_SIZE);
	while (idx < COL_SIZE)
	{
		t->columns[idx].content_array = (t_content *)malloc(sizeof(t_content) * ROW_SIZE);
		idx++;
	}
}

int 	main()
{
	char	*line;
	char	**av;
	t_table	table;

	line = NULL;
	g_col_id = 0;
	g_row_id = 0;
	ft_init_table(&table);

	printf("%s***************************************%s\n", R, W);
	printf("%s*  Welcome to My_DBMS, our 42 ft_db!  *%s\n", R, W);
	printf("%s***************************************%s\n", R, W);
	printf("Here's some quick instructions: \n");
	printf(" --insert c column_name\n"); 	// insert column to table
	printf(" --insert r\n");	// insert record
	printf(" --print all\n"); // print full table
	printf(" --print r search_col search_param\n");	// print specific record
	printf(" --edit r \n");	// update record HOW TO DO THIS?
	printf(" --delete r search_col search_param\n");	// delete record NOT SURE
	printf(" --delete c column_name??\n");	// delete column? 
	printf("\n --help for usage\n\n");
	
	ft_load_db(&table);
	while (1)
	{
		printf("%s My_DBMS %s- %s", DASH, Y, W);
		line = ft_readline();
		av = ft_strsplit(line, ' ');
		ft_dbms(av[0], av, &table);
		free(line);
		free(av);		
	}
	return (0);
}
