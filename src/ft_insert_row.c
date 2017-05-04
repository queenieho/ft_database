/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:03:34 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 14:42:47 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_row_id_gen()
{
	// printf("gen row id\n");
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
	content->data = ft_get_info(col->name);
	content->len = strlen(content->data);
	ft_update_maxlen(col, content->len, max_size);
	// printf("\ncol has a max len of %d\n\n", col->max_len);
	// printf("You have entered %s of len %d\n", content->data, content->len);
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
		// printf("First empty row is at index %d and has id %d\n", r_idx, t->row_id[r_idx]);
		while (c_idx < COL_SIZE && t->col_id[c_idx])
		{
			ft_insert_row_data(&t->columns[c_idx], r_idx, &t->max_size);
			c_idx++;
		}
	}
}
