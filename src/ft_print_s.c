/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:01:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 16:03:39 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static	void	ft_print_sort_table(t_table *t, int *sorted)
{	

	int			row_idx;
	int			real_idx;
	int			len;

	ft_print_header(t);
	row_idx = 0;
	while (row_idx < g_row_id)
	{
		real_idx = ft_find_row(sorted[row_idx], t);
		if(t->row_id[real_idx] > 0)
			ft_print_row(t, real_idx);
		row_idx++;
	}
	ft_print_line(t);
}

static	char	*ft_comp_cols(t_table *t, int row_id, int col_idx)
{
	t_content	*data;
	t_column	*col;
	char		*str;
	int			r_idx;

	r_idx = ft_find_row(row_id, t);
	col = &t->columns[col_idx];
	data = &col->content_array[r_idx];
	str = strdup(data->data);
	return (str);
}

static	int ft_sort_asnd_int(t_table *t, int r_idx, int col_idx, int **array)
{
	int			int1;
	int			int2;
	int			flag;
	int			*sort;
	int			tmp;

	flag = 0;
	sort = *array;
	int1 = ft_atoi(ft_comp_cols(t, sort[r_idx], col_idx));
	int2 = ft_atoi(ft_comp_cols(t, sort[r_idx + 1], col_idx));
	if (int1 > int2)
	{		
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
		flag = 1;
	}
	return (flag);
}

static	int ft_sort_asnd_str(t_table *t, int r_idx, int col_idx, int **array)
{
	char		*str1;
	char		*str2;
	int			flag;
	int			*sort;
	int			tmp;

	flag = 0;
	sort = *array;
	str1 = ft_comp_cols(t, sort[r_idx], col_idx);
	str2 = ft_comp_cols(t, sort[r_idx + 1], col_idx);
	if (ft_strcmp(str1, str2) > 0)
	{		
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
		flag = 1;
	}
	free(str1);
	free(str2);
	return (flag);
}

static	int ft_sort_dsnd_int(t_table *t, int r_idx, int col_idx, int **array)
{
	int			int1;
	int			int2;
	int			flag;
	int			*sort;
	int			tmp;

	flag = 0;
	sort = *array;
	int1 = ft_atoi(ft_comp_cols(t, sort[r_idx], col_idx));
	int2 = ft_atoi(ft_comp_cols(t, sort[r_idx + 1], col_idx));
	if (int1 < int2)
	{		
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
		flag = 1;
	}
	return (flag);
}

static	int ft_sort_dsnd_str(t_table *t, int r_idx, int col_idx, int **array)
{
	char		*str1;
	char		*str2;
	int			flag;
	int			*sort;
	int			tmp;

	flag = 0;
	sort = *array;
	str1 = ft_comp_cols(t, sort[r_idx], col_idx);
	str2 = ft_comp_cols(t, sort[r_idx + 1], col_idx);
	if (ft_strcmp(str1, str2) < 0)
	{		
		tmp = sort[r_idx + 1];
		sort[r_idx + 1] = sort[r_idx];
		sort[r_idx] = tmp;
		flag = 1;
	}
	free(str1);
	free(str2);
	return (flag);
}

static	int		ft_comp_rows(t_table *t, int col_idx, int **array, int asnd_dsnd)
{
	t_column	*col;
	int			r_idx;
	int			flag;
	int			*sort;

	r_idx = 0;
	flag = 0;
	sort = *array;
	col = &t->columns[col_idx];
	while (r_idx < g_row_id && sort[r_idx + 1] > 0)
	{
		printf("%d\n", asnd_dsnd);
		if (col->type == 'i')
		{
			printf("ITS AN INT\n");
			flag = asnd_dsnd ? ft_sort_dsnd_int(t, r_idx, col_idx, &sort) :
				ft_sort_asnd_int(t, r_idx, col_idx, &sort);
		}
		else if (col->type == 's')
		{
			printf("its a string\n");
			flag = asnd_dsnd ? ft_sort_dsnd_str(t, r_idx, col_idx, &sort) :
				ft_sort_asnd_str(t, r_idx, col_idx, &sort);
		}
		r_idx++;
	}
	return (flag);
}

static void		ft_gen_sort_array(t_table *t, int num, int **array)
{
	int	r_idx;
	int	array_idx;
	int	*sort;

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

static void		ft_sorter(t_table *t, int col_idx)
{
	int			*sort_exst;
	int			num_rows;
	int			flag;
	int			asnd_dsnd;
	char		*str;

	asnd_dsnd = 0;
	flag = 1;
	num_rows = ft_empty_row(t);
	sort_exst = (int *)malloc(sizeof(int) * (num_rows + 1));
	bzero(sort_exst, sizeof(int) * (num_rows + 1));
	if ((str = ft_get_info("If you want descending order type (1), otherwise press enter?")))
		if (ft_atoi(str) == 1)
			asnd_dsnd = 1;
	ft_gen_sort_array(t, num_rows, &sort_exst);
	while(flag == 1)
		flag = ft_comp_rows(t, col_idx, &sort_exst, asnd_dsnd);
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

void		ft_print_selected(t_table *t, int num1, int num2)
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
