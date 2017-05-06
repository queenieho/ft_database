/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_row.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:03:34 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 20:07:09 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_row_id_gen(void)
{
	g_row_id += 1;
	return (g_row_id);
}

int		ft_empty_row(t_table *t)
{
	int		idx;

	idx = 0;
	while (idx < ROW_SIZE && t->row_id[idx] != 0)
		idx++;
	if (idx >= ROW_SIZE)
		return (-1);
	return (idx);
}

void	ft_insert_row_data(t_column *col, int r_idx, int *max_size)
{
	t_content	*content;

	content = &col->content_array[r_idx];
	content->data = ft_get_info(col->name);
	content->len = strlen(content->data);
	ft_update_maxlen(col, content->len, max_size);
}

void	ft_insert_row(t_table *t, int num)
{
	int		c_idx;
	int		r_idx;

	if (!t->col_id[0])
		printf("No existing column, please insert at least one column\n");
	else
	{
		while (num)
		{
			c_idx = 0;
			if ((r_idx = ft_empty_row(t)) == -1)
			{
				ft_awkward_moment("No more room for rows. Sorry!");
				return ;
			}
			t->row_id[r_idx] = ft_row_id_gen();
			while (c_idx < COL_SIZE && t->col_id[c_idx])
			{
				ft_insert_row_data(&t->columns[c_idx], r_idx, &t->max_size);
				c_idx++;
			}
			num--;
		}
	}
}
