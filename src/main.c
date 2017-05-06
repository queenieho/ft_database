/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:54:38 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 18:38:58 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_find_col_index(t_table *t, int col_id)
{
	int c_idx;

	c_idx = 0;
	while (c_idx < COL_SIZE && t->col_id[c_idx])
	{
		if (t->col_id[c_idx] == col_id)
			return (c_idx);
		c_idx++;
	}
	return (-1);
}

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
	int	c_idx;
	int r_idx;

	c_idx = 0;
	bzero(t->col_id, sizeof(int) * COL_SIZE);
	bzero(t->row_id, sizeof(int) * ROW_SIZE);
	t->columns = (t_column *)malloc(sizeof(t_column) * COL_SIZE);
	while (c_idx < COL_SIZE)
	{
		r_idx = 0;
		bzero(&t->columns[c_idx], sizeof(t_column));
		t->columns[c_idx].content_array =
		(t_content *)malloc(sizeof(t_content) * ROW_SIZE);
		while (r_idx < ROW_SIZE)
		{
			bzero(&t->columns[c_idx].content_array[r_idx], sizeof(t_content));
			r_idx++;
		}
		c_idx++;
	}
}

void	ft_print_intro(void)
{
	printf("%s*********************************************%s\n", R, W);
	printf("%s*                                           *%s\n", R, W);
	printf("%s*     Welcome to My_DBMS, our 42 ft_db!     *%s\n", R, W);
	printf("%s*                                           *%s\n", R, W);
	printf("%s*********************************************%s\n", R, W);
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
	int		status;
	int		i;

	i = 0;
	status = 1;
	line = NULL;
	g_col_id = 0;
	g_row_id = 0;
	ft_init_table(&table);
	ft_load_db(&table);
	ft_print_intro();
	while (status)
	{
		printf("\n%s My_DBMS %s- %s", DASH, R, W);
		line = ft_readline();
		av = ft_strsplit(line, ' ');
		status = ft_dbms(av[0], av, &table);
		free(line);
		free(av);
	}
	return (0);
}
