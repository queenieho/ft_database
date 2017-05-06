/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:10 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 18:25:53 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_array_len(char **args)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = args;
	while (*tmp)
	{
		tmp++;
		len++;
	}
	return (len);
}

void	ft_cleanup(t_table *t)
{
	int		c_idx;
	int		r_idx;

	c_idx = 0;
	r_idx = 0;
	while (c_idx < COL_SIZE)
	{
		while (r_idx < ROW_SIZE && t->row_id[r_idx] != 0)
		{
			free(t->columns[c_idx].content_array[r_idx].data);
			r_idx++;
		}
		free(t->columns[c_idx].content_array);
		c_idx++;
	}
	free(t->columns);
}

void	ft_exit(t_table *t)
{
	ft_save_handler(t);
	ft_cleanup(t);
}

int		ft_dbms(char *command, char **rec, t_table *t)
{
	int		ac;

	ac = ft_array_len(rec);
	(void)t;
	if (ac == 1 && !strncmp(command, "help", 4))
		ft_print_help_all();
	else if (ac == 1 && !strncmp(command, "exit", 4))
	{
		ft_exit(t);
		return (0);
	}
	else if (ac == 1 && !strncmp(command, "save", 4))
		ft_save_handler(t);
	else if (!strncmp(command, "insert", 6))
		ft_insert_handler(rec, t);
	else if (!strncmp(command, "update", 6))
		ft_update_handler(rec, t);
	else if (!strncmp(command, "print", 5))
		ft_print_handler(rec, t);
	else if (!strncmp(command, "delete", 6))
		ft_delete_handler(rec, t);
	else
		printf("Invalid command. Use \"help\" to see usage.\n");
	return (1);
}
