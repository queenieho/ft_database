/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:37:33 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 17:50:09 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
		perror("failed to open file");
	return (fd);
}

int		ft_open_file_update(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		perror("failed to open file");
	return (fd);
}

void	ft_close_file(int fd)
{
	close(fd);
}

void	ft_insert_col_header(char *header, int len)
{
	printf("inserting %s of len %d\n", header, len);
}

void	ft_save_handler(t_table *t)
{
	int		fd;
	int		c_idx;
	int		r_idx;

	fd = ft_open_file(FILENAME);
	c_idx = 0;
	r_idx = 0;
	// printf("%d\n", t->col_id[c_idx]);
	while (c_idx < COL_SIZE && t->col_id[c_idx] != 0)
	{
		// printf("%d\n", t->col_id[c_idx]);
		printf("Need to insert %s of len %d\n", t->columns[c_idx].name, t->columns[c_idx].name_len);
		ft_insert_col_header(t->columns[c_idx].name, t->columns[c_idx].name_len);
		c_idx++;
	}
	if (t->row_id[r_idx])
		printf("need to insert rows\n");

	ft_close_file(fd);
}