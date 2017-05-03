/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 11:35:29 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 17:47:19 by qho              ###   ########.fr       */
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
	printf("gen col id\n");
	// printf("id: %d\n", *(g_col_id));
	g_col_id += 1;
	// printf("id gen: %d\n", *g_col_id);
	return(g_col_id);
}

void	ft_insert_column(t_table *t, char type, char *name)
{
	printf("inserting column\n");
	int			idx;
	t_column	*col;

	// col = mmap(NULL, sizeof(t_column), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	idx = ft_empty_col(t);
	t->col_id[idx] = ft_col_id_gen();
	printf("%d\n", t->col_id[idx]);
	col = &(t->columns[idx]);
	col->type = type;
	col->name = name;
	col->name_len = strlen(col->name);
	printf("assigned col: %d.  ID: %d.  Address: %p\n", idx, t->col_id[idx], col);
	printf("col type: - %c -, col name: %s, name len: %d\n", t->columns[idx].type, t->columns[idx].name, t->columns[idx].name_len);
	printf("col inserted?\n");

}

void	ft_insert_handler(char **rec, t_table *t, int ac)
{
	char	type;
	char	*col_name;
	// --insert c column_name data_type [-k: use for key generate] or 1st col gens key
	// content type: s.trings, i.nteger, b.oolean, d.ate
	// --insert r
	printf("insert handler\n");

	if (!rec[1])
		printf("print INSERT USAGE\n");

	if (rec[1][0] == 'c' && ac >= 4)
	{
		// printf("insert column\n");
		type = rec[3][0];
		col_name = rec[2];
		ft_insert_column(t, type, col_name);
	}
	else if (rec[1][0] == 'r')
	{
		printf("insert row\n");
		// ft_insert_record(t);
	}
}