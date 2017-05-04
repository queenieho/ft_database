/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:07:30 by apineda           #+#    #+#             */
/*   Updated: 2017/05/04 14:23:28 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_print_handler(char **rec, t_table *t)
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

	// printf("print handler\n");
	// --print all
	// --print r search_col search_param
	// --print sorted??
	

	if (!rec[1])
		printf("print PRINT USAGE\n");

	if (rec[1][0] == 'r')
	{
		if ((row_num = ft_atoi(ft_get_info("What row number?")) >= 0))
			ft_print_row(t, row_num);
	}
	else if (rec[1][0] == 'a')
		ft_print_table(t);
	else if (rec[1][0] == 'c')
		ft_print_header(t);
	else if (rec[1][0] == 's')
		printf("print sorted?\n");
}
