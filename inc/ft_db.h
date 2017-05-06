/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 13:25:53 by qho               #+#    #+#             */
/*   Updated: 2017/05/05 20:12:48 by qho              ###   ########.fr       */
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

# define DASH "\033[31;1m=>\033[0m"

/*
** DEFINE DATA STRUCTS
*/
# define COL_SIZE 5
# define ROW_SIZE 5
# define FILENAME "data"
# define BACKUP_FILE "data.backup"

# ifndef ERRS
#  define ERR(a, b) while(1){if(a){return(b);}break;}
#  define ERR1(a, b, c) while(1){if(a){b;return(c);}break;}
# endif

int		g_col_id;
int		g_row_id;

typedef struct	s_content
{
	int			len;
	char		*data;
}				t_content;

typedef struct	s_column
{
	char		type;
	char		*name;
	int			name_len;
	int			max_len;
	t_content	*content_array;
}				t_column;

typedef struct	s_table
{
	int			col_id[COL_SIZE];
	int			row_id[ROW_SIZE];
	int			max_size;
	t_column	*columns;
}				t_table;

/*
** FT_DB_C
*/
int				ft_array_len(char **args);
void			ft_cleanup(t_table *t);
void			ft_exit(t_table *t);
int				ft_dbms(char *command, char **rec, t_table *t);

/*
** FT_DELETE_C
*/
int				ft_find_row(int r_id, t_table *t);
void			ft_delete_row(t_table *t);
void			ft_delete_column(t_table *t);
void			ft_delete_handler(char **rec, t_table *t);

/*
** FT_HELP_C
*/
void			ft_print_help_all(void);
void			ft_print_help_insert(void);
void			ft_print_help_print(void);
void			ft_print_help_update(void);
void			ft_print_help_delete(void);

/*
** MAIN_C
*/
char			*ft_readline(void);
void			ft_init_table(t_table *t);
void			ft_print_intro(void);

/*
** FT_INSERT_C
*/
void			ft_awkward_moment(char *str);
char			*ft_get_info(char *ask);
void			ft_insert_handler(char **rec, t_table *t);

/*
** FT_INSERT_COL_C
*/
int				ft_empty_col(t_table *t);
int				ft_col_id_gen(void);
void			ft_insert_new_data(t_column *col, int r_idx);
void			ft_insert_column(t_table *t, int num);
char			ft_get_datatype(void);

/*
** FT_INSERT_ROW_C
*/
int				ft_row_id_gen(void);
int				ft_empty_row(t_table *t);
void			ft_insert_row_data(t_column *col, int r_idx, int *max_size);
void			ft_insert_row(t_table *t, int num);

/*
** FT_LOAD_DB_C
*/
void			ft_load_column(char *header, t_table *t);
void			ft_get_columns(char *line, t_table *t);
void			ft_load_row_data(t_table *t, int r_idx, char *record,
									int c_idx);
int				ft_load_row(char *line, t_table *t);
void			ft_load_db(t_table *t);

/*
** FT_PRINT_ALL_C
*/
void			ft_print_data(int max_len, char *str);
void			ft_print_line(t_table *t);
void			ft_print_header(t_table *t);
void			ft_print_row(t_table *t, int row_idx);
void			ft_print_table(t_table *t);

/*
** FT_PRINT_HANDLER_C
*/
int				ft_search_header(t_table *t, char *find);
void			ft_print_filtered(t_table *t);
int				ft_find_last_row(t_table *t, int last_row);
void			ft_print_row_handler(char **rec, t_table *t);
void			ft_print_handler(char **rec, t_table *t);
int				ft_search_col(t_table *t, int row_idx, int col_idx, char *find);
int				ft_search_row(t_table *t, char *str, int col_idx);

/*
** FT_PRINT_S_C
*/
void			ft_print_sorted(t_table *t);
void			ft_sorter(t_table *t, int col_idx);
void			ft_gen_sort_array(t_table *t, int num, int **array);
void			ft_print_sort_table(t_table *t, int *sorted);
void			ft_print_selected(t_table *t, int num1, int num2);
void			ft_comp_rows(t_table *t, int col_idx, int **array,
						int asnd_dsnd);
void			ft_sort_type_asnd(t_table *t, int col_idx, int r_idx,
						int **array);
void			ft_sort_type_dsnd(t_table *t, int col_idx, int r_idx,
						int **array);
void			ft_sort_asnd_int(t_table *t, int r_idx, int col_idx,
						int **array);
void			ft_sort_asnd_str(t_table *t, int r_idx, int col_idx,
						int **array);
void			ft_sort_dsnd_int(t_table *t, int r_idx, int col_idx,
						int **array);
void			ft_sort_dsnd_str(t_table *t, int r_idx, int col_idx,
						int **array);
char			*ft_comp_cols(t_table *t, int row_id, int col_idx);
char			*ft_user_input_check(char *str);

/*
** FT_SAVE_C
*/
int				ft_open_file(char *filename);
void			ft_close_file(int fd);
void			ft_insert_type(char **header, char type);
char			*ft_gen_header(t_column col, int *len);
void			ft_save_col_header(int fd, t_column col);
char			*ft_init_row(t_content record);
char			*ft_append_to_row(char *str, t_content record);
char			*ft_gen_row(t_column *col, int r_idx, t_table *t);
void			ft_save_rows(int fd, t_table *t);
void			ft_save_handler(t_table *t);

/*
** FT_UPDATE_C
*/
int				ft_find_col_index(t_table *t, int col_id);
void			ft_update_maxlen(t_column *col, int new_len, int *max_size);
void			ft_update_record(t_table *t, int r_idx);
void			ft_update_row(t_table *t);
void			ft_update_column(t_table *t);
void			ft_update_handler(char **rec, t_table *t);

#endif
