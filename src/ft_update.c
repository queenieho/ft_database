/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:15 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 23:55:49 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_find_col_index(t_table *t, int col_id)
{
	int c_idx;

	c_idx = 0;
	while (c_idx < COL_SIZE && t->col_id[c_idx])
	{
		if (t->col_id[c_idx] == col_id)
			return (c_idx);
		c_idx++;
	}
	return (-1);
}

void	ft_update_maxlen(t_column *col, int new_len, int *max_size)
{
	if (col->max_len < new_len)
	{
		*max_size = *max_size - col->max_len + new_len;
		col->max_len = new_len;
	}
}

void	ft_update_record(t_table *t, int r_idx)
{
	int		col_id;
	int		c_idx;
	char	*new_input;
	int		new_len;
	char	*field;

	ft_print_table(t);

	field = ft_get_info("Which field would you like to update?");
	
	// col_id = atoi(ft_get_info("Which field would you like to update?"));
	if ((c_idx = ft_find_col_index(t, col_id)) == -1)
	{
		printf("col not found\n");
		return ;
	}
	printf("col number is %d\n", t->col_id[c_idx]);
	new_input = ft_get_info("Insert new input:");
	new_len = strlen(new_input);
	free(t->columns[c_idx].content_array[r_idx].data);
	t->columns[c_idx].content_array[r_idx].data = new_input;
	t->columns[c_idx].content_array[r_idx].len = new_len;
	ft_update_maxlen(&t->columns[c_idx], new_len, &t->max_size);
}

void	ft_update_row(t_table *t)
{
	int		row_id;
	int		r_idx;
	char	*row_string;

	row_id = atoi(ft_get_info("Which row ID would you like to update?"));
	if ((r_idx = ft_find_row(row_id, t)) == -1)
	{
		printf("This row does not exist. Please verify and try again.\n");
		return ;
	}
	printf("We found the following record\n\n");
	ft_print_selected(t, r_idx, 0);
	if ((ft_get_info("Update this record? [y/n]")[0]) == 'n')
		return ;
	ft_update_record(t, r_idx);
	printf("\nUpdated record\n\n");
	ft_print_selected(t, r_idx, 0);
}

void	ft_update_handler(char **rec, t_table *t)
{
	if (!rec[1])
		printf("print UPDATE USAGE\n");
	else if (rec[1][0] == 'r')
		ft_update_row(t);
	else if (rec[1][0] == 'c')
		printf("update column\n");
}
