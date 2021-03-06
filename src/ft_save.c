/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:37:33 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 18:34:56 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_gen_row(t_column *col, int r_idx, t_table *t)
{
	char	*row;
	int		c_idx;

	c_idx = 1;
	row = ft_init_row(col[0].content_array[r_idx]);
	while (c_idx < COL_SIZE && col[c_idx].name)
	{
		if (t->col_id[c_idx] > 0)
			row = ft_append_to_row(row, col[c_idx].content_array[r_idx]);
		c_idx++;
	}
	return (row);
}

void	ft_save_rows(int fd, t_table *t)
{
	int		r_idx;
	int		len;
	char	*row_string;

	r_idx = 0;
	len = 0;
	while (r_idx < ROW_SIZE && t->row_id[r_idx])
	{
		if (t->row_id[r_idx] > 0)
		{
			row_string = ft_gen_row(t->columns, r_idx, t);
			len = strlen(row_string);
			write(fd, row_string, len);
			write(fd, "\n", 1);
			free(row_string);
		}
		r_idx++;
	}
}

char	*ft_gen_header(t_column col, int *len)
{
	char	*header;
	int		i;

	i = 2;
	*len = col.name_len + 3;
	header = (char *)malloc(sizeof(char) * (*len + 1));
	ft_insert_type(&header, col.type);
	header = strcat(header, col.name);
	header = strcat(header, ",");
	return (header);
}

void	ft_save_col_header(int fd, t_column col)
{
	char	*header;
	int		len;

	header = ft_gen_header(col, &len);
	write(fd, header, len);
	free(header);
}

void	ft_save_handler(t_table *t)
{
	int		fd;
	int		c_idx;

	fd = ft_open_file(FILENAME);
	c_idx = 0;
	while (c_idx < COL_SIZE && t->col_id[c_idx] != 0)
	{
		if (t->col_id[c_idx] > 0)
			ft_save_col_header(fd, t->columns[c_idx]);
		c_idx++;
	}
	write(fd, "\n", 1);
	if (t->row_id[0])
		ft_save_rows(fd, t);
	ft_close_file(fd);
}
