/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 18:34:30 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 18:34:49 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		perror("failed to open file");
	return (fd);
}

void	ft_close_file(int fd)
{
	close(fd);
}

void	ft_insert_type(char **header, char type)
{
	char	*tmp;

	tmp = *header;
	*tmp = type;
	tmp++;
	*tmp = ':';
	tmp++;
	*tmp = '\0';
}

char	*ft_init_row(t_content record)
{
	char	*row;

	row = (char *)malloc(sizeof(char) * (record.len + 2));
	row = strcpy(row, record.data);
	row = strcat(row, ",");
	return (row);
}

char	*ft_append_to_row(char *str, t_content record)
{
	char	*row;

	row = (char *)malloc(sizeof(char) * (strlen(str) + strlen(record.data)
					+ 2));
	row = strcpy(row, str);
	row = strcat(row, record.data);
	row = strcat(row, ",");
	free(str);
	return (row);
}
