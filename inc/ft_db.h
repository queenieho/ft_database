/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:53 by qho               #+#    #+#             */
/*   Updated: 2017/05/04 22:40:19 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DB_H
# define FT_DB_H

# include "../libft/libft.h"
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
	// int			key;	//hash key for rows?
	int			len;	//len of string stored
	// int			size;	//byte size of content? Not sure if needed.
	char		*data;	// content stored
}				t_content;

typedef struct s_column	// holds all the content in one column
{
	char		type;	// content type: s.trings, i.nteger, b.oolean, d.ate
	char		*name;	// column name
	int			name_len; // len of name
	int			even_odd;
	int			max_len;
	t_content	*content_array; // pointer to array of structs containing data
}				t_column;

typedef struct	s_table
{
	int			col_id[COL_SIZE];
	int			row_id[ROW_SIZE];
	int			max_size;
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
** FT_DB_C
*/
int		ft_array_len(char **args);
int		ft_dbms(char *command, char **rec, t_table *t);

/*
** FT_DELETE_C
*/
int		ft_find_row(int r_id, t_table *t);
void	ft_delete_row(t_table *t);
void	ft_delete_handler(char **rec, t_table *t);

/*
** FT_FORK_C
*/
int		ft_db_exe(char **av, t_table *table);
char	*ft_readline();
void	ft_init_table(t_table *t);

/*
** FT_INSERT_C
*/
char	*ft_get_info(char *ask);
void	ft_insert_handler(char **rec, t_table *t);

/*
** FT_INSERT_COL_C
*/
int		ft_empty_col(t_table *t);
int		ft_col_id_gen();
void	ft_insert_column(t_table *t, char type, char *name);
char	ft_get_datatype();

/*
** FT_INSERT_ROW_C
*/
int		ft_row_id_gen();
int		ft_empty_row(t_table *t);
void	ft_insert_row_data(t_column *col, int r_idx, int *max_size);
void	ft_insert_row(t_table *t);

/*
** FT_LOAD_DB_C
*/
void	ft_load_column(char	*header, t_table *t);
void	ft_get_columns(char *line, t_table *t);

void	ft_load_row_data(t_table *t, int r_idx, char *record, int c_idx);
// void	ft_load_row_data(t_column *col, int r_idx, char *record, int *max_size);
void	ft_load_row(char *line, t_table *t);
void	ft_load_db(t_table *t);

/*
** FT_PRINT_C
*/
static	int		ft_max_len(t_table *t);
void	ft_print_row(t_table *t, int row_idx);
void	ft_print_data(int max_len, char *str);
void	ft_print_line(t_table *t);
void	ft_print_header(t_table *t);
void	ft_print_table(t_table *t);
void	ft_print_handler(char **rec, t_table *t);
void	ft_print_filtered(t_table *t);
void	ft_print_selected(t_table *t, int num1, int num2);
/*
** FT_SAVE_C
*/
int		ft_open_file(char *filename);
void	ft_close_file(int fd);
void	ft_insert_type(char **header, char type);
char	*ft_gen_header(t_column col, int *len);
void	ft_save_col_header(int fd, t_column col);
char	*ft_init_row(t_content record);
char	*ft_append_to_row(char *str, t_content record);
char	*ft_gen_row(t_column *col, int r_idx);
void	ft_save_rows(int fd, t_table *t);
void	ft_save_handler(t_table *t);

/*
** FT_STRSPLIT_C
*/
// char		**ft_strsplit(char const *s, char c);

/*
** FT_UPDATE_C
*/
int		ft_find_col_index(t_table *t, int col_id);
void	ft_update_maxlen(t_column *col, int new_len, int *max_size);
void	ft_update_record(t_table *t, int r_idx);
void	ft_update_row(t_table *t);
void	ft_update_handler(char **rec, t_table *t);

/*
** FT_UTILS_C
*/
// unsigned int	ft_absolute_val(int n);
// int				ft_numlen(int n);
// char			*ft_itoa(int n);

#endif
