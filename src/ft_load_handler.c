/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:51:05 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 20:21:20 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int	ft_load_db(t_table *t)
{
	int		fd;
	char	*line;
	int		rows;
	int		cols;

	ERR((fd = open(FILENAME, O_RDONLY)) == -1, 0);
	ERR(!(get_next_line(fd, &line)), 0);
	t->max_size = 0;
	ft_get_columns(line, t);
	ft_strdel(&line);
	rows = 0;
	while (get_next_line(fd, &line) && rows < ROW_SIZE)
	{
		ft_load_row(line, t);
		ft_strdel(&line);
		rows++;
	}
	if (rows >= ROW_SIZE)
		ft_awk_moment("Reached max row limit, might have missed some data.");
	if ((cols = ft_empty_col(t)) != -1)
		t->max_size = t->max_size + ((cols + 1) * 3) + 5;
	else
		t->max_size = t->max_size + ((COL_SIZE + 1) * 3) + 5;
	close(fd);
	return (0);
}
