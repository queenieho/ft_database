/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:48:32 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 14:22:13 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

// int		ft_max_len(t_table *t)
// {
// 	int		row_num;
// 	int		col_num;
// 	int		max;
// 	t_content	*data;
// 	t_column	*col;

// 	row_num = 0;
// 	while (row_num < g_row_id)
// 	{
// 		col_num = 0;
// 		while (col_num < g_col_id)
// 		{
// 			col = &t->columns[col_num];
// 			data = &col->content_array[row_num];
// 			if (data->len >= max)
// 				max = data->len;
// 			col_num++;
// 		}
// 		row_num++;
// 	}
// 	return (max);
// }

// char	*ft_get_info(char *ask)
// {
// 	char	*ans;

// 	printf("%s\n", ask);
// 	ans = strtok(ft_readline(), "\n");
// 	return (ans);
// }
		// str = ft_strnew(col->max_len);
		// memset(str, c, col->max_len);
		// printf("%s", str);
		// ft_strdel(&str);
void	ft_print_data(int max_len, char *str)
{
	int		len;

	len = (int)ft_strlen(str);
	printf("%-*s ", max_len, str);
	// max_len += 2;
	// if (even_odd)
	// 	printf("%*s%*s", max_len/2 + len/2 + 1, str, max_len/2 - len/2 + 1, "");
	// else
		// printf("%*s%*s", max_len/2 + len/2, str, max_len/2 - len/2, "");
}

void	ft_print_line(t_table *t)
{
	char	*str;

	str = ft_strnew((int)t->max_size);
	memset(str, '-', (int)t->max_size - 1);
	str[0] = 'o';
	str[(int)t->max_size - 1] = 'o';
	printf("%s", str);
	ft_strdel(&str);
	printf("\n");
}

void	ft_print_header(t_table *t)
{
	t_content	*data;
	t_column	*col;
	int			col_num;
	char		*str;
	int			len;

	ft_print_line(t);
	col_num = 0;
	printf("| Key ");
	while (col_num < g_col_id)
	{
		printf("| ");
		col = &t->columns[col_num];
		str = col->name;
		if (str)
			ft_print_data((int)col->max_len, str);
		col_num++;
	}
	printf(" |\n");
	ft_print_line(t);
}

void	ft_print_row(t_table *t, int row_idx)
{
	t_content	*data;
	t_column	*col;
	int			col_idx;
	char		*str;

	printf("| ");
	col_idx = 0;
	printf("%03d ", t->row_id[row_idx]);
	while (col_idx < g_col_id)
	{
		printf("| ");
		col = &t->columns[col_idx];
		data = &col->content_array[row_idx];
		str = data->data;
		if (str)
			ft_print_data((int)col->max_len, str);
		col_idx++;
	}
	printf(" |\n");
}

void	ft_print_table(t_table *t)
{	

	int			row_idx;
	int			len;

	ft_print_header(t);
	row_idx = 0;
	while (row_idx < g_row_id)
	{
		if(t->row_id[row_idx] > 0)
			ft_print_row(t, row_idx);
		row_idx++;
	}
	ft_print_line(t);
}
