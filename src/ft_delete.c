/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 01:29:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_find_row(int r_id, t_table *t)
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
	if ((r_idx = ft_find_row(row_id, t)) == -1)
	{
		printf("This row does not exist. Please verify and try again.\n");
		return ;
	}
	printf("We found the following record\n\n");
	ft_print_selected(t, r_idx, 0);
	if ((ft_get_info("Delete? [y/n]")[0]) == 'n')
		return ;
	t->row_id[r_idx] = -1;
}

void	ft_delete_column(t_table *t)
{
	int		c_idx;
	char	*new_input;
	int		new_len;
	char	*field;

	ft_print_header(t);
	field = ft_get_info("Which column would you like to delete?");
	if ((c_idx = ft_search_header(t, field)) == -1)
	{
		if ((ft_get_info("Could not find a matching column. Try another? [y/n]")[0]) == 'n')
			return ;
		else
			ft_delete_column(t);
	}
	else
	{
		t->col_id[c_idx] = -1;
		t->max_size = (t->max_size - (t->columns[c_idx].max_len + 3));
	}
}

void	ft_delete_handler(char **rec, t_table *t)
{
	if (!rec[1])
		printf("print DELETE USAGE\n");
	else if (rec[1][0] == 'c')
		ft_delete_column(t);
	else if (rec[1][0] == 'r')
		ft_delete_row(t);
}