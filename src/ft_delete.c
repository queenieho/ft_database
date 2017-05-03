/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:44 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 12:05:34 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_delete_handler(char **rec, t_table *t)
{
	printf("delete handler\n");
	// --delete r search_col search_param
	// --delete c column_name??
	if (!rec[1])
		printf("print DELETE USAGE\n");
	if (rec[1][0] == 'c')
		printf("delete column\n");
	else if (rec[1][0] == 'r')
		printf("delete row\n");
}