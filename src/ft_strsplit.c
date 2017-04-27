/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:36:17 by qho               #+#    #+#             */
/*   Updated: 2017/04/26 18:41:05 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ft_wrdcnt(char const *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			cnt++;
		i++;
	}
	return (cnt);
}


static int	ft_location(int loc, char const *s, char c)
{
	int	i;

	i = loc;
	while (s[i])
	{
		if (s[i] != c)
		{
			loc = i;
			break ;
		}
		i++;
	}
	return (loc);
}

static int	ft_wordlen(int loc, char const *s, char c)
{
	int len;

	len = 0;
	while (s[loc])
	{
		if (s[loc] == c)
			break ;
		len++;
		loc++;
	}
	return (len);
}

static void	ft_getwords(char const *s, char **words, char c)
{
	int location;
	int wlen;
	int j;
	int l;

	location = 0;
	j = 0;
	while (j < ft_wrdcnt(s, c))
	{
		l = 0;
		location = ft_location(location, s, c);
		wlen = ft_wordlen(location, s, c);
		words[j] = (char *)malloc(sizeof(char) * (wlen + 1));
		while (l < wlen)
			words[j][l++] = s[location++];
		words[j][l] = '\0';
		j++;
	}
	words[j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;

	words = NULL;
	if (s && c)
		words = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1));
	if (words)
		ft_getwords(s, words, c);
	return (words);
}