/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:15 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 17:37:53 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_update_row(t_table *t)
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
	if ((ft_get_info("Update this record? [y/n]")[0]) == 'n')
	{
		printf("keep\n");
		return ;
	}
	// t->row_id[r_idx] = -1;
}

void	ft_update_handler(char **rec, t_table *t)
{
	printf("update handler\n");
	// update r
	if (!rec[1])
		printf("print UPDATE USAGE\n");
	if (rec[1][0] == 'r')
	{
		printf("edit row\n");
		ft_update_row(t);
	}
}