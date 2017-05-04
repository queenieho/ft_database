/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_col.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 23:04:40 by qho               #+#    #+#             */
/*   Updated: 2017/05/03 18:32:51 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_empty_col(t_table *t)
{
	printf("finding empty col\n");
	int		i;

	i = 0;
	while (i < COL_SIZE && t->col_id[i])
		i++;
	return (i);
}

int		ft_col_id_gen()
{
	// printf("gen col id\n");
	g_col_id += 1;
	return(g_col_id);
}

void	ft_insert_column(t_table *t, char type, char *name)
{
	printf("inserting column\n");
	int			idx;
	t_column	*col;

	idx = ft_empty_col(t);
	t->col_id[idx] = ft_col_id_gen();
	printf("%d\n", t->col_id[idx]);
	col = &(t->columns[idx]);
	col->type = type;
	col->name = name;
	col->name_len = strlen(col->name);
	col->max_len = col->name_len;
	printf("assigned col: %d.  ID: %d.  Address: %p\n", idx, t->col_id[idx], col);
	printf("\ncol has a max len of %d\n\n", col->max_len);
	printf("col type: - %c -, col name: %s, name len: %d\n", t->columns[idx].type, t->columns[idx].name, t->columns[idx].name_len);
	printf("col inserted?\n");

}

char	ft_get_datatype()
{
	char	type;

	printf("What kind of data will this store?\n");
	printf(" [s] string\n");
	printf(" [i] integer\n");
	printf(" [d] date\n");
	type = ft_readline()[0];
	return(type);
}
