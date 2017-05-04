/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 16:25:45 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	ft_find_row(int r_id, t_table *t)
{
	int		r_idx;

	r_idx = 0;
	while (r_idx < ROW_SIZE && t->row_id[r_idx])
	{
		if (t->row_id[r_idx] == r_id)
			return (r_idx);
		r_idx++;
	}
	return (-1);
}

void	ft_delete_row(t_table *t)
{
	int		row_id;
	int		r_idx;
	char	*row_string;

	row_id = atoi(ft_get_info("Which row ID would you like to delete?"));
	// printf("I have to delete %d  T_T\n", row);
	if ((r_idx = ft_find_row(row_id, t)) == -1)
	{
		printf("Row ID: %d does not exist. Please verify and try again. \n", row_id);
		return ;
	}
	row_string = ft_gen_row(t->columns, r_idx);
	printf("The record we found is the following.\n%s\n", row_string);
	if ((ft_get_info("Delete? [y/n]")[0]) == 'n')
	{
		printf("keep\n");
		return ;
	}
	t->row_id[r_idx] = -1;
}

void	ft_delete_handler(char **rec, t_table *t)
{
	printf("delete handler\n");
	// --delete r search_col search_param
	// --delete c column_name??
	if (!rec[1])
		printf("print DELETE USAGE\n");
	if (rec[1][0] == 'c')
		printf("delete column\n");
	else if (rec[1][0] == 'r')
	{
		printf("delete row\n");
		ft_delete_row(t);
	}
}