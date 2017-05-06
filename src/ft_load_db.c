/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_db.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:02:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 20:03:46 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_load_column(char *header, t_table *t)
{
	char		**info;
	int			len;
	int			idx;
	t_column	*col;

	info = ft_strsplit(header, ':');
	len = ft_array_len(info);
	idx = ft_empty_col(t);
	t->col_id[idx] = ft_col_id_gen();
	col = &(t->columns[idx]);
	if (len == 1)
	{
		col->type = 's';
		col->name = strdup(info[0]);
	}
	else
	{
		col->type = info[0][0];
		col->name = strdup(info[1]);
	}
	col->name_len = strlen(col->name);
	col->max_len = col->name_len;
	t->max_size += col->max_len;
}

int		ft_get_col_num(char *line)
{
	int cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			cnt++;
		i++;
	}
	if (line[i - 1] != ',')
		cnt++;
	return (cnt);
}

void	ft_get_columns(char *line, t_table *t)
{
	char	*header;
	int		c_num;
	char	*tmp;

	// c_num = ft_get_col_num(line);
	if ((c_num = ft_get_col_num(line))> COL_SIZE)
	{
		c_num = COL_SIZE;
		ft_awkward_moment("Reached max column limit, might have missed some data.");
	}
	while (c_num)
	{
		if ((tmp = strchr(line, ',')))
		{
			*tmp = '\0';
			tmp++;
		}
		if (!*line)
			header = strdup("-");
		else
			header = strdup(line);
		ft_load_column(header, t);
		line = tmp;
		c_num--;
	}
}

void	ft_load_row_data(t_table *t, int r_idx, char *record, int c_idx)
{
	t_content	*content;

	content = &t->columns[c_idx].content_array[r_idx];
	if (record)
		content->data = record;
	else
		content->data = strdup("-");
	content->len = strlen(content->data);
	ft_update_maxlen(&t->columns[c_idx], content->len, &t->max_size);
}

int		ft_load_row(char *line, t_table *t)
{
	char	*record;
	int		r_idx;
	int		c_idx;
	char	*tmp;

	c_idx = 0;
	if ((r_idx = ft_empty_row(t)) == -1)
		return (-1);
	t->row_id[r_idx] = ft_row_id_gen();
	while (c_idx < COL_SIZE && t->col_id[c_idx])
	{
		if ((tmp = strchr(line, ',')))
		{
			*tmp = '\0';
			tmp++;
		}
		if (!*line)
			record = strdup("-");
		else
			record = strdup(line);
		ft_load_row_data(t, r_idx, record, c_idx);
		line = tmp;
		c_idx++;
	}
	return (0);
}
