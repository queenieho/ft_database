/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:15 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 23:32:51 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

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

	field = ft_get_info("Which field would you like to update?");
	if ((c_idx = ft_search_header(t, field)) == -1)
	{
		printf("Could not find a matching field. ");
		if ((ft_get_info("Try another? [y/n]")[0]) == 'n')
			return ;
		else
			ft_update_record(t, r_idx);
	}
	else
	{
		new_input = ft_get_info("Insert new input:");
		new_len = strlen(new_input);
		free(t->columns[c_idx].content_array[r_idx].data);
		t->columns[c_idx].content_array[r_idx].data = new_input;
		t->columns[c_idx].content_array[r_idx].len = new_len;
		ft_update_maxlen(&t->columns[c_idx], new_len, &t->max_size);
	}
}

void	ft_update_row(t_table *t)
{
	int		row_id;
	int		r_idx;
	char	*row_string;

	row_id = atoi(ft_get_info("Which row ID would you like to update?"));
	if ((r_idx = ft_find_row(row_id, t)) == -1)
	{
		if ((ft_get_info(
			"This row does not exist. Try another? [y/n]")[0]) == 'n')
			return ;
		else
			ft_update_row(t);
	}
	else
	{
		printf("We found the following record\n\n");
		ft_print_selected(t, r_idx, -1);
		if ((ft_get_info("Update this record? [y/n]")[0]) == 'y')
		{
			ft_update_record(t, r_idx);
			printf("\nUpdated record\n\n");
			ft_print_selected(t, r_idx, -1);
		}
	}
}

int		ft_update_column(t_table *t)
{
	int		c_idx;
	char	*new_input;
	int		new_len;
	char	*field;
	char	*cpy;

	ft_print_header(t);
	field = ft_get_info("Which field would you like to update?");
	cpy = ft_user_input_check(field);
	if ((c_idx = ft_search_header(t, cpy)) == -1)
		ft_check_info(t, cpy);
	else
	{
		free(cpy);
		new_input = ft_get_info("Insert new field name:");
		new_len = strlen(new_input);
		free(t->columns[c_idx].name);
		t->columns[c_idx].name = new_input;
		t->columns[c_idx].name_len = new_len;
		ft_update_maxlen(&t->columns[c_idx], new_len, &t->max_size);
	}
	return (0);
}

void	ft_update_handler(char **rec, t_table *t)
{
	if (!rec[1])
		ft_print_help_update();
	else if (rec[1][0] == 'r')
		ft_update_row(t);
	else if (rec[1][0] == 'c')
		ft_update_column(t);
}
