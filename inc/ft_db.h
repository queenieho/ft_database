/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:53 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 18:19:26 by qho              ###   ########.fr       */
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
# include <signal.h>
# include <sys/mman.h>

/*
** DEFINE COLORS
*/
# define G "\033[32;1m"
# define Y "\033[33;1m"
# define R "\033[31;1m"
# define B "\033[34;1m"
# define W "\033[0m"

# define DASH "\033[33;1m=>\033[0m"

/*
** DEFINE DATA STRUCTS
*/
# define COL_SIZE 100
# define ROW_SIZE 500
# define FILENAME "data"
# define BACKUP_FILE "data.backup" // autosave every few minutes?

int		g_col_id;
int		g_row_id;

typedef struct s_date // will need a date_to_string function to store in data array
{
	int			month;
	int			day;
	int			year;
}				t_date;

typedef struct	s_content
{
	int			key;	//hash key for rows?
	int			len;	//len of string stored
	int			size;	//byte size of content? Not sure if needed.
	char		*data;	// content stored
}				t_content;

typedef struct s_column	// holds all the content in one column
{
	char		type;	// content type: s.trings, i.nteger, b.oolean, d.ate
	char		*name;	// column name
	int			name_len; // len of name
	t_content	*content_array; // pointer to array of structs containing data
}				t_column;

typedef struct	s_table
{
	int			col_id[COL_SIZE];
	int			row_id[ROW_SIZE];
	t_column	*columns;	// pointers to each column
}				t_table;


/*
** STRUCT FOR RECORD
*/
typedef struct	s_person
{
	unsigned int	key;
	char			fname[16];
	char			lname[16];
	unsigned int	age;
}				t_person;

/*
** FT_STRSPLIT_C
*/
char		**ft_strsplit(char const *s, char c);

/*
** FT_FORK_C
*/
int		ft_db_exe(char **av, t_table *table);
char	*ft_readline();
void	ft_init_table(t_table *t);


/*
** FT_DB_C
*/
int		ft_insert_record(int fd, t_person *data);
int		ft_get_record(int fd, t_person *data, int key);
int		ft_delete_record(int fd, int key);
int		ft_dbms(char *command, char **rec, t_table *t);

/*
** FT_INSERT_C
*/
void	ft_insert_handler(char **rec, t_table *t, int ac);

/*
** FT_PRINT_C
*/
void	ft_print_handler(char **rec, t_table *t);

/*
** FT_UPDATE_C
*/
void	ft_update_handler(char **rec, t_table *t);

/*
** FT_DELETE_C
*/
void	ft_delete_handler(char **rec, t_table *t);

/*
** FT_SAVE_C
*/
void	ft_save_handler(t_table *t);
int		ft_open_file(char *filename);
int		ft_open_file_update(char *filename);
void	ft_close_file(int fd);

#endif
