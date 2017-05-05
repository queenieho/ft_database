/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:01:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/04 22:29:34 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		ft_print_selected(t_table *t)
{
	int		num1;
	int		num2;

	num1 = 0;
	num2 = 0;
	if ((num1 = ft_atoi(
		ft_get_info("What row would you like to start printing from?"))) >= 0)
	{
		if ((num2 = ft_atoi(
			ft_get_info("What row would you like to print to?")))
			 >= 0 && num2 > num1)
		{
			ft_print_header(t);
			while (num1 < num2)
				ft_print_row(t, num1++);
			ft_print_line(t);
		}
		else
			printf("The first number must be >= 0 and < the second number\n");
	}
}