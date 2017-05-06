/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:35:29 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 20:21:29 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_awk_moment(char *str)
{
	printf("%s [!] %s [!]%s\n", R, str, W);
}

char	*ft_get_info(char *ask)
{
	char	*ans;

	printf("\n%s\n", ask);
	ans = strtok(ft_readline(), "\n");
	if (!ans)
		ans = strdup("-");
	return (ans);
}

void	ft_insert_handler(char **rec, t_table *t)
{
	int		num;

	num = 1;
	if (!rec[1])
		ft_print_help_insert();
	else
	{
		if (rec[2] && (num = atoi(rec[2])) <= 0)
			num = 1;
		if (rec[1][0] == 'c')
			ft_insert_column(t, num);
		else if (rec[1][0] == 'r')
			ft_insert_row(t, num);
	}
}
