/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 14:42:53 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_max_len(t_table *t)
{
	int		row_num;
	int		col_num;
	int		max;
	t_content	*data;
	t_column	*col;

	row_num = 0;
	while (row_num < g_row_id)
	{
		col_num = 0;
		while (col_num < g_col_id)
		{
			col = &t->columns[col_num];
			data = &col->content_array[row_num];
			if (data->len >= max)
				max = data->len;
			col_num++;
		}
		row_num++;
	}
	return (max);
}

// char	*ft_get_info(char *ask)
// {
// 	char	*ans;

// 	printf("%s\n", ask);
// 	ans = strtok(ft_readline(), "\n");
// 	return (ans);
// }

static	void	ft_print_dash(t_table *t)
{	
	int		row_num;
	int		col_num;
	t_content	*data;
	t_column	*col;
	int			max;
	char		*str;

	max = ft_max_len(t);
	row_num = 0;
	while (row_num < g_row_id)
	{
		col_num = 0;
		while (col_num < g_col_id)
		{
			col = &t->columns[col_num];
			data = &col->content_array[row_num];
			str = ft_strnew(max);
			memset(str, '-', max);
			printf("%s", str);
			printf("%s", data->data);
			col_num++;
		}
		printf("\n");
		row_num++;
	}
}

void			ft_print_handler(char **rec, t_table *t)
{
	int		row_num;
	int		col_num;
	t_content	*data;
	t_column	*col;
	int			max;

	// t->col_id[]
	// t->row_id[]
	// t->columns[]
	// t->columns[]->type
	// t->columns[]->name
	// t->columns[]->namelen
	// t->columns[]->content_array->data
	// data = &(t->columns[idx]);
	printf("print handler\n");
	// --print all
	// --print r search_col search_param
	// --print sorted??
	

	if (!rec[1])
		printf("print PRINT USAGE\n");

	if (rec[1][0] == 'r')
		printf("print specific record\n");
	else if (rec[1][0] == 'a')
	{
		ft_print_dash(t);
	}
	else if (rec[1][0] == 's')
		printf("print sorted?\n");
}