/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 17:57:19 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static	int		ft_max_len(t_table *t)
{
	int		row_num;
	int		col_num;
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
			printf("%ds", data->data);
			col_num++;
		}
		row_num++;
	}
}

void			ft_print_handler(char **rec, t_table *t)
{
	int		row_num;
	int		col_num;
	t_content	*data;
	t_column	*col;

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
		row_num = 0;
		while (row_num < g_row_id)
		{
			col_num = 0;
			while (col_num < g_col_id)
			{
				col = &t->columns[col_num];
				data = &col->content_array[row_num];
				printf("%ds", data->data);
				col_num++;
			}
			printf("\n");
			row_num++;
		}

	}
	else if (rec[1][0] == 's')
		printf("print sorted?\n");
}