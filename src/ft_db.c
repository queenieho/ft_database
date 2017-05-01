/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:10 by qho               #+#    #+#             */
/*   Updated: 2017/04/30 22:10:21 by qho              ###   ########.fr       */
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

int		ft_array_len(char **args)
{
	int		len;
	char	**tmp;

	len = 0;
	tmp = args;
	while (*tmp)
	{
		tmp++;
		len++;
	}
	return (len);
}

int		ft_dbms(char *command, char **rec)
{
	// printf("FT_DBMS\n");
	int			fd;
	t_person	record;
	t_person	tmp;
	int			ac;

	ac = ft_array_len(rec);
	// printf("command: %s\n", command);
	// printf("len: %d\n", ac);
	if (ac > 1)
	{
		/* insert data */
		if (ac >= 5 && !strcmp(command, "insert"))
		{
			// printf("insert data\n");
			fd = ft_open_file("data1");
			record.key = atoi(rec[1]);
			strcpy(record.fname, rec[2]);
			strcpy(record.lname, rec[3]);
			record.age  = atoi(rec[4]);
			ft_insert_record(fd, &record);
		}

		/* delete */
		else if (ac >= 2 && !strcmp(command, "delete"))
		{
			// printf("deleting data\n");
			fd = ft_open_file_update("data1");
			ft_delete_record(fd, atoi(rec[1]));
		}
		/* print */
		else if (ac >= 2 && !strcmp(command, "print"))
		{
			// printf("printing data\n");
			fd = ft_open_file("data1");
			ft_get_record(fd, &record, atoi(rec[1]));
			printf("Key: %d\n", record.key);
			printf("First Name: %s\n", record.fname);
			printf("Last Name: %s\n", record.lname);
			printf("Age: %d\n", record.age);
		}
		/* update */
		else if (ac >= 5 && !strcmp(command, "edit"))
		{
			printf("editing data\n");
			fd = ft_open_file_update("data1");
			ft_get_record(fd, &tmp, atoi(rec[1]));
			// printf("Key: %d\n", record.key);
			// printf("First Name: %s\n", record.fname);
			// printf("Last Name: %s\n", record.lname);
			// printf("Age: %d\n", record.age);
			record.key = atoi(rec[1]);
			strcpy(record.fname, rec[2]);
			strcpy(record.lname, rec[3]);
			record.age  = atoi(rec[4]);
			ft_delete_record(fd, atoi(rec[1]));
			ft_insert_record(fd, &record);
			// bzero(&record, sizeof(t_person));
			// ft_get_record(fd, &record, atoi(rec[1]));
			printf("Record has been updated as follows\n");
			printf("Key: %d --> %d\n", tmp.key, record.key);
			printf("First Name: %s --> %s\n", tmp.fname, record.fname);
			printf("Last Name: %s --> %s\n", tmp.lname, record.lname);
			printf("Age: %d --> %d\n", tmp.age, record.age);
		}
		ft_close_file(fd);
	}
	return (0);
}

// int		main(int ac, char **av)
// {
// 	int			fd;
// 	t_person	record;

// 	if (ac > 1)
// 	{
// 		/* insert data */
// 		if (ac > 5 && !strcmp(av[1], "insert"))
// 		{
// 			fd = ft_open_file("data1");
// 			record.key = atoi(av[2]);
// 			strcpy(record.fname, av[3]);
// 			strcpy(record.lname, av[4]);
// 			record.age  = atoi(av[5]);
// 			ft_insert_record(fd, &record);
// 		}

// 		/* delete */
// 		else if (ac > 2 && !strcmp(av[1], "delete"))
// 		{
// 			fd = ft_open_file_update("data1");
// 			ft_delete_record(fd, atoi(av[2]));
// 		}
// 		/* print */
// 		else if (ac > 2 && !strcmp(av[1], "print"))
// 		{
// 			fd = ft_open_file("data1");
// 			ft_get_record(fd, &record, atoi(av[2]));
// 			printf("Key: %d\n", record.key);
// 			printf("First Name: %s\n", record.fname);
// 			printf("Last Name: %s\n", record.lname);
// 			printf("Age: %d\n", record.age);
// 		}
// 	}
// 	ft_close_file(fd);
// 	return (0);
// }
