/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:24:37 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/22 20:03:41 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_abs(long long n)
{
	return ((n < 0) ? -n : n);
}

static int			ft_nbrlen(long long n)
{
	int len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_ltoa(long long n)
{
	bool	sign;
	int		len;
	char	*result;

	sign = (n >= 0) ? true : false;
	len = ft_nbrlen(n);
	if ((result = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len] = ft_abs(n % 10) + '0';
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == false)
		result[0] = '-';
	return (result);
}
