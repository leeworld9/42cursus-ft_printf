/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:57:34 by dohelee           #+#    #+#             */
/*   Updated: 2021/01/25 22:31:42 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	convert_addr(unsigned long long num, char *param)
{
	int j;

	j = 0;
	while (true)
	{
		if (num / 16 != 0)
		{
			param[j] = "0123456789abcdef"[num % 16];
			num = num / 16;
		}
		else
		{
			param[j] = "0123456789abcdef"[num];
			param[j + 1] = 'x';
			param[j + 2] = '0';
			param[j + 3] = '\0';
			break ;
		}
		j++;
	}
}

static char	*point_value_chk(t_printf *data)
{
	char	*param;

	if (data->void_p != NULL)
	{
		data->ull_param = (unsigned long long)data->void_p;
		if ((param = (char *)malloc(sizeof(void *) + 1)) == NULL)
			return (NULL);
		convert_addr(data->ull_param, param);
		reverse_arr(param);
	}
	else
		param = (data->prec == -1) ? "0x" : "0x0";
	return (param);
}

static int	show_result(t_printf *data)
{
	char	*param;
	char	*result;

	if (point_value_chk(data) == NULL)
		return (0);
	get_p_maxlen(data, ft_strlen(param));
	if ((result = (char *)malloc(sizeof(char) * (data->max_len + 1))) == NULL)
	{
		if (data->void_p != NULL)
			free(param);
		return (0);
	}
	result[data->max_len] = '\0';
	result = p_exception(data, result, param);
	ft_putstr_fd(result, 1);
	if (data->void_p != NULL)
		free(param);
	free(result);
	return (data->max_len);
}

int			ft_printf_p(va_list ap, char *target, int i)
{
	t_printf	*data;
	int			len;

	len = 0;
	if ((data = (t_printf *)malloc(sizeof(t_printf))) == NULL)
		return (0);
	data->tag = ft_substr(target, 1, i);
	data->flag = '\0';
	data->width = 0;
	data->prec = -1;
	data->minus = 0;
	get_flag(data);
	get_width(ap, data);
	get_prec(ap, data);
	data->void_p = va_arg(ap, void *);
	len += show_result(data);
	free(data->tag);
	free(data);
	return (len);
}
