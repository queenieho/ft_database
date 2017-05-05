/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:54:38 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 11:59:04 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_readline(void)
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
		t->columns[idx].content_array =
		(t_content *)malloc(sizeof(t_content) * ROW_SIZE);
		idx++;
	}
}

void	ft_print_intro(void)
{
	printf("%s*********************************************%s\n", R, W);
	printf("%s*                                           *%s\n", R, W);
	printf("%s*     Welcome to My_DBMS, our 42 ft_db!     *%s\n", R, W);
	printf("%s*                                           *%s\n", R, W);
	printf("%s*********************************************%s\n", R, W);
	// printf("Welcome to\n");
	// printf("    (`-')            _(`-')      (`-')    (`-')   (`-')    \n");
	// printf("    (OO )_          ( (OO )    __( OO)    (OO )_  ( OO)_   \n");
	// printf(",--./  ,-.),--.   ,-.\\    .'_ '-'---.\\,--./  ,-.)(_)--\\_)  \n");
	// printf("|   `.'   (`-')'.'  /'`'-..__)| .-. (/|   `.'   |/    _ /  \n");
	// printf("|  |'.'|  (OO \\    / |  |  ' || '-' `.)  |'.'|  |\\_..`--.  \n");
	// printf("|  |   |  ||  /   /) |  |  / :| /`'.  |  |   |  |.-._)   \\ \n");
	// printf("|  |   |  |`-/   /`  |  '-'  /| '--'  /  |   |  |\\       / \n");
	// printf("`--'   `--'  `--'    `------' `------'`--'   `--' `-----'  \n");
	// printf("Our 42 ft_db\n");
	printf("Here's some quick instructions: \n");
	printf(" help\n");
	printf(" insert\n");
	printf(" print\n");
	printf(" update\n");
	printf(" delete\n");
	printf(" save\n");
	printf(" exit\n");
}

int		main(void)
{
	char	*line;
	char	**av;
	t_table	table;

	line = NULL;
	g_col_id = 0;
	g_row_id = 0;
	ft_init_table(&table);
	ft_load_db(&table);
	ft_print_intro();
	while (1)
	{
		printf("\n%s My_DBMS %s- %s", DASH, R, W);
		line = ft_readline();
		av = ft_strsplit(line, ' ');
		free(line);
		ft_dbms(av[0], av, &table);
		// free(line);
		free(av);
	}
	return (0);
}
