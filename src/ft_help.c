/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:00:24 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 10:05:40 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"


void	ft_print_help_all(void)
{
	ft_print_help_insert();
	ft_print_help_print();
	ft_print_help_update();
	ft_print_help_delete();
	printf(" save\n");
	printf(" exit\n");
}

void	ft_print_help_insert(void)
{
	printf(" insert c [number]\n");
	printf(" insert r [number]\n");
}

void	ft_print_help_print(void)
{
	printf(" print a\n");
	printf(" print r row_id1 [row_id2]\n");
	printf(" print c\n");
	printf(" print f\n");
	printf(" print sorted??\n");

}

void	ft_print_help_update(void)
{
	printf(" update r\n");
	printf(" update c\n");
}

void	ft_print_help_delete(void)
{
	printf(" delete r\n");
	printf(" delete c\n");
}
