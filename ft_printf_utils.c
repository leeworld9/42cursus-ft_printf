/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:45:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/18 17:18:28 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void fill_chr(int max, int i, char *result, char chr)
{
	while (i > 0)
	{
		result[--max] = chr;
		i--;
	}
}

void fill_result(int max, int i, char *result, char *param)
{
	while (i > 0)
	{
		result[--max] = param[i-1];
		i--;
	}
}

int	find_chr_idx(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c)
		i++;
	if ((int)ft_strlen(str) == i)
		return (-1);
	return (i);
}

int abs_convert(int num)
{
	return (num = (num > 0) ? num : -num);
}