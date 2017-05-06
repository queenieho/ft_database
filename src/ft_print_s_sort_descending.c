/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_sort_descending.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 17:21:59 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 17:28:03 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_sort_dsnd_int(t_table *t, int r_idx, int col_idx,
							int **array)
{
	int			int1;
	int			int2;
	int			*sort;
	int			tmp;

	sort = *array;
	int1 = ft_atoi(ft_comp_cols(t, sort[r_idx], col_idx));
	int2 = ft_atoi(ft_comp_cols(t, sort[r_idx + 1], col_idx));
	if (int1 < int2)
	{
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
	}
}

void	ft_sort_dsnd_str(t_table *t, int r_idx, int col_idx,
							int **array)
{
	char		*str1;
	char		*str2;
	int			*sort;
	int			tmp;

	sort = *array;
	str1 = ft_comp_cols(t, sort[r_idx], col_idx);
	str2 = ft_comp_cols(t, sort[r_idx + 1], col_idx);
	if (ft_strcmp(str1, str2) < 0)
	{
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
	}
	free(str1);
	free(str2);
}

void	ft_sort_type_dsnd(t_table *t, int col_idx, int r_idx,
							int **array)
{
	int			*sort;

	sort = *array;
	if (t->columns[col_idx].type == 'i')
		ft_sort_dsnd_int(t, r_idx, col_idx, &sort);
	else if (t->columns[col_idx].type == 's')
		ft_sort_dsnd_str(t, r_idx, col_idx, &sort);
}