/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:16:50 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 17:27:53 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_comp_cols(t_table *t, int row_id, int col_idx)
{
	t_content	*data;
	t_column	*col;
	char		*str;
	int			r_idx;

	r_idx = ft_find_row(row_id, t);
	col = &t->columns[col_idx];
	data = &col->content_array[r_idx];
	str = strdup(data->data);
	return (str);
}

void	ft_comp_rows(t_table *t, int col_idx, int **array,
						int asnd_dsnd)
{
	int			r_idx;
	int			*sort;
	int			size;

	sort = *array;
	size = g_row_id;
	while (size)
	{
		r_idx = 0;
		while (r_idx + 1 < size && sort[r_idx + 1] > 0)
		{
			if (asnd_dsnd)
				ft_sort_type_dsnd(t, col_idx, r_idx, &sort);
			else
				ft_sort_type_asnd(t, col_idx, r_idx, &sort);
			r_idx++;
		}
		size--;
	}
}
