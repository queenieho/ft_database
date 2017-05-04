/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_db.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:02:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 12:05:33 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_load_column(char	*header, t_table *t)
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
		col->type = 's';
	else
		col->type = info[0][0];
	col->name = strdup(info[1]);
	col->name_len = strlen(col->name);
	col->max_len = col->name_len;
	t->max_size += col->max_len;
	col->even_odd = col->max_len % 2 == 1 ? 1 : 0;
	// printf("assigned col: %d.  ID: %d.  Address: %p\n", idx, t->col_id[idx], col);
	// printf("\ncol has a max len of %d\n\n", col->max_len);
	// printf("col type: - %c -, col name: %s, name len: %d\n", t->columns[idx].type, t->columns[idx].name, t->columns[idx].name_len);
	// printf("col inserted?\n");
}

void	ft_get_columns(char *line, t_table *t)
{
	char	**headers;
	// int		c_num;

	headers = ft_strsplit(line, ',');
	// c_num = ft_array_len(headers);
	while (*headers)
	{
		ft_load_column(*headers, t);
		headers++;
	}
}

void	ft_load_row_data(t_table *t, int r_idx, char *record, int c_idx)
{
	t_content	*content;

	content = &t->columns[c_idx].content_array[r_idx];
	content->data = strdup(record);
	content->len = strlen(content->data);
	ft_update_maxlen(&t->columns[c_idx], content->len, &t->max_size);
	// if (content->len > col->max_len)
	// {
	// 	max_size = max_size - col->max_len + content->len;
	// 	// printf("row len is larger than header len, will replace\n");
	// 	col->max_len = content->len;
	// 	// printf("\ncol has a max len of %d\n\n", col->max_len);
	// 	// printf("max_size %d\n", *max_size);
	// }
	// printf("You have entered %s of len %d\n", content->data, content->len);
}

void	ft_load_row(char *line, t_table *t)
{
	char	**records;
	int		r_idx;
	int		c_idx;

	c_idx = 0;
	r_idx = ft_empty_row(t);
	t->row_id[r_idx] = ft_row_id_gen();
	// printf("First empty row is at index %d and has id %d\n", r_idx, t->row_id[r_idx]);
	records = ft_strsplit(line, ',');
	while (c_idx < COL_SIZE && t->col_id[c_idx])
	{
		ft_load_row_data(t, r_idx, records[c_idx], c_idx);
		c_idx++;
	}

}

void	ft_load_db(t_table *t)
{
	int		fd;
	char	*line;

	if ((fd = open(FILENAME, O_RDONLY)) == -1)
	{
		printf("file no exist\n");
		return ;
	}
	if (!(get_next_line(fd, &line)))
	{
		printf("no header\n");
		return ;
	}
	t->max_size = 0;
	ft_get_columns(line, t);
	printf("columns max_size %d\n", t->max_size);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		// printf("about to load %s\n", line);
		ft_load_row(line, t);
		ft_strdel(&line);
	}
	t->max_size = t->max_size + ((ft_empty_col(t) + 1) * 3) + 5;
	// printf("whole max_size %d\n", t->max_size);
	// printf("%s\n", line);
	close(fd);
	// printf("%d\n", fd);
}