/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:00:24 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 20:38:53 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_print_help_all(void)
{
	ft_print_help_insert();
	ft_print_help_print();
	ft_print_help_update();
	ft_print_help_delete();
	printf(" save %s# saves current table%s\n", G, W);
	printf(" exit %s# saves current table and exits%s\n", G, W);
}

void	ft_print_help_insert(void)
{
	printf(" insert c [number] %s# inserts column or columns%s\n", G, W);
	printf(" insert r [number] %s# inserts row or rows%s\n", G, W);
}

void	ft_print_help_print(void)
{
	printf(" print [a] %s# prints full table%s\n", G, W);
	printf(" print [r] row_id1 [row_id2] %s# prints row or range of rows%s\n"
			, G, W);
	printf(" print [c] %s# prints column headers%s\n", G, W);
	printf(" print [f] %s# prints user filtered table%s\n", G, W);
	printf(" print [s] %s# prints user sorted table%s\n", G, W);
}

void	ft_print_help_update(void)
{
	printf(" update [r] %s# updates row%s\n", G, W);
	printf(" update [c] %s# updates column%s\n", G, W);
}

void	ft_print_help_delete(void)
{
	printf(" delete [r] %s# deletes row%s\n", G, W);
	printf(" delete [c] %s# deletes column%s\n", G, W);
}
