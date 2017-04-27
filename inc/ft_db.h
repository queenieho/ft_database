/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:53 by qho               #+#    #+#             */
/*   Updated: 2017/04/26 19:35:10 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_person
{
	unsigned int	key;
	char			fname[16];
	char			lname[16];
	unsigned int	age;
}				t_person;

/* FT_STRSPLIT_C */
char		**ft_strsplit(char const *s, char c);

/* FT_FORK_C */
int		ft_db_exe(char **av);
char	*ft_readline();

/* FT_DB_C */
int		ft_open_file(char *filename);
int		ft_open_file_update(char *filename);
void	ft_close_file(int fd);
int		ft_insert_record(int fd, t_person *data);
int		ft_get_record(int fd, t_person *data, int key);
int		ft_delete_record(int fd, int key);
int		ft_dbms(char *command, char **rec);


#endif