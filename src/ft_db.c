/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:10 by qho               #+#    #+#             */
/*   Updated: 2017/04/23 20:49:22 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
		perror("failed to open file");
	return (fd);
}

int		ft_open_file_update(char *filename)
{
	int		fd;

	fd = open(filename, O_CREAT | O_RDWR, 0644);
	if (fd == -1)
		perror("failed to open file");
	return (fd);
}

void	ft_close_file(int fd)
{
	close(fd);
}

int		ft_insert_record(int fd, t_person *data)
{
	// printf("inserting data\n");
	int		ret;

	ret = write(fd, data, sizeof(t_person));
	return (ret);
}

int		ft_get_record(int fd, t_person *data, int key)
{
	int		ret;

	// printf("%d\n", key);
	// data = (t_person *)malloc(sizeof(t_person));
	while ((ret = read(fd, data, sizeof(t_person))) != -1)
	{
		if (ret == 0)
		{
			memset(data, 0, sizeof(t_person));
			break ;
			return (ret);
		}
		else if (data->key == key)
		{
			// printf("key found?\n");
			// printf("Key: %d\n", data->key);
			// printf("First Name: %s\n", data->fname);
			// printf("Last Name: %s\n", data->lname);
			// printf("Age: %d\n", data->age);			
			return (ret);
		}

	}
	memset(data, 0, sizeof(t_person));
	return (ret);
}

int		ft_delete_record(int fd, int key)
{
	int			ret;
	t_person	record;
	off_t		position;

	position = lseek(fd, 0, SEEK_SET);
	while ((ret = read(fd, &record, sizeof(t_person))) != -1)
	{
		if (ret == 0)
			return (ret);
		else if (record.key == key)
		{
			lseek(fd, position, SEEK_SET);
			record.key = 0;
			// Only sets key to 0, but keeps all the data, it just won't be findable
			ret = write(fd, &record, sizeof(t_person));
			return (ret);
		}
		position = lseek(fd, 0, SEEK_CUR);
	}
	return (ret);
}

int		main(int ac, char **av)
{
	int			fd;
	t_person	record;

	if (ac > 1)
	{
		/* insert data */
		if (ac > 5 && !strcmp(av[1], "insert"))
		{
			fd = ft_open_file("data1");
			// printf("insert data\n");
			record.key = atoi(av[2]);
			strcpy(record.fname, av[3]);
			// record.fname = strdup(av[3]);
			// printf("name: %s\n", record.fname);
			strcpy(record.lname, av[4]);
			// record.lname = strdup(av[4]);
			record.age  = atoi(av[5]);
			// printf("insert data\n");
			ft_insert_record(fd, &record);
		}

		/* delete */
		else if (ac > 2 && !strcmp(av[1], "delete"))
		{
			fd = ft_open_file_update("data1");
			ft_delete_record(fd, atoi(av[2]));
		}
		/* print */
		else if (ac > 2 && !strcmp(av[1], "print"))
		{
			fd = ft_open_file("data1");
			ft_get_record(fd, &record, atoi(av[2]));
			printf("Key: %d\n", record.key);
			printf("First Name: %s\n", record.fname);
			printf("Last Name: %s\n", record.lname);
			printf("Age: %d\n", record.age);
		}
	}
	ft_close_file(fd);
	return (0);
}
