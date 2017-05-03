/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 23:07:21 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_print_handler(char **rec, t_table *t)
{
	printf("print handler\n");
	// --print all
	// --print r search_col search_param
	// --print sorted??
	if (!rec[1])
		printf("print PRINT USAGE\n");

	if (rec[1][0] == 'r')
		printf("print specific record\n");
	else if (rec[1][0] == 'a')
		printf("print all\n");
	else if (rec[1][0] == 's')
		printf("print sorted?\n");
}