/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_common_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:03:42 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/21 17:32:01 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_chr_idx(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if ((int)ft_strlen(str) == i)
		return (-1);
	return (i);
}

long long	abs_convert(long long num)
{
	return (num = (num > 0) ? num : -num);
}
