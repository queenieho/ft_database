/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:04:40 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 23:00:12 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_empty_col(t_table *t)
{
	int		i;

	i = 0;
	while (i < COL_SIZE && t->col_id[i] != 0)
		i++;
	if (i >= COL_SIZE)
		return (-1);
	return (i);
}

int		ft_col_id_gen(void)
{
	g_col_id += 1;
	return (g_col_id);
}

void	ft_insert_new_data(t_column *col, int r_idx)
{
	while (r_idx >= 0)
	{
		col->content_array[r_idx].data = strdup("-");
		r_idx--;
	}
}

int		ft_insert_column(t_table *t, int num)
{
	int			idx;
	t_column	*col;
	int			r_idx;
	char		type;
	char		*name;

	while (num)
	{
		ERR1((idx = ft_empty_col(t)) == -1,
			ft_awk_moment("No more room for columns. Sorry!"), 0);
		name = ft_get_info("\nWhat is the column name?");
		type = ft_get_datatype();
		t->col_id[idx] = ft_col_id_gen();
		col = &(t->columns[idx]);
		col->type = type;
		col->name = name;
		col->name_len = strlen(col->name);
		ft_update_maxlen(col, col->name_len, &t->max_size);
		t->max_size += 3;
		if ((r_idx = ft_empty_row(t)) > 0)
			ft_insert_new_data(col, r_idx - 1);
		num--;
	}
	printf("%s Column %s%d%s inserted.\n\n", SUCCESS, G, t->col_id[idx], W);
	return (0);
}

char	ft_get_datatype(void)
{
	char	type;

	printf("\nWhat kind of data will this store?\n");
	printf(" [s] string\n");
	printf(" [i] integer\n");
	type = ft_readline()[0];
	return (type);
}
