/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:10 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 10:23:56 by qho              ###   ########.fr       */
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
	int		idx;

	idx = 0;
	while (idx < COL_SIZE)
	{
		free(t->columns[idx].content_array);
		idx++;
	}
	free(t->columns);
}

void	ft_exit(t_table *t)
{
	ft_save_handler(t);
	ft_cleanup(t);
	exit(1);
}

int		ft_dbms(char *command, char **rec, t_table *t)
{
	int		ac;

	ac = ft_array_len(rec);
	(void)t;
	if (ac == 1 && !strncmp(command, "help", 4))
		ft_print_help_all();
	else if (ac == 1 && !strncmp(command, "exit", 4))
		ft_exit(t);
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
	return (0);
}
