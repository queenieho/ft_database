/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:03:34 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 22:07:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_row_id_gen()
{
	g_row_id += 1;
	return(g_row_id);
}

int		ft_empty_row(t_table *t)
{
	int		idx;

	idx = 0;
	while (idx < ROW_SIZE && t->row_id[idx])
		idx++;
	return(idx);
}

void	ft_insert_row_data(t_column *col, int r_idx, int *max_size)
{
	t_content	*content;

	content = &col->content_array[r_idx];
	if (!(content->data = ft_get_info(col->name)))
		content->data = strdup("-");
	content->len = strlen(content->data);
	ft_update_maxlen(col, content->len, max_size);
}

void	ft_insert_row(t_table *t)
{
	int		c_idx;
	int		r_idx;

	c_idx = 0;
	if (!t->col_id[0])
		printf("No existing column, please insert at least one column\n");
	else
	{
		r_idx = ft_empty_row(t);
		t->row_id[r_idx] = ft_row_id_gen();
		while (c_idx < COL_SIZE && t->col_id[c_idx])
		{
			ft_insert_row_data(&t->columns[c_idx], r_idx, &t->max_size);
			c_idx++;
		}
		ft_print_row(t, r_idx);
	}
}
