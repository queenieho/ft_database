/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:07:30 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 19:40:59 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char		*ft_user_input_check(char *str)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = ft_strdup(str);
	while (cpy[i])
	{
		cpy[i] = ft_tolower(cpy[i]);
		i++;
	}
	return (cpy);
}

void		ft_print_filtered(t_table *t)
{
	char	*str;
	int		col_idx;
	char	*cpy;

	ft_print_header(t);
	str = ft_get_info("What column would you like to filter");
	if (str)
	{
		cpy = ft_user_input_check(str);
		col_idx = ft_search_header(t, cpy);
		free (cpy);
		if (col_idx >= 0)
		{
			str = ft_get_info("What would you like to filter for?");
			if (str)
			{
				cpy = ft_user_input_check(str);
				if (ft_search_row(t, ft_user_input_check(str), col_idx) == -1)
					printf("Search of %s was not found.\n", str);
				free(cpy);
			}
		}
	}
}

void		ft_print_row_handler(char **rec, t_table *t)
{
	int		num1;
	int		num2;

	if (!rec[2])
		ft_print_help_print();
	else if (rec[2] && rec[3])
	{
		num1 = ft_find_row(ft_atoi(rec[2]), t);
		if ((num2 = ft_find_row(ft_atoi(rec[3]), t)) == -1)
			num2 = ft_find_last_row(t, ft_empty_row(t) - 1);
		if (num1 >= 0 && num2 >= 0)
			ft_print_selected(t, num1, num2);
		else if (num1 >= 0)
			ft_print_selected(t, num1, -1);
	}
	else if (rec[2])
	{
		num1 = ft_find_row(ft_atoi(rec[2]), t);
		if (num1 >= 0)
			ft_print_selected(t, num1, -1);
	}
}

void		ft_print_handler(char **rec, t_table *t)
{
	int		num1;
	int		num2;

	if (!rec[1])
		ft_print_help_print();
	else if (rec[1][0] == 'r')
		ft_print_row_handler(rec, t);
	else if (rec[1][0] == 'a')
		ft_print_table(t);
	else if (rec[1][0] == 'c')
		ft_print_header(t);
	else if (rec[1][0] == 'f')
		ft_print_filtered(t);
	else if (rec[1][0] == 's')
		ft_print_sorted(t);
}
