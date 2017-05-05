/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:04:40 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 22:36:11 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_empty_col(t_table *t)
{
	int		i;

	i = 0;
	while (i < COL_SIZE && t->col_id[i])
		i++;
	return (i);
}

int		ft_col_id_gen()
{
	g_col_id += 1;
	return(g_col_id);
}

void	ft_insert_new_data(t_column *col, int r_idx)
{
	while (r_idx >= 0)
	{
		col->content_array[r_idx].data = strdup("-");
		r_idx--;
	}
}

void	ft_insert_column(t_table *t, int num)
{
	int			idx;
	t_column	*col;
	int			r_idx;
	char		type;
	char		*col_name;

	while (num)
	{
		col_name = ft_get_info("What is the column name?");
		type = ft_get_datatype();
		idx = ft_empty_col(t);
		t->col_id[idx] = ft_col_id_gen();
		col = &(t->columns[idx]);
		col->max_len = 0;
		col->type = type;
		col->name = name;
		col->name_len = strlen(col->name);
		ft_update_maxlen(col, col->name_len, &t->max_size);
		t->max_size += 3;
		if ((r_idx = ft_empty_row(t)) > 0)
			ft_insert_new_data(col, r_idx - 1);
		num--;
	}
	ft_print_header(t);
}

char	ft_get_datatype()
{
	char	type;

	printf("What kind of data will this store?\n");
	printf(" [s] string\n");
	printf(" [i] integer\n");
	printf(" [d] date\n");
	type = ft_readline()[0];
	return(type);
}
