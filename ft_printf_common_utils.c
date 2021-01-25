/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_common_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:03:42 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 18:34:08 by dohelee          ###   ########.fr       */
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

void		fill_chr(t_printf *data, int i, char *result, char chr)
{
	int len;

	len = data->max_len;
	while (i > 0)
	{
		result[--len] = chr;
		i--;
	}
}

void		fill_result(t_printf *data, char *result, char *param)
{
	int i;
	int j;
	int len;

	len = data->max_len - 1;
	i = ft_strlen(param);
	while (i > 0)
	{
		result[len--] = param[i - 1];
		i--;
	}
	if (data->minus == 1)
	{
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
}

void		left_sort(char *result, int max_len)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((tmp = (char *)malloc(sizeof(char) * (max_len + 1))) == NULL)
		return ;
	tmp[max_len] = '\0';
	while (result[i] == ' ')
		i++;
	while (j + i != max_len)
	{
		tmp[j] = result[j + i];
		j++;
	}
	while (j != max_len)
		tmp[j++] = ' ';
	i = 0;
	while (i != max_len)
	{
		result[i] = tmp[i];
		i++;
	}
	free(tmp);
}
