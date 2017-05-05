/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:07:30 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 02:04:23 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_search_header(t_table *t, char *find)
{
	t_content	*data;
	t_column	*col;
	int			col_idx;
	char		*str;
	int			len;

	col_idx = 0;
	while (col_idx < g_col_id)
	{
		col = &t->columns[col_idx];
		str = col->name;
		if (str && t->col_id[col_idx] > 0)
			if(!(ft_strcmp(str, find)))
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

	ft_print_header(t);
	row_idx = 0;
	while (row_idx < g_row_id)
	{
		if(t->row_id[row_idx] > 0)
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

void			ft_print_filtered(t_table *t)
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

void			ft_print_handler(char **rec, t_table *t)
{
	int		num1;
	int		num2;

	if (!rec[1])
		printf("print PRINT USAGE\n");
	else if (rec[1][0] == 'r')
	{
		if (rec[2] && rec[3])
		{
			num1 = ft_find_row(ft_atoi(rec[2]), t);
			num2 = ft_find_row(ft_atoi(rec[3]), t);
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
	else if (rec[1][0] == 'a')
		ft_print_table(t);
	else if (rec[1][0] == 'c')
		ft_print_header(t);
	else if (rec[1][0] == 'f')
		ft_print_filtered(t);
	else if (rec[1][0] == 's')	
		ft_print_sorted(t);
}
