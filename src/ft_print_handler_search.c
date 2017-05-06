/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler_search.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:36:43 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 18:40:50 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			ft_search_header(t_table *t, char *find)
{
	t_column	*col;
	int			col_idx;
	char		*str;
	int			len;
	int			i;

	col_idx = 0;
	while (col_idx < g_col_id)
	{
		col = &t->columns[col_idx];
		str = col->name;
		i = 0;
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
		if (str && t->col_id[col_idx] > 0)
			if (!(ft_strcmp(str, find)))
				return (col_idx);
		col_idx++;
	}
	return (-1);
}

int			ft_search_col(t_table *t, int row_idx, int col_idx, char *find)
{
	t_content	*data;
	t_column	*col;
	char		*str;
	int			ret;

	ret = 0;
	col = &t->columns[col_idx];
	data = &col->content_array[row_idx];
	str = data->data;
	if (ft_strstr(str, find))
	{
		ret = 1;
	}
	return (ret);
}

int			ft_search_row(t_table *t, char *str, int col_idx)
{
	int			row_idx;
	int			len;
	int			ret;

	row_idx = 0;
	ft_print_header(t);
	while (row_idx < g_row_id)
	{
		if (t->row_id[row_idx] > 0)
		{
			if (ft_search_col(t, row_idx, col_idx, str))
			{
				ft_print_row(t, row_idx);
				ret = 1;
			}
		}
		row_idx++;
	}
	ft_print_line(t);
	return (ret);
}

int			ft_find_last_row(t_table *t, int last_row)
{
	while (last_row <= 0 && t->row_id[last_row] == -1)
		last_row--;
	return (last_row);
}
