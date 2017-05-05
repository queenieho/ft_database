/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:35:29 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 22:57:34 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

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
		printf("print INSERT USAGE\n");
	else if (rec[2])
		if ((num = atoi(rec[2])) <= 0)
			num = 1;
	if (rec[1][0] == 'c')
		ft_insert_column(t, num);
	else if (rec[1][0] == 'r')
		ft_insert_row(t, num);
}
