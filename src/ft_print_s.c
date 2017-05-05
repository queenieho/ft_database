/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:01:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 01:47:09 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		ft_print_sorted(t_table *t)

void		ft_print_selected(t_table *t, int num1, int num2)
{
	if (num1 >= 0 && num2 >= 0 && num1 < num2)
	{
		ft_print_header(t);
		while (num1 < num2)
			ft_print_row(t, num1++);
		ft_print_line(t);
	}
	else if (num1 >= 0 && num2 < 0)
	{
		ft_print_header(t);
		ft_print_row(t, num1);
		ft_print_line(t);
	}
	else
		printf("The first number must be >= 0 and < the second number.\n");
}
