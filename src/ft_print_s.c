/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 22:01:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 12:17:41 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

// void	ft_print_table(t_table *t)
// {	

// 	int			row_idx;
// 	int			len;

// 	ft_print_header(t);
// 	row_idx = 0;
// 	while (row_idx < g_row_id)
// 	{
// 		if(t->row_id[row_idx] > 0)
// 			ft_print_row(t, row_idx);
// 		row_idx++;
// 	}
// 	ft_print_line(t);
// }

// void		ft_print_sorted(t_table *t)
// {
// 	int			*sort;
// 	int			num_rows;

// 	num_rows = 1;
// 	sort = (int *)strnew(num_rows);
	// sort[0] = 42;
	// sort[1] = 513;
	// sort[2] = 42;
	// sort[3] = 297;
	// sort[4] = 10000;
	// sort[5] = 10000;
	// printf("%c\n", sort[0]);
	// printf("%c\n", sort[1]);
	// printf("%d\n", sort[2]);
	// printf("%d\n", sort[3]);
	// printf("%d\n", sort[4]);
	// printf("%d\n", sort[5]);
// }

// static	int	ft_search_header(t_table *t, char *find)
// {
// 	t_content	*data;
// 	t_column	*col;
// 	int			col_idx;
// 	char		*str;
// 	int			len;

// 	col_idx = 0;
// 	while (col_idx < g_col_id)
// 	{
// 		col = &t->columns[col_idx];
// 		str = col->name;
// 		if (str && t->col_id[col_idx] > 0)
// 			if(ft_strcmp(str, find))
// 				return (col_idx);
// 		col_idx++;
// 	}
// 	return (-1);
// }

// static	int	ft_search_col(t_table *t, int row_idx, int col_idx, char *find)
// {
// 	t_content	*data;
// 	t_column	*col;
// 	char		*str;
// 	int			ret;

// 	ret = 0;
// 	col = &t->columns[col_idx];
// 	data = &col->content_array[row_idx];
// 	str = data->data;
// 	if (ft_strstr(str, find))
// 	{
// 		ret = 1;
// 	}
// 	return (ret);
// }

// static	int	ft_search_row(t_table *t, char *str, int col_idx)
// {	

// 	int			row_idx;
// 	int			len;
// 	int			ret;

// 	ft_print_header(t);
// 	row_idx = 0;
// 	while (row_idx < g_row_id)
// 	{
// 		if(t->row_id[row_idx] > 0)
// 		{
// 			if (ft_search_col(t, row_idx, col_idx, str))
// 			{
// 				ft_print_row(t, row_idx);
// 				ret = 1;
// 			}
// 		}
// 		row_idx++;
// 	}
// 	ft_print_line(t);
// 	return (ret);
// }

// void			ft_print_filtered(t_table *t)
// {
// 	char	*str;
// 	int		col_idx;

// 	ft_print_header(t);
// 	str = ft_get_info("What column would you like to filter");
// 	if (str)
// 	{
// 		col_idx = ft_search_header(t, str);
// 		if (col_idx >= 0)
// 		{
// 			str = ft_get_info("What would you like to filter for?");
// 			if (str)
// 			{
// 				if (ft_search_row(t, str, col_idx) == -1)
// 					printf("Search of %s was not found.\n", str);
// 			}
// 		}
// 	}

// }

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

static	int		ft_comp_rows(t_table *t, int col_idx, int **array)
{	
	int			row_idx;
	int			flag;
	char		*str1;
	char		*str2;
	int			*sort;

	row_idx = 0;
	flag = 0;
	sort = *array;
	while (row_idx < g_row_id && sort[row_idx + 1] > 0)
	{
		str1 = ft_comp_cols(t, sort[row_idx], col_idx);
		str2 = ft_comp_cols(t, sort[row_idx + 1], col_idx);

		printf("String 1: %s\n", str1);
		printf("String 2: %s\n", str2);
		// if (ft_strcmp(str1, str2) > 0)
		// {
		// 	**sort[sort_idx] = row_idx + 1;
		// 	**sort[sort_idx + 1] = row_idx;
		// 	flag = 1;
		// }

		// else
		// {
		// 	**sort[sort_idx + 1] = row_idx;
		// 	**sort[sort_idx + 1] = row_idx + 1;
		// }
		free(str1);
		free(str2);
		row_idx++;
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
	// printf("%d\n", num);
	while (r_idx < num && t->row_id[r_idx] != 0)
	{
		// printf("here? \n");
		// printf("%d\n", r_idx);
		if (t->row_id[r_idx] != -1)
		{
			// printf("found matching id, will assign!\n");
			sort[array_idx] = t->row_id[r_idx];
			array_idx++;
		}
		// else
		// 	printf("minus 1\n");
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

	int i = 0;
	flag = 1;
	num_rows = ft_empty_row(t);
	printf("num rows %d\n", num_rows);
	sort_exst = (int *)malloc(sizeof(int) * (num_rows + 1));
	bzero(sort_exst, sizeof(int) * (num_rows + 1));
	ft_gen_sort_array(t, num_rows, &sort_exst);

	// while(flag == 1)
	// 	flag = ft_sort_del(t, col_idx, &sort_del);
	while(flag == 1)
		flag = ft_comp_rows(t, col_idx, &sort_exst);

	// while (i < num_rows)
	// {
	// 	printf("%d:  %d\n", i, sort_exst[i]);
	// 	i++;
	// }
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
