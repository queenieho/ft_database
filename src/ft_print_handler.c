/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:07:30 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 17:39:49 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			ft_search_header(t_table *t, char *find)
{
	t_content	*data;
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

static	int	ft_search_col(t_table *t, int row_idx, int col_idx, char *find)
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

static	int	ft_search_row(t_table *t, char *str, int col_idx)
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

void		ft_print_filtered(t_table *t)
{
	char	*str;
	int		col_idx;

	ft_print_header(t);
	str = ft_get_info("What column would you like to filter");
	if (str)
	{
		col_idx = ft_search_header(t, str);
		if (col_idx >= 0)
		{
			str = ft_get_info("What would you like to filter for?");
			if (str)
			{
				if (ft_search_row(t, str, col_idx) == -1)
					printf("Search of %s was not found.\n", str);
			}
		}
	}
}

int			ft_find_last_row(t_table *t, int last_row)
{
	while (last_row <= 0 && t->row_id[last_row] == -1)
		last_row--;
	return (last_row);
}

void		ft_print_row_handler(char **rec, t_table *t)
{
	int		num1;
	int		num2;

	if (!rec[2])
		ft_print_help_print();
	else if (rec[2] && rec[3])
	{
		num1 = ft_find_row(ft_atoi(rec[2]), t);
		if ((num2 = ft_find_row(ft_atoi(rec[3]), t)) == -1)
			num2 = ft_find_last_row(t, ft_empty_row(t) - 1);
		if (num1 >= 0 && num2 >= 0)
			ft_print_selected(t, num1, num2);
		else if (num1 >= 0)
			ft_print_selected(t, num1, -1);
	}
	else if (rec[2])
	{
		num1 = ft_find_row(ft_atoi(rec[2]), t);
		if (num1 >= 0)
			ft_print_selected(t, num1, -1);
	}
}

void		ft_print_handler(char **rec, t_table *t)
{
	int		num1;
	int		num2;

	if (!rec[1])
		ft_print_help_print();
	else if (rec[1][0] == 'r')
		ft_print_row_handler(rec, t);
	else if (rec[1][0] == 'a')
		ft_print_table(t);
	else if (rec[1][0] == 'c')
		ft_print_header(t);
	else if (rec[1][0] == 'f')
		ft_print_filtered(t);
	else if (rec[1][0] == 's')
	{
		printf("print sorted\n");
		ft_print_sorted(t);
	}
}
