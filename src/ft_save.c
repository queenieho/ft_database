/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 15:37:33 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 09:37:08 by qho              ###   ########.fr       */
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

// int		ft_open_file_update(char *filename)
// {
// 	int		fd;

// 	fd = open(filename, O_CREAT | O_RDWR, 0644);
// 	if (fd == -1)
// 		perror("failed to open file");
// 	return (fd);
// }

void	ft_close_file(int fd)
{
	close(fd);
}

// int		ft_numlen(int nb)
// {
// 	int	len;

// 	len = 1;
// 	while (nb / 10)
// 		len++;
// 	return (len);
// }

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

char	*ft_gen_header(t_column col, int *len)
{
	char	*header;
	int		i;
	// char	*num;

	i = 2;
	// num = ft_itoa(col.name_len);
	// *len = col.name_len + ft_numlen(col.name_len) + 5;
	*len = col.name_len + 3;
	// header = (char *)malloc(sizeof(char) * 3);
	header = (char *)malloc(sizeof(char) * (*len + 1));
	ft_insert_type(&header, col.type);
	// header = strcat(header, num);
	// header = strcat(header, ":");
	header = strcat(header, col.name);
	header = strcat(header, ",");
	// printf("lenght of %d is : %d\n", col.name_len, ft_numlen(col.name_len));
	// printf("%s\n", num);
	// printf("%s\n", header);
	return (header);
}

void	ft_save_col_header(int fd, t_column col)
{
	char	*header;
	int		len;
	// printf("inserting %s of len %d, of type %c\n", col.name, col.name_len, col.type);
	header = ft_gen_header(col, &len);
	// write(1, header, len);
	write(fd, header, len);
	// write(fd, ",", 1);
	// printf("success!!!\n");
}

char	*ft_init_row(t_content record)
{
	// printf("init row\n");
	char	*row;

	row = (char *)malloc(sizeof(char) * (record.len + 2));
	row = strcpy(row, record.data);
	row = strcat(row, ",");
	// printf("done init %s\n", row);
	return(row);
}

char	*ft_append_to_row(char *str, t_content record)
{
	// printf("append\n");
	char	*row;

	row = (char *)malloc(sizeof(char) * (strlen(str) + record.len + 2));
	row = strcpy(row, str);
	row = strcat(row, record.data);
	row = strcat(row, ",");
	free(str);
	// printf("done append %s\n", row);
	return(row);
}

char	*ft_gen_row(t_column *col, int r_idx)
{
	// printf("generating row ID %d\n", r_idx);
	char	*row;
	int		c_idx;

	c_idx = 1;
	row = ft_init_row(col[0].content_array[r_idx]);
	// printf("generated init row: %s\n", row);
	while (c_idx < COL_SIZE && col[c_idx].name)
	{
		row = ft_append_to_row(row, col[c_idx].content_array[r_idx]);
		// printf("extended row: %s\n", row);
		c_idx++;
	}
	// printf("row generated\n");
	return (row);
}

void	ft_save_rows(int fd, t_table *t)
{
	// int		c_idx;
	int		r_idx;
	int		len;
	char	*row_string;

	// c_idx = 0;
	r_idx = 0;
	len = 0;
	while (r_idx < ROW_SIZE && t->row_id[r_idx])
	{
		if (t->row_id[r_idx] > 0)
		{
			row_string = ft_gen_row(t->columns, r_idx);
			len = strlen(row_string);
			// write(1, row_string, len);
			write(fd, row_string, len);
			// write(1, "\n", 1);
			write(fd, "\n", 1);
		}
		r_idx++;
	}
}

void	ft_save_handler(t_table *t)
{
	int		fd;
	int		c_idx;
	// int		r_idx;

	fd = ft_open_file(FILENAME);
	c_idx = 0;
	// r_idx = 0;
	// printf("%d\n", t->col_id[c_idx]);
	while (c_idx < COL_SIZE && t->col_id[c_idx] != 0)
	{
		// printf("%d\n", t->col_id[c_idx]);
		// printf("Need to insert %s of len %d\n", t->columns[c_idx].name, t->columns[c_idx].name_len);
		ft_save_col_header(fd, t->columns[c_idx]);
		c_idx++;
	}
	write(fd, "\n", 1);
	if (t->row_id[0])
	{
		// printf("need to insert rows\n");
		ft_save_rows(fd, t);
	}

	ft_close_file(fd);
}