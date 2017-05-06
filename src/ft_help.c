/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:00:24 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 22:34:43 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_print_help_all(void)
{
	ft_print_help_insert();
	ft_print_help_print();
	ft_print_help_update();
	ft_print_help_delete();
	printf(" %ssave %s# saves current table\n", G, W);
	printf(" %sexit %s# saves current table and exits\n", G, W);
}

void	ft_print_help_insert(void)
{
	printf(" %sinsert c [number] %s# inserts column or columns\n", G, W);
	printf(" %sinsert r [number] %s# inserts row or rows\n", G, W);
}

void	ft_print_help_print(void)
{
	printf(" %sprint [a] %s# prints full table\n", G, W);
	printf(" %sprint [r] row_id1 [row_id2] %s# prints row or range of rows\n"
			, G, W);
	printf(" %sprint [c] %s# prints column headers\n", G, W);
	printf(" %sprint [f] %s# prints user filtered table\n", G, W);
	printf(" %sprint [s] %s# prints user sorted table\n", G, W);
}

void	ft_print_help_update(void)
{
	printf(" %supdate [r] %s# updates row\n", G, W);
	printf(" %supdate [c] %s# updates column\n", G, W);
}

void	ft_print_help_delete(void)
{
	printf(" %sdelete [r] %s# deletes row\n", G, W);
	printf(" %sdelete [c] %s# deletes column\n", G, W);
}
