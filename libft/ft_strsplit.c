/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 10:28:15 by apineda           #+#    #+#             */
/*   Updated: 2017/05/05 15:10:31 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	ft_whitespace(char const *s, char c, int i)
// {
// 	while (s[i] == c && s[i] != '\0')
// 		i++;
// 	return (i);
// }

// static int	ft_c(char const *s, char c, int i)
// {
// 	int		j;

// 	j = 1;
// 	while (s[i] != c && s[i] != '\0')
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// static int	ft_words(char const *s, char c, int i)
// {
// 	int		j;

// 	j = 1;
// 	while (s[i] != '\0')
// 	{
// 		while (s[i] != c && s[i] != '\0')
// 			i++;
// 		j++;
// 		i = ft_whitespace(s, c, i);
// 	}
// 	return (j);
// }

// char		**ft_strsplit(char const *s, char c)
// {
// 	char	**str;
// 	int		i[3];

// 	str = NULL;
// 	ft_bzero((void*)i, sizeof(int) * 3);
// 	if (s && c)
// 	{
// 		i[0] = ft_whitespace(s, c, i[0]);
// 		if ((str = (char **)ft_memalloc(sizeof(char*) * ft_words(s, c, i[0]))))
// 		{
// 			while (s[i[0]] != '\0')
// 			{
// 				i[1] = 0;
// 				str[i[2]] = (char *)ft_strnew(sizeof(char) * ft_c(s, c, i[0]));
// 				while (s[i[0]] != c && s[i[0]] != '\0')
// 					str[i[2]][i[1]++] = s[i[0]++];
// 				str[i[2]][i[1]] = '\0';
// 				i[2]++;
// 				i[0] = ft_whitespace(s, c, i[0]);
// 			}
// 			str[i[2]] = NULL;
// 		}
// 	}
// 	return (str);
// }

static int		ft_wrdcnt(char const *s, char c)
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

// static char	**ft_getwords(char const *s, char **words, char c)
// {
// 	int location;
// 	int wlen;
// 	int j;
// 	int l;
// 	char **ret;

// 	location = 0;
// 	j = 0;
// 	ret = words;
// 	while (j < ft_wrdcnt(s, c))
// 	{
// 		l = 0;
// 		location = ft_location(location, s, c);
// 		wlen = ft_wordlen(location, s, c);
// 		ret[j] = (char *)malloc(sizeof(char) * (wlen + 1));
// 		while (l < wlen)
// 			ret[j][l++] = s[location++];
// 		ret[j][l] = '\0';
// 		j++;
// 	}
// 	ret[j] = NULL;
// 	return (ret);
// }

static char	**ft_getwords(char const *s, char c, int len)
{
	int location;
	int wlen;
	int j;
	int l;
	char **ret;

	location = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * len);
	while (j < ft_wrdcnt(s, c))
	{
		l = 0;
		location = ft_location(location, s, c);
		wlen = ft_wordlen(location, s, c);
		ret[j] = (char *)malloc(sizeof(char) * (wlen + 1));
		while (l < wlen)
			ret[j][l++] = s[location++];
		ret[j][l] = '\0';
		j++;
	}
	ret[j] = NULL;
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;

	words = NULL;
	if (s && c)
		words = ft_getwords(s, c, (ft_wrdcnt(s, c) + 1));
		// words = (char **)malloc(sizeof(char *) * (ft_wrdcnt(s, c) + 1));
	// if (words)
	// 	words = ft_getwords(s, c, (ft_wrdcnt(s, c) + 1));
	return (words);
}

