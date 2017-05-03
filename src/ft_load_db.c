/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_db.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:02:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 15:58:40 by qho              ###   ########.fr       */
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
	printf("assigned col: %d.  ID: %d.  Address: %p\n", idx, t->col_id[idx], col);
	printf("col type: - %c -, col name: %s, name len: %d\n", t->columns[idx].type, t->columns[idx].name, t->columns[idx].name_len);
	printf("col inserted?\n");
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

void	ft_load_row_data(t_column *col, int r_idx, char *record)
{
	t_content	*content;

	content = &col->content_array[r_idx];
	content->data = strdup(record);
	content->len = strlen(content->data);
	printf("You have entered %s of len %d\n", content->data, content->len);
}

void	ft_load_row(char *line, t_table *t)
{
	char	**records;
	int		r_idx;
	int		c_idx;

	c_idx = 0;
	r_idx = ft_empty_row(t);
	t->row_id[r_idx] = ft_row_id_gen();
	printf("First empty row is at index %d and has id %d\n", r_idx, t->row_id[r_idx]);
	records = ft_strsplit(line, ',');
	while (c_idx < COL_SIZE && t->col_id[c_idx])
	{
		ft_load_row_data(&t->columns[c_idx], r_idx, records[c_idx]);
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
	ft_get_columns(line, t);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		printf("about to load %s\n", line);
		ft_load_row(line, t);
		ft_strdel(&line);
	}
	// printf("%s\n", line);
	close(fd);
	// printf("%d\n", fd);
}