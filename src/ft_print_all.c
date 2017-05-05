/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 09:04:09 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_print_data(int max_len, char *str)
{
	int		len;

	len = (int)ft_strlen(str);
	printf("%-*s ", max_len, str);
}

void	ft_print_line(t_table *t)
{
	char	*str;

	str = ft_strnew((int)t->max_size);
	memset(str, '-', (int)t->max_size - 1);
	str[0] = 'o';
	str[(int)t->max_size - 1] = 'o';
	printf("%s", str);
	ft_strdel(&str);
	printf("\n");
}

void	ft_print_header(t_table *t)
{
	t_content	*data;
	t_column	*col;
	int			col_idx;
	char		*str;
	int			len;

	ft_print_line(t);
	col_idx = 0;
	printf("| Key ");
	while (col_idx < g_col_id)
	{
		if (t->col_id[col_idx] > 0)
		{
			printf("| ");
			col = &t->columns[col_idx];
			str = col->name;
			if (str && t->col_id[col_idx] > 0)
				ft_print_data((int)col->max_len, str);
		}
		col_idx++;
	}
	printf(" |\n");
	ft_print_line(t);
}

void	ft_print_row(t_table *t, int row_idx)
{
	t_content	*data;
	t_column	*col;
	int			col_idx;
	char		*str;

	printf("| ");
	col_idx = 0;
	printf("%03d ", t->row_id[row_idx]);
	while (col_idx < g_col_id)
	{
		if (t->col_id[col_idx] > 0)
		{
			printf("| ");
			col = &t->columns[col_idx];
			data = &col->content_array[row_idx];
			str = data->data;
			if (str && t->col_id[col_idx] > 0)
				ft_print_data((int)col->max_len, str);
		}
		col_idx++;
	}
	printf(" |\n");
}

void	ft_print_table(t_table *t)
{
	int			row_idx;
	int			len;

	row_idx = 0;
	ft_print_header(t);
	while (row_idx < g_row_id)
	{
		if (t->row_id[row_idx] > 0)
			ft_print_row(t, row_idx);
		row_idx++;
	}
	ft_print_line(t);
}
