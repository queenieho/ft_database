/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:35:29 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 14:16:50 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char	*ft_get_info(char *ask)
{
	char	*ans;

	printf("%s\n", ask);
	ans = strtok(ft_readline(), "\n");
	return (ans);
}

void	ft_insert_handler(char **rec, t_table *t)
{
	char	type;
	char	*col_name;
	int		num;
	// --insert c column_name data_type [-k: use for key generate] or 1st col gens key
	// content type: s.trings, i.nteger, d.ate
	// --insert r
	printf("insert handler\n");
	num = 1;
	if (!rec[1])
		printf("print INSERT USAGE\n");

	if (rec[2])
		if ((num = atoi(rec[2])) <= 0)
			num = 1;
	printf("inserting %d\n", num);
	if (rec[1][0] == 'c')
	{
		// printf("insert column\n");
		col_name = ft_get_info("What is the column name?");
		type = ft_get_datatype();
		// printf("Column name: %s, of type: %c\n", col_name, type);
		ft_insert_column(t, type, col_name);
	}
	else if (rec[1][0] == 'r')
	{
		// printf("insert row\n");
		ft_insert_row(t);
		// ft_insert_record(t);
	}
}