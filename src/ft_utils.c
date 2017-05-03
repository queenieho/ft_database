/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:04:43 by qho               #+#    #+#             */
/*   Updated: 2017/05/02 23:08:16 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

unsigned int	ft_absolute_val(int n)
{
	if (n < 0)
		n = (unsigned int)-n;
	return ((unsigned int)n);
}

int	ft_numlen(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n == -2147483648)
		len = 11;
	if (n < 0 && n > -2147483648)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char			*num;
	unsigned int	tmp;
	int				len;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (ft_numlen(n) + 1));
	if (num)
	{
		num[len--] = '\0';
		if (n == 0)
			num[0] = '0';
		if (n < 0)
			num[0] = '-';
		tmp = ft_absolute_val(n);
		while (len + 1 && tmp)
		{
			num[len] = (tmp % 10) + '0';
			tmp = tmp / 10;
			len--;
		}
	}
	return (num);
}
