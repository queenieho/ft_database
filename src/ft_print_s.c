/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:01:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 18:28:43 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void			ft_print_sort_table(t_table *t, int *sorted)
{
	int			row_idx;
	int			real_idx;
	int			len;

	ft_print_header(t);
	row_idx = 0;
	while (row_idx < g_row_id)
	{
		real_idx = ft_find_row(sorted[row_idx], t);
		if (t->row_id[real_idx] > 0)
			ft_print_row(t, real_idx);
		row_idx++;
	}
	ft_print_line(t);
}

void			ft_gen_sort_array(t_table *t, int num, int **array)
{
	int			r_idx;
	int			array_idx;
	int			*sort;

	r_idx = 0;
	array_idx = 0;
	sort = *array;
	while (r_idx < num && t->row_id[r_idx] != 0)
	{
		if (t->row_id[r_idx] != -1)
		{
			sort[array_idx] = t->row_id[r_idx];
			array_idx++;
		}
		r_idx++;
	}
	while (array_idx < num)
	{
		sort[array_idx] = -1;
		array_idx++;
	}
}

void			ft_sorter(t_table *t, int col_idx)
{
	int			*sort_exst;
	int			num_rows;
	int			asnd_dsnd;
	char		*str;

	asnd_dsnd = 0;
	num_rows = ft_empty_row(t);
	sort_exst = (int *)malloc(sizeof(int) * (num_rows + 1));
	bzero(sort_exst, sizeof(int) * (num_rows + 1));
	if ((str = ft_get_info(
		"If you want descending order type (1) otherwise press enter?")))
		if (ft_atoi(str) == 1)
			asnd_dsnd = 1;
	ft_gen_sort_array(t, num_rows, &sort_exst);
	ft_comp_rows(t, col_idx, &sort_exst, asnd_dsnd);
	ft_print_sort_table(t, sort_exst);
}

void			ft_print_sorted(t_table *t)
{
	char	*str;
	int		col_idx;

	ft_print_header(t);
	str = ft_get_info("Which field would you like to sort by?");
	if (str)
	{
		if ((col_idx = ft_search_header(t, str)) == -1)
		{
			printf("Could not find a matching field. \n");
			if ((ft_get_info("Try another? [y/n]")[0]) == 'n')
				return ;
			else
				ft_print_sorted(t);
		}
		else
			ft_sorter(t, col_idx);
	}
}

void			ft_print_selected(t_table *t, int num1, int num2)
{
	if (num1 >= 0 && num2 >= 0 && num1 < num2)
	{
		ft_print_header(t);
		while (num1 <= num2)
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
