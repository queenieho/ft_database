/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:51:05 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 18:51:27 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	ft_load_db(t_table *t)
{
	int		fd;
	char	*line;

	if ((fd = open(FILENAME, O_RDONLY)) == -1)
		return ;
	if (!(get_next_line(fd, &line)))
		return ;
	t->max_size = 0;
	ft_get_columns(line, t);
	ft_strdel(&line);
	while (get_next_line(fd, &line))
	{
		ft_load_row(line, t);
		ft_strdel(&line);
	}
	t->max_size = t->max_size + ((ft_empty_col(t) + 1) * 3) + 5;
	close(fd);
}
