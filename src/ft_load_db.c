/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_db.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:02:16 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 14:02:21 by qho              ###   ########.fr       */
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
	// printf("%d columns in file\n", c_num);
	// while (c_num)
	// {
	// 	printf("%s\n", *headers);
	// 	c_num--;
	// 	headers++;
	// }
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
	// printf("%s\n", line);
	close(fd);
	// printf("%d\n", fd);
}