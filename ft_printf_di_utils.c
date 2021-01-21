/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:03:22 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/21 18:53:02 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_maxlen(t_printf *data, int param_len)
{
	if (data->pres >= data->width)
		data->max_len = ((data->pres > param_len) ? data->pres : param_len);
	else
		data->max_len = ((data->width > param_len) ? data->width : param_len);
	if (data->pres == data->max_len || param_len == data->max_len)
		data->max_len += data->minus;
}

void	fill_chr(t_printf *data, int i, char *result, char chr)
{
	int len;

	len = data->max_len;
	while (i > 0)
	{
		result[--len] = chr;
		i--;
	}
}

void	fill_result(t_printf *data, char *result, char *param_abs)
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

void	left_sort(char *result, int max_len)
{
	char	*tmp;
	int		i;
	int		j;

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

char	*flag_bypass(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && ft_strchr(FT_FLAG, *(str + i)))
		i++;
	return (str + i);
}

int		zero_flagchk(va_list ap, t_printf *data)
{
	int	argument;

	if ((argument = va_arg(ap, int)) < 0)
		data->flag = '-';
	return ((int)abs_convert(argument));
}
