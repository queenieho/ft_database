/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 17:54:38 by qho               #+#    #+#             */
/*   Updated: 2017/04/26 19:35:00 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
** FT_STRSPLIT
*/

// int		ft_wrdcnt(char const *s, char c)
// {
// 	int	cnt;
// 	int	i;

// 	cnt = 0;
// 	i = 0;
// 	while (s[i])
// 	{
// 		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
// 			cnt++;
// 		i++;
// 	}
// 	return (cnt);
// }


// static int	ft_location(int loc, char const *s, char c)
// {
// 	int	i;

// 	i = loc;
// 	while (s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			loc = i;
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (loc);
// }

// static int	ft_wordlen(int loc, char const *s, char c)
// {
// 	int len;

// 	len = 0;
// 	while (s[loc])
// 	{
// 		if (s[loc] == c)
// 			break ;
// 		len++;
// 		loc++;
// 	}
// 	return (len);
// }

// static void	ft_getwords(char const *s, char **words, char c)
// {
// 	int location;
// 	int wlen;
// 	int j;
// 	int l;

// 	location = 0;
// 	j = 0;
// 	while (j < ft_wrdcnt(s, c))
// 	{
// 		l = 0;
// 		location = ft_location(location, s, c);
// 		wlen = ft_wordlen(location, s, c);
// 		words[j] = (char *)malloc(sizeof(char) * (wlen + 1));
// 		while (l < wlen)
// 			words[j][l++] = s[location++];
// 		words[j][l] = '\0';
// 		j++;
// 	}
// 	words[j] = NULL;
// }

// char		**ft_strsplit(char const *s, char c)
// {
// 	char	**words;

// 	words = NULL;
// 	if (s && c)
// 		words = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1));
// 	if (words)
// 		ft_getwords(s, words, c);
// 	return (words);
// }


/*
** FT_FORK
*/

// int		ft_dbms(char *command, char **record)
// {
	
// 	return (1);
// }

int		ft_db_exe(char **av)
{
	pid_t	pid; 
	pid_t	wpid;
  	int		status;

	pid = fork();
	if (pid < 0)
		perror("sql"); // Error forking
	else if (pid == 0) // Child process
	{
		// printf("Child process\n");
		if (ft_dbms(av[0], av) == -1) 
			perror("lsh");
		exit(EXIT_FAILURE);
	}
	else	// Parent process
	{
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

char	*ft_readline()
{
	char	*line;
	size_t	bufsize;

	line = NULL;
	bufsize = 0;
	getline(&line, &bufsize, stdin);
	return (line);
}

int 	main()
{
	char	*line;
	char	**av;
	int		status;

	status = 1;
	line = NULL;
	while (status)
	{
		printf("My_DBMS - ");
		line = ft_readline();
		av = ft_strsplit(line, ' ');
		status = ft_db_exe(av);
		free(line);
		free(av);		
	}
	return (0);
}