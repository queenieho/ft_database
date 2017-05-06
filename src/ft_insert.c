/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:35:29 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 18:31:19 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_get_info(char *ask)
{
	char	*ans;
	int		i;

	printf("\n%s\n", ask);
	ans = strtok(ft_readline(), "\n");
	if (!ans)
		ans = strdup("-");
	else
	{
		i = 0;
		while (ans[i])
		{
			ans[i] = ft_tolower(ans[i]);
			i++;
		}
	}
	printf("%s\n", ans);
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
