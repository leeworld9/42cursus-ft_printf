/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 07:45:36 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/20 14:38:00 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void fill_chr(t_printf *data, int  i, char *result, char chr)
{
	int len;

	len = data->max_len;
	while (i > 0)
	{
		result[--len] = chr;
		i--;
	}
}

void fill_result(t_printf *data, char *result, char *param_abs)
{
	int i;
	int j;
	int len;

	len = data->max_len - 1;
	i = ft_strlen(param_abs);
	while (i > 0)
	{
		result[len--] = param_abs[i - 1];
		i--;
	}
	j = data->max_len - 1;
	while (j > 0 && data->minus == 1)
	{
		if (!ft_isdigit(result[j]))
		{
			result[j] = '-';
			break ;
		}
		j--;
	}
	if (data->minus == 1 && !ft_strchr(result, '-'))
		result[j] = '-';
}

int	find_chr_idx(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if ((int)ft_strlen(str) == i)
		return (-1);
	return (i);
}

long long abs_convert(long long num)
{
	return (num = (num > 0) ? num : -num);
}

void left_sort(char *result, int max_len)
{
	char *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (max_len + 1));
	tmp[max_len] = '\0';
	while (result[i] == ' ')
		i++;
	while (j + i != max_len)
	{
		tmp[j] = result[j + i];
		j++;
	}
	while (j != max_len)
	{
		tmp[j] = ' ';
		j++;
	}
	ft_strlcpy(result, tmp, max_len + 1);
	free(tmp);
}