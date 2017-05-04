/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:15 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 15:00:49 by qho              ###   ########.fr       */
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

	printf("PRINT COLUMNS WITH NUMBERS\n");
	col_id = atoi(ft_get_info("Which field would you like to update? Select a number"));
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
	// printf("I have to delete %d  T_T\n", row);
	if ((r_idx = ft_find_row(row_id, t)) == -1)
	{
		printf("Row ID: %d does not exist. Please verify and try again. \n", row_id);
		return ;
	}
	row_string = ft_gen_row(t->columns, r_idx);
	printf("The record we found is the following.\n%s\n", row_string);

	// NEED TO CHANGE THE OUTPUT OF THE RECORD TO SHOW FIELDS

	if ((ft_get_info("Update this record? [y/n]")[0]) == 'n')
	{
		printf("keep\n");
		return ;
	}
	ft_update_record(t, r_idx);
	row_string = ft_gen_row(t->columns, r_idx);
	printf("New record\n%s\n", row_string);
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